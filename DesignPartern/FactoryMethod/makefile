CC = clang++
RM = rm -rf
CXXFLAG = --std=c++11

all:main.o
	$(CC) -o main main.o 
main.o:main.cc ConcreteProduct.h ConcreteFactory.h
	$(CC) -c main.cc $(CXXFLAG)
clean:
	$(RM) main *.o *.gch
