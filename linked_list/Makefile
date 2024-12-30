CC = clang
CFLAGS = -Wall -g -fsanitize=address

all: linked_list

linked_list: linked_list.o test.o
	$(CC) $(CFLAGS) -o linked_list linked_list.o test.o

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

run:
	clear
	./linked_list

clean:
	rm *.o
	rm linked_list
