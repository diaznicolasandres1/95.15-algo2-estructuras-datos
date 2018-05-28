EXEC = pruebas
CC = gcc
CFILES = tail.c lista.h lista.c
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes

build: $(CFILES)
	$(CC) $(CFLAGS) $(CFILES) -o pruebas

run: build
	./pruebas

valgrind: build
	valgrind $(VFLAGS) cat archivo  | ./pruebas 3

clean:
	rm -f *.0 pruebas


