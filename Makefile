LIBFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
all:
	g++ -std=c++17 -c SDL_Utils.cpp $(LIBFLAGS)
	g++ -std=c++17 -c texture.cpp $(LIBFLAGS)
	g++ -std=c++17 -c dot.cpp $(LIBFLAGS)
	g++ -std=c++17 -c main.cpp $(LIBFLAGS)

	g++ -std=c++17 SDL_Utils.o texture.o dot.o main.o -o main $(LIBFLAGS)
run:
	chmod +x main
	./main
clean:
	rm -rf *.o 