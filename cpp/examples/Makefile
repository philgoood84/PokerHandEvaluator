CC=gcc
CXX=g++
TOPDIR=..
INCLUDE=${TOPDIR}/include
SRC=${TOPDIR}/src
CXXFLAG+=-std=c++11

all: example1 example2

example1: example1.o libpheval.a
	${CC} ${CFLAGS} $^ -o $@

example2: example2.cc libpheval.a
	${CXX} ${CFLAGS} ${CXXFLAG} -I${INCLUDE} $^ -o $@

libpheval.a: ${SRC}/evaluator5.o ${SRC}/evaluator6.o ${SRC}/evaluator7.o \
             ${SRC}/hashtable5.o ${SRC}/hashtable6.o ${SRC}/hashtable7.o \
             ${SRC}/hash.o ${SRC}/hashtable.o ${SRC}/dptables.o
	ar rcs $@ $^

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -rf *.o example1 example2
