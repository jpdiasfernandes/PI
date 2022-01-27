stack.exe : prog.o stack.o
	gcc -o stack.exe prog.o stack.o

prog.o : prog.c stack.h
	gcc -c prog.c

stack.o : stack.c stack.h
	gcc -c stack.c