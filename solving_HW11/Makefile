src1 = Question_1
src2 = Question_2
src3 = Question_3

main: main.o ${src1}.o ${src2}.o ${src3}.o
	g++ -g main.o ${src1}.o ${src2}.o ${src3}.o -o main
	-rm *.o

main.o: main.cpp ${src1}.h ${src2}.h ${src3}.h
	g++ -c -g main.cpp -o main.o

${src1}.o: ${src1}.cpp ${src1}.h
	g++ -c -g ${src1}.cpp -o ${src1}.o

${src2}.o: ${src2}.cpp ${src2}.h
	g++ -c -g ${src2}.cpp -o ${src2}.o

${src3}.o: ${src3}.cpp ${src3}.h
	g++ -c -g ${src3}.cpp -o ${src3}.o

clean:
	-rm *.o main