#include <iostream>
#include "DFA.h"

using namespace std;

int main() {

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

// Equivalent DFA to the regex of c(bb|ca)*
DeterministicFiniteAutomata dfa(X, p, delta, acc);

    printf("DFA equivalent to regex of c(bb|ca)*\n");
    printf("Testing 'c': %s\n", dfa.accepts("c") ? "true" : "false");
    printf("Testing 'a': %s\n", dfa.accepts("a") ? "true" : "false");
    printf("Testing 'cbb': %s\n", dfa.accepts("cbb") ? "true" : "false");
    printf("Testing 'cbba': %s\n", dfa.accepts("cbba") ? "true" : "false");
    printf("Testing 'bbca': %s\n", dfa.accepts("bbca") ? "true" : "false");
    printf("Testing 'cbbbbcabbcabbbbcacacacabbca': %s\n",
           dfa.accepts("cbbbbcabbcabbbbcacacacabbca") ? "true" : "false");
    return 0;
}