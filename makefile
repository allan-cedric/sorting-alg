CC=gcc
CFLAGS=-Wall -Wextra -lm

EXEC=evaluate_sorting
OBJ=sorting.o evaluate_sorting.o

all: evaluate_sorting clean

evaluate_sorting: $(OBJ)

evaluate_sorting.o: evaluate_sorting.c sorting.h
sorting.o: sorting.c sorting.h

clean:
	-rm -f $(OBJ) *~

purge: clean
	-rm -f $(EXEC) 
	
