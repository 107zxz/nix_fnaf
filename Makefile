SOURCES=$(wildcard src/*.c)

main: $(SOURCES) main.c
	clang -Wall -lraylib main.c $(SOURCES) -o main

run: main
	./main

install:
	mkdir -p ${out}/bin
	cp main ${out}/bin/main


run_tests: run_t_generation

t_generation: $(SOURCES) test/t_generation.c
	clang -Wall -lraylib test/t_generation.c $(SOURCES) -o t_generation
run_t_generation: t_generation
	./t_generation