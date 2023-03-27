CC|=gcc
CFLAGS+=-std=gnu17 -Wall

show.out: show.c shiva.o aradani.o text_index.o
	${CC}    $^ -o $@ ${CFLAGS} -lraylib -lm
%.out: %.c sword.o
	${CC}    $^ -o $@ ${CFLAGS} -luv
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.o *.out
.PHONY: clean
