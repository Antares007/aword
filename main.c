const char *empty_tree = "4b825dc642cb6eb9a060e54bf8d69288fbee4904";
void *load_tree(const char *hash);
int compile_tree(const char *hash);
#include <stdio.h>
#include <unistd.h>
void (*tree)(void **, long);
void GreenCB(void **o, long a) {
  printf("%s\n", __FUNCTION__), (tree - 16 * 4)(o, a);
}
void PurpleCB(void **o, long a) {
  printf("%s\n", __FUNCTION__), (tree - 16 * 4)(o, a);
}
typedef void (*t_t)(void**, long);
int main(int argc, char **argv) {
  void *o[1024];
  long a = 0;
  tree = load_tree(argv[1]); printf("tree %s loaded at:%p\n", argv[1], tree);
  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = load_tree;
  o[a++] = PurpleCB;
  o[a++] = GreenCB;
  (tree - 16 * 5)(o, a);
  return 0;
}
