all:
	g++ -Isrc/include -Iinclude/headers -Lsrc/lib -o main runFile/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf 
