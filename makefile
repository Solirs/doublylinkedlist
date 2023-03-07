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
	-rm libdoublylinkedlist.a
	-rm libdoublylinkedlist.o
	-rm doublylinkedlist
	-rm valgrind-*
valgrind:
	make build
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./doublylinkedlist
