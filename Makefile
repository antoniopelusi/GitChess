all:
	@if [ ! -d "bin" ]; \
		then  \
			@echo "|> Creating /bin directory"; \
			@mkdir bin; \
	fi

	@echo "|> Building: Linux x64"
	@gcc -Ofast src/** -o bin/GitChess

	@echo "|> Building: Windows x64"
	@x86_64-w64-mingw32-gcc -Ofast src/** -o bin/GitChess.exe

debug_linux_x64:
	@if [ ! -d "bin" ]; \
		then  \
			@echo "|> Creating /bin directory"; \
			@mkdir bin; \
	fi

	@echo "|> Building: Linux x64"
	@gcc src/** -o bin/GitChessDebug

debug_windows_x64:
	@if [ ! -d "bin" ]; \
		then  \
			@echo "|> Creating /bin directory"; \
			@mkdir bin; \
	fi

	@echo "|> Building: Windows x64"
	@x86_64-w64-mingw32-gcc src/** -o bin/GitChessDebug.exe

clean:
	@echo "|> Cleaning /bin "
	@rm -rf bin/*