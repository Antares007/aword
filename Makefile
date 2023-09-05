CC|=clang
LD=ld -melf_x86_64
CFLAGS+=-std=gnu17 -Wall
run: root.out ram.ram awords
	./root.out
root.out: root.c map_file.o
awords: parse.js awords.tab
	node $^
hash.out: hash.c
	${CC} $^ -o $@ ${CFLAGS} -lssl -lcrypto
%.out: %.c
	${CC} $^ -o $@ ${CFLAGS}
%.o: %.c
	${CC} -c $^ -o $@ ${CFLAGS}
ram.ram:
	dd status=progress bs=2048 if=/dev/zero of=ram.ram count=2048
clean:
	rm -f *.bin *.o *.out
.PHONY: clean run
