#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <SDL2/SDL.h>

struct SDL_Text{
    //nessacerry attributes
    const char* text;
    int size;
    int width;
    int length;
    int x;
    int y;
    SDL_Color color;
    const char* f;
    
    //auto
    SDL_Rect rect = {x,y,width,length};
    SDL_Surface* surfaceText = NULL;
    
    //optional background
    bool background;
    SDL_Color bgcolor;
    bool fill;
    
    //optional background image
    bool bgImage;
    const char* file;
    SDL_Surface* BMP;
    //optional rect for background
    SDL_Rect bgrect = {};
    
    //functions
    bool init();
    bool draw(SDL_Renderer* renderer);
    void TextGetError();
    
    //for error handling
    bool didInit;
    bool didText;
};

bool SDL_Text::init(){
    if(TTF_Init() == -1){return false;}
    TTF_Font* font = TTF_OpenFont(f, size);
    if (!font){return false;}
    surfaceText = TTF_RenderText_Solid(font, text, color);   
    if (!surfaceText){return false;}
    if(bgImage){BMP = SDL_LoadBMP(file);if(!BMP){return false;}}
    didInit = true;
    return true;
}

bool SDL_Text::draw(SDL_Renderer* renderer){
    didText = true;
    if(!bgrect.y+bgrect.x+bgrect.w+bgrect.h){bgrect = rect;}
    SDL_Texture* Text = SDL_CreateTextureFromSurface(renderer, surfaceText);
    if (!Text){return false;}
    if(bgImage){SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,BMP); if (!texture){return false;}
    if(SDL_RenderCopy(renderer,texture,NULL,&bgrect) == -1){return false;}}
    if (background){SDL_SetRenderDrawColor(renderer,bgcolor.r,bgcolor.g,bgcolor.b,bgcolor.a);SDL_RenderDrawRect(renderer,&bgrect);if(fill){SDL_RenderFillRect(renderer,&bgrect);}}
    if(SDL_RenderCopy(renderer, Text, NULL, &rect) == -1){return false;}
    return true;
}

void SDL_Text::TextGetError(){
    if (didText && !didInit){std::cout << "SDL_text error: You need to init your text with .init()" << std::endl;;}
    else if (!size){std::cout << "SDL_text error: You're missing your .size" << std::endl;}
    else if (!width || !length){std::cout << "SDL_text error: You're missing your .width or .length" << std::endl;}
    else if (!f){std::cout << "SDL_text error: You're missing your .f" << std::endl;}
    
    else{
        std::cout << "SDL2 error: " << std::endl << std::endl << SDL_GetError() << std::endl << "TTF error: " << std::endl << std::endl << std::endl << TTF_GetError() << std::endl;
    }
}

int main(){
    return 0;
}