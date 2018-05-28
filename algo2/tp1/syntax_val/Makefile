EXEC = pruebas
CC = gcc
CFILES = pila.h pila.c syntax_val.c strutil.c strutil.h
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

build: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o pruebas

run: build
	./pruebas

valgrind: build
	valgrind $(VFLAGS)  cat archivo1.txt | ./pruebas 


clean:
	rm -f *.0 pruebas


