r.exe : readFile.o dicionario.o
	gcc -o r.exe readFile.o dicionario.o

readFile.o : readFile.c dicionario.h
	gcc -c readFile.c

dicionario.o : dicionario.c dicionario.h
	gcc -c dicionario.c
