
TARGET = main.exe
OBJ = main.o question1.o question2.o question3.o
SOURCE = main.cpp question1.cpp question2.cpp question3.cpp

$(TARGET): $(OBJ)
	g++ $(OBJ) -o $(TARGET)

main.o: main.cpp question1.h question2.h question3.h
	g++ -c main.cpp
question1.o: question1.cpp question1.h
	g++ -c question1.cpp
question2.o: question2.cpp question3.h
	g++ -c question2.cpp
question3.o: question3.cpp question3.h
	g++ -c question3.cpp

clean:
	-rm *.o *.exe