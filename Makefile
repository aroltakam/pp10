program: Aufgabe_2_main.o libstatistics.a
		gcc Aufgabe_2_main.o -L. -lstatistics -lm -o program

libstatistics.a: statistics.o
		ar rcs libstatistics.a statistics.o

statistics.o: statistics.c statistics.h
		gcc -c statistics.c -o statistics.o

Aufgabe_2_main.o: Aufgabe_2_main.c statistics.h
		gcc -c Aufgabe_2_main.c -o Aufgabe_2_main.o

clean:
		rm -f *.o *.a program

