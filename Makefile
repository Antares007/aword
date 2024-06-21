CC|=clang
CFLAGS+=-std=c2x -Wall
%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.o *.out
.PHONY: clean
