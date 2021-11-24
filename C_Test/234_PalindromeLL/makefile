run.exe: main_234.o
	gcc -o run.exe main_234.o
main_560.o: main_234.c
	gcc -std=gnu99 -pedantic -Wall -c main_234.c
.PHONY: clean
clean:
	rm -f run.exe *.o
