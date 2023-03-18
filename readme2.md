*"In the beginning was the Word, and the Word was with God, and the Word was God." John 1:1*

# Abstract
In the realm of software, we face a persistent issue: the lack of a universal compositional unit or building block that would significantly simplify the process of connecting software systems and expressing problems in a language that resembles human speech. What we require is a definitive term that can bring about a revolution in software development. Fortunately, we have made significant progress in this endeavor and have created a perfect loop with actionable words and sentences.

An actionable word is an essential unit of composition that enables us to program machines without knowing how to code. It has the ability to split programming into two parts: programming by actionable words, which any human can do, and making actionable words, which requires more experienced programmers who know how to code in machine/programming languages.

Just like human language, actionable words have a concept of rotation around the word's core. In actionable sentences, execution flows like a current in wires, and we can control the direction of execution flow from left to right, right to left, top to bottom, and bottom to top. The power of actionable words is the ability to compose execution flow in a way that is scalable, distributable, and tailored to our needs. In software, any problem can be solved through indirection, where actionable words are composed with each other through indirect connections.

An actionable word is a new building block, so it is a new concept. To better understand it, we can draw analogies to other building blocks. For example, we can compare it to a cell in botany, which is a unit of composition in the cellular dimension. In a cell, we have other building blocks, such as proteins, which are constructed from simpler building blocks like molecules. Similarly, actionable words are like cells, and C functions/lambda functions are more like molecules and proteins in cells.

We will describe the protocol of actionable words and show how to build more powerful units of composition.

# Junction words
Junction words are actionable words that are used to combine multiple actionable sentences together. The most common junction words are "and", "or", and "not". Junction words take one or more actionable sentences as input and return an actionable sentence as output.

The "and" junction word takes two actionable sentences as input and returns a new actionable sentence that will only return true if both input sentences return true. Here is an example of an "and" junction word in code:
``` c
N(and) {
  if (δ == 1) {
    // Forward execution
    ω[3].c(α, ω+3, ο, ρ, δ, σ);
    if (!ω[3].q) {
      // The first sentence was false
      ω[0].q = 0;
      ω[6].c(α, ω+6, ο, ρ, δ, σ);
    }
  } else {
    // Reverse execution
    ω[-3].c(α, ω-3, ο, ρ, δ, σ);
    if (!ω[-3].q) {
      // The second sentence was false
      ω[0].q = 0;
      ω[-9].c(α, ω-9, ο, ρ, δ, σ);
    }
  }
}
```

The "or" junction word takes two actionable sentences as input and returns a new actionable sentence that will return true if either of the input sentences return true. Here is an example of an "or" junction word in code:

``` c
N(or) {
  if (δ == 1) {
    // Forward execution
    ω[3].c(α, ω+3, ο, ρ, δ, σ);
    if (ω[3].q) {
      // The first sentence was true
      ω[0].q = 1;
      ω[6].c(α, ω+6, ο, ρ, δ, σ);
    }
  } else {
    // Reverse
```
