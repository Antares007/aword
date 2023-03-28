CC|=gcc
CFLAGS+=-std=gnu17 -Wall

src/sshow.out: src/sshow.c src/aword.o src/aradani.o src/text_index.o
	${CC}    $^ -o $@ ${CFLAGS} -lraylib -lm
%.out: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.o *.out
.PHONY: clean
