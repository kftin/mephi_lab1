
CC = cc

CFLAGS = -std=c11 -lreadline -g

all:main

main:main.o f_lab1_manipul.o f_lab1_check.o f_lab1_in.o test.o
	$(CC) $(CFLAGS) main.o f_lab1_manipul.o f_lab1_check.o f_lab1_in.o test.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

f_lab1_manipul.o: f_lab1_manipul.c
	$(CC) $(CFLAGS) -c f_lab1_manipul.c

f_lab1_check.o: f_lab1_check.c
	$(CC) $(CFLAGS) -c f_lab1_check.c

f_lab1_in.o: f_lab1_in.c
	$(CC) $(CFLAGS) -c f_lab1_in.c

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -rf *.o main

