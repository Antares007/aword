/*
sentence_member
  {parse_name}.                        // write Tword
  terminal.                            // write terminal
  action.                              // write terminal

sentence_members
  sentence_member.
  sentence_members space sentence_member.

sentence
  sentence_members dot.

name_defining_paragraph
  sentence.
  name_defining_paragraph space sentence.

name_defining_paragraphs
  name_defining_paragraph new_line.
  name_defining_paragraphs name_defining_paragraph new_line.

name
  {}.

new_line
  '\n'.                                   // align

most_abstract_definition
  name new_line name_defining_paragraphs.

*/

void beginning() {}
void showit() {}
void op() {}
void parse_name() {}
void parse_new_line() {}
void parse_char() {}

void run(void **o, long s);

#pragma GCC diagnostic ignored "-Wint-conversion"
// clang-format off
int main() {
  void*o[1024];
  long s = 0;
#define os(a,b) o[s++] = a, o[s++] = b,

  os(1, beginning) os(2, "most_abstract_definition") os(3, showit)

  os(4, "most_abstract_definition") os(3, op)
  os(2, "name") os(2, "new_line") os(2, "name_defining_paragraphs") os(5, op) os(3, op)

  os(4, "name") os(3, op)
  os(6, parse_name) os(5, op) os(3, op)

  os(4, "new_line") os(3, op)
  os(6, parse_new_line) os(5, op) os(3, op)

  os(4, "name_defining_paragraphs") os(3, op)
  os(2, "name_defining_paragraph") os(2, "new_line") os(5, op) os(3, op)
  os(2, "name_defining_paragraphs") os(2, "name_defining_paragraph")os(2, "new_line") os(5, op) os(3, op)

  os(4, "name_defining_paragraph") os(3, op)
  os(2, "sentence") os(5, op) os(3, op)
  os(2, "name_defining_paragraph")os(2, "space")os(2, "sentence") os(5, op) os(3, op)

  os(4, "sentence") os(3, op)
  os(2, "sentence_members") os(2, "dot") os(5, op) os(3, op)

  os(4, "sentence_members") os(3, op)
  os(2, "sentence_member")  os(2, "new_line") os(5, op) os(3, op)
  os(2, "sentence_members") os(2, "space") os(2, "sentence_member") os(5, op) os(3, op)

  os(4, "sentence_member") os(3, op)
  os(6, parse_name) os(5, op) os(3, op)
  os(6, parse_char) os(5, op) os(3, op)

  run(o, s);
}

