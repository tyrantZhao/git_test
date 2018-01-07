CC = clang++
OBJS = main.o stack.o
CXXFLAGS = --std=c++11

.PHONY : main clean
main : $(OBJS)
	$(CC) -o main $(OBJS)
main.o : main.cc stack.h
	$(CC) -c main.cc $(CXXFLAGS)
stack.o : stack.cc stack.h
	$(CC) -c stack.cc $(CXXFLAGS)
clean:
	rm main *.o
