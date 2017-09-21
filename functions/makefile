GCC = gcc -c
COMP = gcc -o
main: main.o functions.o
	${COMP} main main.o functions.o
main.o: main.c functions.h
	${GCC} main.c
functions.o: functions.c functions.h
	${GCC} functions.c
