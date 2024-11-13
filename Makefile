main: main.c
	clang -Wall -lraylib main.c -o main

run: main
	./main

install:
	mkdir -p ${out}/bin
	cp main ${out}/bin/main