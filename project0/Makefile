CPP = g++
CFLAGS = -Wall -Wno-unused-function -std=c++11
PROGRAMS = test

all: $(PROGRAMS)

test: test_set.cpp
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROGRAMS) *.o *.a a.out *.err *~