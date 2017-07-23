markov:markov.o eprintf.o
	gcc markov.o eprintf.o -o markov
eprintf.o:eprintf.c eprintf.h
	gcc -c eprintf.c -o eprintf.o
markov.o:markov.c eprintf.h
	gcc -c markov.c -o markov.o

