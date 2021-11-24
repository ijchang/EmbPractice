run.exe: main_2.o
	gcc -o run.exe main_2.o
main_560.o: main_2.c
	gcc -std=gnu99 -pedantic -Wall -c main_2.c
.PHONY: clean
clean:
	rm -f run.exe *.o
