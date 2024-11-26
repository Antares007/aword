CC|=clang
CFLAGS+=-std=gnu17 -Wall

BookSources := $(wildcard books/*.c)
BookObjects := $(patsubst %.c,%.o,$(BookSources))
ProgramSources := $(wildcard programs/*.c)
ProgramObjects := $(patsubst %.c,%.o,$(ProgramSources))

sophis.out: sophis.c text_index.o ${BookObjects} ${ProgramObjects}
	${CC} ${CFLAGS} -lraylib -lm $^ -o $@

%.out: %.c
	${CC} ${CFLAGS} $^ -o $@
%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@
clean:
	rm -f **/*.o **/*.out *.o *.out
.PHONY: clean run
