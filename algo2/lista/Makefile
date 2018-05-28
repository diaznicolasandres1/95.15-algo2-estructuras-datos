EXEC = pruebas
CC = gcc
CFILES = testing.c testing.h lista.c lista.h pila.c pila.h pruebas_alumno.c main.c
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

build: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o pruebas

run: build
	./pruebas

valgrind: build
	valgrind $(VFLAGS) ./pruebas

clean:
	rm -f *.0 pruebas


