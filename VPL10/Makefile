all: out

out: main.o HeapInt.o
	g++ -o out ./main.o ./HeapInt.o

main.o: main.cpp HeapInt.hpp
	g++ -I include -c ./main.cpp -o ./main.o

HeapInt.o: ./HeapInt.cpp ./HeapInt.hpp
	g++ -I include -c ./HeapInt.cpp -o ./HeapInt.o 

