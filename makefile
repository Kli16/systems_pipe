all: pipe.c
	gcc -o pipe pipe.c

run: all
	./pipe

clean:
	rm pipe
	rm *.o
	rm *~
