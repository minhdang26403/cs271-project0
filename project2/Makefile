CPP = g++
CFLAGS = -Wall -Wno-unused-function -std=c++11
PROGRAMS = test usecase

all: $(PROGRAMS)

test: test_minqueue.cpp
	$(CPP) $(CFLAGS) -o $@ $^

usecase: main.cpp
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROGRAMS) *.o *.a a.out *.err *~