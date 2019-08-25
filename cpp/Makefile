CC=gcc
CXX=g++
INCLUDE=./include
CFLAGS+=-Ofast
CXXFLAGS+=-Ofast -std=c++14

all: five six seven

five: test/five.o libpheval.a test/kev/libkev.a
	${CXX} ${CXXFLAGS} $^ -o $@

six: test/six.o libpheval.a test/kev/libkev.a
	${CXX} ${CXXFLAGS} $^ -o $@

seven: test/seven.o libpheval.a test/kev/libkev.a
	${CXX} ${CXXFLAGS} $^ -o $@

libpheval.a: src/evaluator5.o src/evaluator6.o src/evaluator7.o \
  			 src/hashtable5.o src/hashtable6.o src/hashtable7.o \
  			 src/hash.o src/hashtable.o src/dptables.o
	ar rcs $@ $^

test/kev/libkev.a: test/kev/fast_eval.o test/kev/kev_eval.o
	ar rcs $@ $^

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

%.o: %.cc
	${CXX} -c ${CXXFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -f src/*.o test/*.o test/kev/*.o test/kev/*.a *.o *.a five six seven

