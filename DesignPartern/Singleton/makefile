CC = clang++
RM = rm -rf
CXXFLAG = --std=c++11
OBJS = main.o singleton.o

all:$(OBJS)
	$(CC) -o main $(OBJS)
main.o:main.cc singleton.h
	$(CC) -c main.cc $(CXXFLAG)
singleton.o:singleton.h singleton.cc
	$(CC) -c singleton.cc $(CXXFLAG)
clean:
	$(RM) main *.o *.gch
