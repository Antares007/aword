CC|=clang
CFLAGS+=-std=gnu17 -Wall

BookSources := $(wildcard bo_*.c)
BookObjects := $(patsubst %.c,%.o,$(BookSources))

main.out: main.c text_index.o
	${CC} ${CFLAGS} -lraylib -lm $^ -o $@

sophis2.out: sophis2.c sophis2_text_index.o $(BookObjects)
	${CC} ${CFLAGS} -lraylib -lm $^ -o $@
sophis.out: sophis.c sophis_text_index.o
	${CC} ${CFLAGS} -lraylib -lm $^ -o $@
%.out: %.c
	${CC} ${CFLAGS} $^ -o $@
%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@
clean:
	rm -f *.o *.out
.PHONY: clean run
