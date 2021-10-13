run.exe: main.o
	#gcc -std=gnu99 -pedantic -Wall -O2 -o run.exe main.o
	gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.o
main.o: main.c
	#gcc -std=gnu99 -pedantic -Wall -O2 -c main.c
	#gcc -std=gnu99 -pedantic -Wall -O2 -c main.c
	gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -c main.c
.PHONY: clean
clean:
	rm -f run.exe *.o
