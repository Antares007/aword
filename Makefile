CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu17 -Wall
run: main.out awords
	cp main.out abin && cd abin && ulimit -s unlimited && ./main.out
awords: parse.js awords.tab
	node $^
local.out: local.c
	${CC} $^ -o $@ ${CFLAGS} -lraylib -lm
main.out: main.c text_index.o
	${CC} $^ -o $@ ${CFLAGS} -lraylib -lm
light.out: light.c light_text_index.o
	${CC} $^ -o $@ ${CFLAGS} -lraylib -lm
%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.bin *.o *.out
.PHONY: clean run
