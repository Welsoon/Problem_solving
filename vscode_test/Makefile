

main: main.o file.o
	g++ -g main.o file.o -o main
	-rm *.o

main.o: main.cpp file.h
	g++ -c -g main.cpp -o main.o

file.o: file.cpp file.h
	g++ -c -g file.cpp -o file.o

clean:
	-rm *.o main