CPP = g++
CFLAGS = -Wall -Wno-unused-function -std=c++11
PROGRAMS = test_set_example

all: $(PROGRAMS)

test_set_example: test_set_example.cpp
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(PROGRAMS) *.o *.a a.out *.err *~