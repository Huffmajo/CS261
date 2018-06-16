C = gcc
CFLAGS = -Wall -lm -std=c99

default: prog

main.o: main.c
	${C} ${CFLAGS} -c main.c

prog: main.o
	${C} ${CFLAGS} -o prog main.o

clean:
	rm *.o

cleanall: clean
	rm prog

