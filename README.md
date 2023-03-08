# WIP

A free (as in freedom) implementation of a 
heterogenous doubly linked list in C, which means it can contain different data types (i.e strings, ints).  
It can be built as a static object with `make object` and linked to any program you want including doublylinkedlist.h.  
It is not by any mean secure or mature, and still lacks some functions, use with caution.  
Valgrind reports no memory leaks when correctly using the implementation (see main.c and run `make valgrind`).  
