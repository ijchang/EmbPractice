run.exe: main_250.o
	gcc -o run.exe main_250.o
main_560.o: main_250.c
	gcc -std=gnu99 -pedantic -Wall -c main_250.c
.PHONY: clean
clean:
	rm -f run.exe *.o
