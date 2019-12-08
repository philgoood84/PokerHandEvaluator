CC=gcc
CXX=g++
TOPDIR=..
INCLUDE=${TOPDIR}/include
SRC=${TOPDIR}/src
CFLAGS+=-std=c99
CXXFLAG+=-std=c++11

all: c_example cpp_example

c_example: c_example.c libpheval.a
	${CC} ${CFLAGS} -I${INCLUDE} $^ -o $@

cpp_example: cpp_example.cc libpheval.a
	${CXX} ${CFLAGS} ${CXXFLAG} -I${INCLUDE} $^ -o $@

libpheval.a: ${SRC}/evaluator5.o ${SRC}/hashtable5.o \
             ${SRC}/evaluator6.o ${SRC}/hashtable6.o \
             ${SRC}/evaluator7.o ${SRC}/hashtable7.o \
             ${SRC}/hash.o ${SRC}/hashtable.o ${SRC}/dptables.o ${SRC}/evaluator.o \
             ${SRC}/rank.o ${SRC}/7462.o
	ar rcs $@ $^

%.o: %.cc
	${CXX} -c ${CXXFLAG} -I${INCLUDE} $< -o $@

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -rf *.o c_example cpp_example
