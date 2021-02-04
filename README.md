# SDL_text
A wrapper for SDL_ttf so you can render text faster with fewer lines.



# How to Build 
  **To build the library**
  run the command "make buildLib"

  **To build the example** 
  run the command "make buildExample"
  
 
# How to use SDL_Text (*nessacerry* attributes)
  First you'll need to create your text with **SDL_Text text {};**
    
  the SDL_Text struct has 8 attributes you need to include
    
  std::string text - the text you want to display
    
  int width and int length  - your text's width and length 
    
  int x and int y - your text's  x and y
    
  SDL_Color - your text's color (More info about SDL_Color @ https://wiki.libsdl.org/SDL_Color)
    
  and, std::string font - your text's font
    
  a simple example of this is 

    SDL_Text text3 = {"Text3",50,50,50,300,300,{255,0,0,0},"Roboto-Regular.ttf"};
    
# How to use SDL_Text (*optional* attributes)
  
  **Rect**
  
  bool background - toggles background (auto false) (rect only)
  
  SDL_Color bgcolor - your text's background color (rect only) (More info about SDL_Color @ https://wiki.libsdl.org/SDL_Color)
  
  bool fill - toggles if you want to fill your background rect or not
  
  bgrect - optional rect for your background if you want to make it difer from your text's rect (auto your text's rect) (both Rect and Image)
  
  **Image**
  
  bool bgImage - toggles background (auto false) (image only)
  
  const char* file - the file of your background's image
  
  bgrect - optional rect for your background if you want to make it difer from your text's rect (auto your text's rect) (both Rect and Image)
  

# SDL_Tect functions
  bool init() - function to initialise yor SDL_Text object (Your code will not work if you don't include this) returns true if it worked and false if there was in error
  
  bool draw(SDL_Renderer* renderer) - draws your text/background on the SDL renderer
  
  void GetError() - outputs any SDL/SDL_TTF/SDL_text errors in the terminal 

  **Simple Error Handling**
    if (!text.init()){text.TextGetError}
    or
    if (!text.draw(renderer)){text.TextGetError}
    
