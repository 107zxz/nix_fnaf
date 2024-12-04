SOURCES=$(wildcard **/*.c)

main: $(SOURCES)
	clang -Wall -lraylib $(SOURCES) -o main

run: main
	./main

install:
	mkdir -p ${out}/bin
	cp main ${out}/bin/main
