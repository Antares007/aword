#pragma GCC diagnostic ignored "-Wint-conversion"
#define N(argo)                                                                \
  void argo(long *ο, long β, long α, long τ, long σ, long ρ, long δ)
#define aContext ο, β, α, τ, σ, ρ, δ
typedef N((*n_t));
#include <stdio.h>
N(goTo    ) { τ += 11 * δ, ((n_t)ο[τ])(aContext); }
N(tab     ) { τ = ο[β++], goTo(aContext); }

N(call_a  ) {            τ = ο[τ + 10], goTo(aContext); }
N(call_b  ) {            τ = ο[τ - 10], goTo(aContext); }
N(call_o  ) { ο[--β] = τ, τ = ο[τ + δ], goTo(aContext); }
N(call    ) {
  ο[ο[τ + 1]  = σ] = call_a,                                                      σ += 11;
  ο[            σ] = call_o,  ο[σ - 1] = τ + ο[τ - 5], ο[σ + 1] = τ + ο[τ + 5],   σ += 11;
  ο[ο[τ - 1]  = σ] = call_b,                                                      σ += 11;
  ((n_t)(ο[τ] = call_o))(aContext);
}
N(print ) { printf("%s", (char *)ο[τ + 5]), goTo(aContext); }
N(dot   ) { δ = -δ, goTo(aContext); }
N(beginning) { if (ρ < 2) ρ = 3, goTo(aContext); }

N(twist) {}
N(halt) {}
int main() {
  long β = 1024;
  long ο[β * 5] = {};
  long α = 0;
  long τ = β;
  long σ = τ;
  long ρ = 3;
  long δ = 1;

  ο[σ] = beginning,                                                   σ += 11;
  ο[σ] = call,        ο[σ - 5] =  9 * 11,       ο[σ + 5] =  5 * 11,   σ += 11;
  ο[σ] = call,        ο[σ - 5] = 12 * 11,       ο[σ + 5] =  8 * 11,   σ += 11;
  ο[σ] = call,        ο[σ - 5] = 15 * 11,       ο[σ + 5] = 11 * 11,   σ += 11;
  ο[σ] = print,                                 ο[σ + 5] = ".",       σ += 11;
  ο[σ] = dot,                                                         σ += 11;
  ο[σ] = tab,                                                         σ += 11;
  ο[σ] = print,       ο[σ + 5] = "actionable",                        σ += 11;
  ο[σ] = dot,                                                         σ += 11;
  ο[σ] = print,       ο[σ + 5] = "ACTIONABLE",                        σ += 11;
  ο[σ] = tab,                                                         σ += 11;
  ο[σ] = print,       ο[σ + 5] = "-",                                 σ += 11;
  ο[σ] = dot,                                                         σ += 11;
  ο[σ] = print,       ο[σ + 5] = "+",                                 σ += 11;
  ο[σ] = tab,                                                         σ += 11;
  ο[σ] = print,       ο[σ + 5] = "word",                              σ += 11;
  ο[σ] = dot,                                                         σ += 11;
  ο[σ] = call,        ο[σ - 5] = 5*11,          ο[σ + 5] = 1*11,      σ += 11;
  ο[σ] = tab,                                                         σ += 11;
  ο[σ] = print,       ο[σ + 5] = "aword",                             σ += 11;
  ο[σ] = dot,                                                         σ += 11;
  ο[σ] = print,       ο[σ + 5] = "AWORD",                             σ += 11;
  ο[σ] = tab,                                                         σ += 11;

  goTo(aContext);

  return 0;
}
/*
  Perfect cycle
  What does it means to cycle in epoll?


    / -
  -   -
    \ -



how we can write sentences with call back part.
it must be on top of epoll.
so our sentence must have predicate to check epoll events and callback part.
we need super simple example.
i really need to focus.
we need to combine twist with epoll and multitasking!
we need to find the way!
we need to twist!


example:

let's write sample epoll subscribe:

In this context, what does inheritance mean, and how do we implement
polymorphism?

Inheritance operates from the bottom up. We start with a base, called goTo,
and then build instructions on top of it.
It can be compared to a living tree. Initially, a tree has pith and bark.
Over time, the tree adds new layers between the bark and the pith.
Each new layer becomes the pith for the next year's growth,
and this process continues in yearly cycles.
We can understand inheritance by looking at how a tree grows new branches.
The tree develops its pith, and eventually, it may branch out.
When a branch forms, its initial pith is inherited from the main trunk of the
tree.

Here is the real difference. We don't have a class definition as a blueprint. We
don't have a blueprint at all. The definition and its instantiation have the
same structure. We use actionable text to define and actionable text to
instantiate. So, we need to more precisely explain what this means. We need to
define the machinery to explain how it is possible. We have a definition in
actionable text. How can we visualize the growth of the text? The key is the
point of branching. At that point, we possibly already have a grown pith, and we
are branching. What does branching mean? I have an idea of the abstract
definition. It is a form to define a new word. Basically, it means to write the
name of the new word and on the next line write one or more actionable
sentences. These sentences may execute one after another, or they may represent
productions in terms of language theory. This whole idea of actionable text
needs to be focused on growth. This means we need to create an interpreter. An
interpreter that can grow itself. This means it can interpret a string and, as a
result, produce a recursively enumerable set of new abstract definitions in
actionable text form. This is the only way it can grow. It will consume a string
to output a new layer of abstract definitions in the form of actionable text.

Now, let's be more concrete. We already stated how to write the abstract
definition of a new word. Now, let's talk about what it means to output it in
the form of actionable text. The first definition in actionable text will be the
one that defines how to parse and output a string, defining definitions in
actionable text form. So, actionable text is a group of actionable words. Which
words can we use to define an abstract definition? We need to make it in a super
simple form. We can use the word call to state the start of a new branch, or we
can align with Georgian language syntax rules. Let's follow the language.
According to Georgian language syntax rules,
a sentence is a group of sentence members followed by a member that represents a
dot. After the header, i.e., after the name of the new word, we don't write a
dot. We continue writing on a new line. Note: The header can be a group of
sentence members representing several words, i.e., a fragment of the sentence.
After the header, we write paragraphs. Each paragraph must start with
tabulation, and the sentences in the paragraph follow each other. We can
symplify it.

We need interpreter.
We need fucking interpreter.
We will feeeed in string and it will output actionable text.
When we will feed in more string it will use all actionable text including
outputs to output more actionable text. In oter words roots of the tree are
growing crown and crown are growing roots and it is in constant cycles.

Ok thats sounds interesting and nothing more.
We need to describe concrete machienary.
All we have is sentence members layed out in one dimension.
Additionaly we can have perpendicular dimension where we can grow pith.
While parsing we can do it.
Grow dimension of name to define them.
Well let's state that each branch originates accordint to tis definint
actionable sentence. So while we are on the trunk and it defines branching pont.
We will copy whalle definition ad a grown brunch.
I.E. we will instansiate it.

Our definition in actionable text form must include sentence members which will
support twist. Hey please remember this it is all about twist. So we need to
somehow write it. So there is the problem we need to formulate it and solve it.
Twist
In wich color we will start twist?
Ok here is the problem:
We can have actionable sentence in which two members of the sentence referencing
same aword. The aword is defined by actionable text.


We are in sentence which may be already copyed from its
definition or it may be sentence defined from beginning.
we can idetify that we are going in member of
the sentence first time. next member references same defining sentece.
we will have no proble if we copy defining sentence while we are in firs member
which references it. and mutate that member so next time we will use copyed,
instastiated version.

How do we define a class and instantiate it?

We have elevated CPU. i.e. we have defined CPU in terms of its own language.
now we need to add missing functionality.
what is missing? we need to find the way to define new computational model?




*/
