CC|=clang
CFLAGS+=-std=gnu17 -Wall
%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.bin *.o *.out
.PHONY: clean
