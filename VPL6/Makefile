all: out

out: main.o aluno.o
	g++ -o out ./main.o ./aluno.o

main.o: main.cpp aluno.hpp
	g++ -I include -c ./main.cpp -o ./main.o

aluno.o: ./aluno.cpp ./aluno.hpp
	g++ -I include -c ./aluno.cpp -o ./aluno.o 


