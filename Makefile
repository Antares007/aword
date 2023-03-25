CC|=gcc
CFLAGS+=-std=gnu17 -Wall

show.out: show.c shiva.o aradani.o gut.o
	${CC}    $^ -o $@ ${CFLAGS} -lraylib -lm
aword.out: aword.c gut.o
	${CC}    $^ -o $@ ${CFLAGS} -lraylib -lm
%.out: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.o *.out
.PHONY: clean
