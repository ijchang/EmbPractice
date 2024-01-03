run.exe: main.o mySource.o
	gcc -o run.exe main.o mySource.o
main.o: main.c
	gcc -std=gnu99 -pedantic -Wall -c main.c
mySource.o: mySource.c
	gcc -std=gnu99 -pedantic -Wall -c mySource.c
.PHONY: clean
clean:
	rm -f run.exe *.o
