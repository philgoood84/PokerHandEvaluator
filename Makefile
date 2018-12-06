CC=gcc
INCLUDE=./include
CFLAGS+=-Ofast

all: five seven

five: test/five.o libpheval5.a test/kev/libkev.a
	${CC} ${CFLAGS} $^ -o $@

six: test/six.o libpheval6.a test/kev/libkev.a
	${CC} ${CFLAGS} $^ -o $@

seven: test/seven.o libpheval7.a test/kev/libkev.a
	${CC} ${CFLAGS} $^ -o $@

libpheval5.a: src/evaluator5.o src/hash.o src/hashtable.o src/hashtable5.o src/dptables.o
	mkdir -p dist
	ar rcs $@ $^

libpheval6.a: src/evaluator6.o src/hash.o src/hashtable.o src/hashtable6.o src/dptables.o
	mkdir -p dist
	ar rcs $@ $^

libpheval7.a: src/evaluator7.o src/hash.o src/hashtable.o src/hashtable7.o src/dptables.o
	mkdir -p dist
	ar rcs $@ $^

test/kev/libkev.a: test/kev/fast_eval.o test/kev/kev_eval.o
	ar rcs $@ $^

%.o: %.c
	${CC} -c ${CFLAGS} -I${INCLUDE} $< -o $@

clean:
	rm -f src/*.o test/*.o test/kev/*.o test/kev/*.a *.o *.a five six seven

