all:
	gcc -Ofast src/** -o bin/GitChess
	x86_64-w64-mingw32-gcc -Ofast src/** -o bin/GitChess.exe

debug:
	gcc src/** -o bin/GitChessDebug
	x86_64-w64-mingw32-gcc src/** -o bin/GitChessDebug.exe