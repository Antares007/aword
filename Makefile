CC|=gcc
CFLAGS+=-std=gnu17 -Wall -Wno-array-bounds

aword.out: aword.c gut.o
	${CC}    $^ -o $@ ${CFLAGS} -lraylib -lm
%.out: %.c
	${CC}    $^ -o $@ ${CFLAGS} -luv
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
%.bin: %.asm
	nasm -f bin $^ -o $@
clean:
	rm -f **/*.o **/*.out *.o *.out
.PHONY: clean
