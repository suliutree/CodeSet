observer:observer.o subject.o main.o
	g++ observer.o subject.o main.o -o observer
observer.o:observer.cpp observer.h
	g++ -c observer.cpp -o observer.o
subject.o:subject.cpp observer.h subject.h
	g++ -c subject.cpp -o subject.o
main.o:main.cpp observer.h subject.h
	g++ -c main.cpp -o main.o
