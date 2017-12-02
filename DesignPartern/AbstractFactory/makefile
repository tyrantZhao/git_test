CC = clang++
RM = rm -rf
CXXFLAG = --std=c++11
OBJS = main.o AbstractFactory.o
all:$(OBJS)
	$(CC) -o main $(OBJS)
main.o:main.cc AbstractFactory.h ConcreteProduct.h
	$(CC) -c main.cc $(CXXFLAG)
AbstractFactory.o:AbstractFactory.cc AbstractFactory.h
	$(CC) -c AbstractFactory.cc $(CXXFLAG)
clean:
	$(RM) main *.o *.gch
