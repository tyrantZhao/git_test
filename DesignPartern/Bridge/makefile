CC = clang++
RM = rm -rf
CXXFLAG = --std=c++11
OBJS = main.o
all:$(OBJS)
	$(CC) -o main $(OBJS) $(CXXFLAG)
main.o:main.cc concrete.h concreteimpl.h
	$(CC) -c main.cc $(CXXFLAG)
clean:
	$(RM) main *.o *.gch
