run.exe: main_430.o
	gcc -o run.exe main_430.o
main.o: main_430.c
	gcc -std=gnu99 -pedantic -Wall -c main_430.c
.PHONY: clean
clean:
	rm -f run.exe *.o
