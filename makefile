all: compile run

compile:
	mkdir -p ./bin  
	gcc -I ./include/ -c ./src/jval.c -o ./bin/jval.o
	gcc -I ./include/ -c ./src/jrb.c -o ./bin/jrb.o
	gcc -I ./include/ -c ./src/fields.c -o ./bin/fields.o
	gcc -I ./include/ -c ./src/dllist.c -o ./bin/dllist.o
	gcc -I ./include/ -c ./src/main.c -o ./bin/main.o
	gcc -I ./include/ ./bin/jval.o ./bin/jrb.o ./bin/fields.o ./bin/dllist.o ./bin/main.o -o ./bin/main

run:
	./bin/main giris/giris.dat

clean:
	rm -rf ./bin
