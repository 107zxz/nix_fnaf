main: src/main.c
	clang -Wall -lraylib src/main.c -o main

run: main
	./main

install:
	mkdir -p ${out}/bin
	cp main ${out}/bin/main
