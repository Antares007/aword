*"In the beginning was the Word, and the Word was with God, and the Word was God." John 1:1*

# Abstract
In the realm of software, we face a persistent issue: the lack of a universal compositional unit or building block that would significantly simplify the process of connecting software systems and expressing problems in a language that resembles human speech. What we require is a definitive term that can bring about a revolution in software development. Fortunately, we have made significant progress in this endeavor and have created a perfect loop with actionable words and sentences.

 actionable word is the unit of composition which does not require call stack. The power of actionable words is the ability to compose execution flow in a way that is scalable, distributable, and tailored to our needs. In software, any problem can be solved through indirection, where actionable words are composed with each other through indirect connections. 
Actionable word is the unit of composition which can resolve memory managment problems.

An actinable words will make posible to do things which was immposible to do in straitforward and simple way.  actionable sentences is the weay to concuirior time related problmens in software.
Just like human language, actionable words have a concept of rotation around the word's core. In actionable sentences, execution flows like a AC current in wires, in both directions, and we can control the direction of execution flow. 

An actionable word is an essential unit of composition that enables us to program machines without knowing how to code. It has the ability to split programming into two parts: programming by actionable words, which any human can do, and making actionable words, which requires more experienced programmers who know how to code in machine/programming languages.

An actionable word is a new building block, so it is a new concept. To better understand it, we can draw analogies to other building blocks. For example, we can compare it to a cell in botany, which is a unit of composition in the cellular dimension. In a cell, we have other building blocks, such as proteins, which are constructed from simpler building blocks like molecules. Similarly, actionable words are like cells, and C functions/lambda functions are more like molecules and proteins in cells.

We will describe the protocol of actionable words and show how to build more powerful units of composition.

# Actionable word
Actionable word is defined in terms of actionable sentence and actionable sentence includes defionition of actionable word. just like in human language sentence is groupe of words which contains idea followed by dot. actionable word is four sided thing.
```
 ...|      left aword      |     current aword    |     right aword      |...
    |                      |                      |                      |
    |back |pointer of|front|back |pointer of|front|back |pointer of|front|
    |value|narrative |value|value|narrative |value|value|narrative |value|
``` 
Each actionable word is represented by three pointers in contigous space in memory. in center we have pointer to "narrative" and from bouth sides of "narrative" we have space of machine word width to hold values. they are essential to compose with other actinable sentences with help of junction actionable words like "not", "and" and "or". alsow, they can be used in narratives texts to persist data in any way wish.

# Actionable sentece
Actionable sentence is a group of actinable words started by actionable word "b" - stands for begin, and folowed by actionable word "o" - stands for dot.

to work with actionable sentences and contigous memory spaces more comfortably we have defined special structure ```struct text_t;```. it is one machine word in lenght and gives us ability to access values as predefined types without casting them in standard way.

``` c
typedef struct text_t {
  union {
    void *v; long q; const char *cs; struct text_t *t;
    void (*c)(long α, struct τext *ω, struct τext *ο, long ρ, long δ, long σ);
  };
} text_t;
void show() {
  text_t*text;
  text[0].q = 7;          // access as value of type "long" 
  text[1].c(0,0,0,0,0,0); // access as narrative. note narrative is defined below.
  text[2].t = text;       // access as value of text_t pointer e.i.
                          // recursive type pointer.
  // etc...
}
```

# Narrative
Narrative is C language function with fixed 6 parameters plus body text of the function. so it is defined by tuple of 7 virables.

Becous we have fixed parameters we need to have them in any narrative we will define.
Here is macro "N", which will help us easily definine narratives.
``` c
#define N(argo) void argo(long α, struct τext *ω, struct τext *ο, long ρ, long δ, long σ)
```
For fixed parameter we have chousen greek letters to represent them. when we will be working towards defining narratives body, greek letters will help us to not make collisions to local virables.

now we will show simplest actionable words narrative, which is doing nothing i.e. it is like an "id" function.
lest describe how execution is folwing. in narratives body we are jumping to next or previous actionable words narrative. depending of value of δ, represents direction of executins flow, which can be either 1 or -1. jumping expression below may become ```ω[3].c(α, ω+3, ο, ρ, 1, σ); or ```ω[-3].c(α, ω-3, ο, ρ, -1, σ);```
``` c
// Note, we dont using calling convention which includes return semantics and call stack.
N(m) { ω[3*δ].c(α, ω+3*δ, ο, ρ, δ, σ); }
```
we are passing arguments and defining free virables. for now lest define "X" macro to hide calling expression.

Here simlest one actionable words sentence sample code:
``` c
#define X ω[3*δ].c(α, ω+3*δ, ο, ρ, δ, σ)
N(b) { ρ = (ρ + 1) % 4; δ =  1; X; }
N(m) {                          X; }
N(o) {                  δ = -1; X; }
void show() {
  text_t text[] = {
    {.q = 0}, {.c = b}, {.q = 0},
    {.q = 0}, {.c = m}, {.q = 0},
    {.q = 0}, {.c = o}, {.q = 0}};
  long α = 0;
  text_t*ω = text + 1;
  text_t ο[512];
  long ρ = 0, δ = 1, σ = sizeof(ο) / sizeof(*ο);
  X;
}
```
remember actionable word "b" begins and "o" will end sentence. when execution flow will goes to  our actionable sentence "b m o" it will loop. exutution will start from word after "b", in our case from "m" then it will go to next actionable words narrative, which is "o". "o" will turen executuion flow in reverse direction by setting δ to -1. mombmombmombmombmomb... forever and we have notion of rays which is represented by "ρ" - roe. we shell discuss how we are using rays in compose logical and syntactical connections between actionable words and sentences.


narrative in center of actionable word can have conections to one,in case of "b" and "o", upto four actionable words represented by left aword, back value, right aword and front value.
