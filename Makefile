CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu17 -Wall
sshow.out: sshow.c text_index.o aradani.o
	${CC} $^ -o $@ ${CFLAGS} -lm -lraylib
root.out: root.c map_file.o
awords:
	node parse.js awords.tab
p.out: p.c json.o
%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
ram.ram:
	dd status=progress bs=2048 if=/dev/zero of=ram.ram count=2048
clean:
	rm -f *.bin *.o *.out
.PHONY: clean run
