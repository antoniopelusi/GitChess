.SILENT: debug_linux_x64
.SILENT: debug_windows_x64
.SILENT: linux_x64
.SILENT: windows_x64
.SILENT: clean

all: clean debug_linux_x64 debug_windows_x64 linux_x64 windows_x64

debug_linux_x64:
	if [ ! -d "bin" ]; \
		then \
				echo "|> Creating /bin directory"; \
				mkdir bin; \
	fi

	echo "|> Building: Debug Linux x64"
	gcc src/** -o bin/GitChessDebug

debug_windows_x64:
	if [ ! -d "bin" ]; \
		then \
				echo "|> Creating /bin directory"; \
				mkdir bin; \
	fi

	echo "|> Building: Debug Windows x64"
	x86_64-w64-mingw32-gcc src/** -o bin/GitChessDebug.exe

linux_x64:
	if [ ! -d "bin" ]; \
		then \
				echo "|> Creating /bin directory"; \
				mkdir bin; \
	fi

	echo "|> Building: Linux x64"
	gcc -Ofast src/** -o bin/GitChess

windows_x64:
	if [ ! -d "bin" ]; \
		then \
				echo "|> Creating /bin directory"; \
				mkdir bin; \
	fi

	echo "|> Building: Windows x64"
	x86_64-w64-mingw32-gcc -Ofast src/** -o bin/GitChess.exe

clean:
	echo "|> Cleaning /bin "
	rm -rf bin/*