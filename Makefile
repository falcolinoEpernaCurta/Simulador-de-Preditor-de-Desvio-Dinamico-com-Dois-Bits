all: 2bitcounter

2bitcounter: main.c
	gcc -Wall  main.c -lncurses -o 2bitcounter

clean:
	-rm -f *.o *~

purge: clean
	-rm -f ncounter
