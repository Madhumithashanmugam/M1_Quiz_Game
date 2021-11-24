CC= gcc

CFLAGS=-c -Wall

all: quiz

quiz: quiz.o functions.o
	$(CC) quiz.o functions.o -o quiz

quiz.o: quiz.c
	$(CC) $(CFLAGS) quiz.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

clean: 
	rm -rf *.o quiz