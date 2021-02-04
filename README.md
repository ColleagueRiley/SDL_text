# SDL_text
A wrapper for SDL_ttf so you can render text faster with fewer lines.



# How to Build 
  **To build the library**
  run the command "make buildLib"

  **To build the example** 
  run the command "make buildExample"
  
 
# How to use SDL_Text (attributes)
    First you'll need to create your text with **SDL_Text text {};**
    
    the SDL_Text struct has 8 attributes you need to include
    
    std::string text - the text you want to display
    
    int width and int length  - your text's width and length 
    
    int x and int y - your text's  x and y
    
    SDL_Color - your text's color (More info about SDL_Color @ https://wiki.libsdl.org/SDL_Color)
    
    and, std::string font - your text's font
    
    a simple example of this is 

    SDL_Text text3 = {"Text3",50,50,50,300,300,{255,0,0,0},"Roboto-Regular.ttf"};
    
