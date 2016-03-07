CC=gcc

all: five seven

five: hash.o dptables.o hashtable5.o evaluator5.o five.o
	${CC} ${CFLAGS} $^ -o $@

seven: hash.o dptables.o hashtable7.o evaluator7.o seven.o
	${CC} ${CFLAGS} $^ -o $@

hashtable7.o:
ifneq ("$(wildcard hashtable7.c)","")
	${CC} -c -O0 hashtable7.c -o $@
else
	tar xzf hashtable7.tar.gz; ${CC} -c -O0 hashtable7.c -o $@
endif

%.o: %.c
	${CC} -c ${CFLAGS} $< -o $@

clean:
ifneq ("$(wildcard hashtable7.o)","")
	mv hashtable7.o .backup7; rm -f *.o five seven; mv .backup7 hashtable7.o
else
	rm -f *.o five seven
endif
