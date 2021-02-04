#include <SDL2/SDL.h>
#include "SDL_text.hpp"

bool running = true;
SDL_Event e;
const Uint8* keys = SDL_GetKeyboardState(NULL);


SDL_Text text = {"Text",50,50,50,100,100,{255,0,0,0},"Roboto-Regular.ttf", .background = true,.bgcolor ={0,255,0,0}, .fill = true};
SDL_Text text2 = {"Text2",50,50,50,200,200,{255,0,0,0},"Roboto-Regular.ttf", .background = true,.bgcolor ={0,255,0,0}};
SDL_Text text3 = {"Text3",50,50,50,300,300,{255,0,0,0},"Roboto-Regular.ttf"};
SDL_Text text4 = {"Text4",50,50,50,400,400,{255,0,0,0},"Roboto-Regular.ttf", .bgImage = true, .file = "images/button.bmp"};


int main(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    
    if(!text.init()){TextGetError();}if(!text2.init()){TextGetError();}if(!text3.init()){TextGetError();}if(!text4.init()){TextGetError();}
    
    SDL_Window* window = SDL_CreateWindow("Example",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    while (running){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                running = false;
            }
            
            if (keys[SDL_SCANCODE_ESCAPE]){
                running = false;
            }
        }
        SDL_RenderClear(renderer);
        if(!text.draw(renderer)){TextGetError();}
        if(!text2.draw(renderer)){TextGetError();}
        if(!text3.draw(renderer)){TextGetError();}
        if(!text4.draw(renderer)){TextGetError();}
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderPresent(renderer);
    }
    void SDL_Quit();
}