LIBRARIES = -lSDL2 -lSDL2_mixer 

buildLib: 
	@echo "Building Library"; \
	if [ -d "$(BUILD)" ]; then \
		echo ""; \
    else \
        mkdir build; \
		cd build; \
		mkdir lib; \
		mkdir include; \
		cd ..; \
	fi
	
	gcc -shared source/SDL_text.cpp -o build/lib/libSDL_text.so -fPIC -lSDL2 -lSDL2_ttf

	cp SDL_text.hpp build/include

buildExample:
	@echo "Building Example"; \
	
	g++ example.cpp -o example.out -lSDL2 -lSDL2_ttf