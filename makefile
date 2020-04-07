CC=gcc
CFLAGS=-ansi -Wall -lm

EXEC=testa_ordenacao
OBJ=sorting.o testa_ordenacao.o

all: testa_ordenacao clean

testa_ordenacao: $(OBJ)
	$(CC) $(OBJ) -o testa_ordenacao $(CFLAGS) 

testa_ordenacao.o: testa_ordenacao.c sorting.h
	$(CC) -c testa_ordenacao.c $(CFLAGS)

sorting.o: sorting.c sorting.h
	$(CC) -c sorting.c $(CFLAGS)

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC) 
	
