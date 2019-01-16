# C++ Automata
Implementations of different types of automata as taught in my Models of Computation module at University.

## DFA (Deterministic Finite Automata)

These types of automata consist of the following properties:

- A finite set ![X](https://latex.codecogs.com/gif.latex?X) of values
- An initial state ![p belongs to X](https://latex.codecogs.com/gif.latex?p%5Cin%20X)
- A transition function ![X x Sigma -> X](https://latex.codecogs.com/gif.latex?%5Cdelta%3AX%5Ctimes%5CSigma%5Crightarrow%20X)
- A set of accepting states ![Acc is a subset of X](https://latex.codecogs.com/gif.latex?Acc%5Csubseteq%20X)

The implementation assumes a well-formed DFA will be created with a complete transition function. The example given in `main.cpp` is the equivalent of the regex `c(bb|ca)*`. The example given is the following:

```cpp
// Equivalent DFA to the regex of c(bb|ca)*
set<int> X({7, 2, 3, 95, 18});
int p = 7;
set<tuple<int, char, int>> delta({tuple<int, char, int>(7, 'a', 18), tuple<int, char, int>(7, 'b', 18),
                                  tuple<int, char, int>(7, 'c', 2), tuple<int, char, int>(2, 'a', 18),
                                  tuple<int, char, int>(2, 'b', 3), tuple<int, char, int>(2, 'c', 95),
                                  tuple<int, char, int>(3, 'a', 18), tuple<int, char, int>(3, 'b', 2),
                                  tuple<int, char, int>(3, 'c', 18), tuple<int, char, int>(95, 'a', 2),
                                  tuple<int, char, int>(95, 'b', 18), tuple<int, char, int>(95, 'c', 18),
                                  tuple<int, char, int>(18, 'a', 18), tuple<int, char, int>(18, 'b', 18),
                                  tuple<int, char, int>(18, 'c', 18)});
set<int> acc({2});

DeterministicFiniteAutomata dfa(X, p, delta, acc);
```

## Partial DFA (Deterministic Finite Automata)

A partial DFA is similar to a regular DFA; however, the transition function in this case is only a partial function (not all inputs have an output). The use of a partial transition function means that if it is undefined for the state, then it can immediately terminate. This reduces computation as an input is rejected as soon as the function cannot be applied to it, rather than continuing to the end of the input.

They are made of the following properties:

- A finite set ![X](https://latex.codecogs.com/gif.latex?X) of values
- An initial state ![p belongs to X](https://latex.codecogs.com/gif.latex?p%5Cin%20X)
- A **partial** transition function ![X x Sigma -|> X](https://latex.codecogs.com/gif.latex?%5Cdelta%3A%20X%5Ctimes%5CSigma%5Cpto%7B%5Cmathrel%7B%5Cooalign%7B%5Chfil%24%5Cmapstochar%24%5Chfil%5Ccr%24%5Cto%24%5Ccr%7D%7D%7DX)
- A set of accepting states ![Acc is a subset of X](https://latex.codecogs.com/gif.latex?Acc%5Csubseteq%20X)

The example given in `main.cpp` is the equivalent DFA above, which is of the regex `c(bb|ca)*`. The example given is the following:

```cpp
// Clear the sets for re-use
X.clear(); delta.clear(); acc.clear();

// Equivalent Partial DFA to the DFA above
X.insert({7, 3, 2, 95});
p = 7;
delta.insert(
        {tuple<int, char, int>(7, 'c', 2), tuple<int, char, int>(2, 'b', 3), tuple<int, char, int>(2, 'c', 95),
         tuple<int, char, int>(3, 'b', 2), tuple<int, char, int>(95, 'a', 2)});
acc.insert({2});

PartialDeterministicFiniteAutomata pdfa(X, p, delta, acc);
```