all:
	gcc -Ofast src/main.c src/bitmanipulation.c -o bin/GitChess
	x86_64-w64-mingw32-gcc -Ofast src/main.c src/bitmanipulation.c -o bin/GitChess.exe

debug:
	gcc src/** -o bin/GitChessDebug
	x86_64-w64-mingw32-gcc src/** -o bin/GitChessDebug.exe