abin.exe : abinDemo.o abin.o
	gcc -o abin.exe abinDemo.o abin.o

abinDemo.o : abinDemo.c abin.h
	gcc -c abinDemo.c

abin.o : abin.c abin.h
	gcc -c abin.c