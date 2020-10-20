run.exe: main.o
	gcc -o run.exe main.o
main.o: main.c
	gcc -std=gnu99 -pedantic -Wall -c main.c
.PHONY: clean
clean:
	rm -f run.exe *.o
