build:
	make object
	gcc main.c libdoublylinkedlist.a -Wall -Wextra -o doublylinkedlist


run:
	make build
	./doublylinkedlist

object:
	gcc -c doublylinkedlist.c -Wall -Wextra -o libdoublylinkedlist.o
	ar rcs libdoublylinkedlist.a libdoublylinkedlist.o

clean:
	rm libdoublylinkedlist.a
	rm libdoublylinkedlist.o
	rm doublylinkedlist