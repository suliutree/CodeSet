virtualspeed:autotimer.o myclass.o main.o
	g++ autotimer.o myclass.o main.o -o virtualspeed
autotimer.o:autotimer.cpp autotimer.h
	g++ -c autotimer.cpp -o autotimer.o
myclass.o:myclass.cpp myclass.h
	g++ -c myclass.cpp -o myclass.o
main.o:main.cpp autotimer.h myclass.h
	g++ -c main.cpp -o main.o
