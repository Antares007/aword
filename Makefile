CC|=clang
CFLAGS+=-std=gnu17 -Wall

sophis.out: sophis.c ani.o text_index.o
	${CC} ${CFLAGS} -lraylib -lm $^ -o $@

%.out: %.c
	${CC} ${CFLAGS} $^ -o $@
%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@
clean:
	rm -f **/*.o **/*.out *.o *.out *.dot.png *.dot
.PHONY: clean run
