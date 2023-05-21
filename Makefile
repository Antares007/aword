CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu17 -Wall
root.out: root.c map_file.o
p.out: p.c json.o
%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
clean:
	rm -f *.bin *.o *.out
.PHONY: clean run
