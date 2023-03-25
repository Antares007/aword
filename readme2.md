
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
