CC|=clang
CFLAGS+=-std=c2x -Wall

sophis.out: sophis.c sophis_text_index.o
	${CC} $^ -o $@ -lraylib -lm  ${CFLAGS}
sophis_text_index.out: sophis_text_index.c sophis.o
	${CC} $^ -o $@ -lraylib -lm  ${CFLAGS}
%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.o *.out
.PHONY: clean run
