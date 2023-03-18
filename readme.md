*"In the beginning was the Word, and the Word was with God, and the Word was God." John 1:1*

# Abstract
In the world of software, we face an unresolved issue: the absence of a universal compositional unit or building block that would make it ten times easier, or even more, to connect software systems and express problems in a language that resembles human speech. We require a definitive term to bring about a software revolution. Today, We have made significant progress in this endeavor and have created a perfect loop with actionable words and sentences.

Actionable word is essential unit of composition which will give us ability to program machines without knowing how to code. it has ability to split programming in two pars. programming by actionable words which is task any human can do. and making actionable words will be task for more experianced programers who knows how to code i.e. programm in machine/programming languages.

Just like human language actionable words has concept of rotation around words core.

In actionable sentences execution is flowing like current in wiers. and we can controll of swiching directions and direct execution flow from left to right and from right to left and from top to bottom and from bottom to top. power actionable words give us is to have ability to compose execution flow in a way we wish and that is scalable and distributable across globe. in software any problem can be solved thrue indirection acrionable words composing with each other thrue indirect connection.

Actionable word is a new building block so it is a new thing and to help to think about it we can give several analogy. lets take for example cell from botany. we can think of it like a building block. unit of composition in celural dimension. in cell we have other kind of building block, like proteins, which are in turn constucted from more smpler bulding blocks like molecules etc. so to compare acionable word is a cell like thing and C functions/lamdas are more like molecules and proteins in cells. 

We will describe protocol of actionable word and show the way how to build more powerfull unit of compositions.

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
