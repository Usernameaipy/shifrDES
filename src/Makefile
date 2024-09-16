CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -pedantic
BUILDDIR=../build/

all : des

des : des_shifr.o dynamic.o input.o des_block.o matrix.o des_IP_FP.o
	$(CC) $(CFLAGS) des_shifr.o dynamic.o input.o des_block.o matrix.o des_IP_FP.o -o $(BUILDDIR)des

des_shifr.o : des_shifr/des_shifr.c des_shifr/des_shifr.h
	$(CC) $(CFLAGS) -c des_shifr/des_shifr.c -o des_shifr.o

dynamic.o : input/dynamic.c input/dynamic.h
	$(CC) $(CFLAGS) -c input/dynamic.c -o dynamic.o

input.o : input/input.c input/input.h
	$(CC) $(CFLAGS) -c input/input.c -o input.o

des_block.o : des_shifr/des_block.c des_shifr/des_block.h
	$(CC) $(CFLAGS) -c des_shifr/des_block.c -o des_block.o

matrix.o : matrix/matrix.c matrix/matrix.h
	$(CC) $(CFLAGS) -c matrix/matrix.c -o matrix.o

des_IP_FP.o : des_shifr/des_IP_FP.c des_shifr/des_IP_FP.h
	$(CC) $(CFLAGS) -c des_shifr/des_IP_FP.c -o des_IP_FP.o

clean :
	rm -rf *.o
	rm -rf $(BUILDDIR)*

rebuild : clean all