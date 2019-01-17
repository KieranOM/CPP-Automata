#include <iostream>
#include "DFA.h"
#include "PDFA.h"
#include "NFA.h"

using namespace std;

int main() {

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

    DeterministicFiniteAutomaton dfa(X, p, delta, acc);

    printf("DFA equivalent to regex of c(bb|ca)*\n");
    printf("Testing 'c': %s\n", dfa.accepts("c") ? "true" : "false");
    printf("Testing 'a': %s\n", dfa.accepts("a") ? "true" : "false");
    printf("Testing 'cbb': %s\n", dfa.accepts("cbb") ? "true" : "false");
    printf("Testing 'cbba': %s\n", dfa.accepts("cbba") ? "true" : "false");
    printf("Testing 'bbca': %s\n", dfa.accepts("bbca") ? "true" : "false");
    printf("Testing 'cbbbbcabbcabbbbcacacacabbca': %s\n",
           dfa.accepts("cbbbbcabbcabbbbcacacacabbca") ? "true" : "false");

    // Clear the sets for re-use
    X.clear();
    delta.clear();
    acc.clear();

    // Equivalent Partial DFA to the DFA above
    X.insert({7, 3, 2, 95});
    p = 7;
    delta.insert(
            {tuple<int, char, int>(7, 'c', 2), tuple<int, char, int>(2, 'b', 3), tuple<int, char, int>(2, 'c', 95),
             tuple<int, char, int>(3, 'b', 2), tuple<int, char, int>(95, 'a', 2)});
    acc.insert({2});

    PartialDeterministicFiniteAutomaton pdfa(X, p, delta, acc);

    printf("\nPartial DFA equivalent to regex of c(bb|ca)*\n");
    printf("Testing 'c': %s\n", pdfa.accepts("c") ? "true" : "false");
    printf("Testing 'a': %s\n", pdfa.accepts("a") ? "true" : "false");
    printf("Testing 'cbb': %s\n", pdfa.accepts("cbb") ? "true" : "false");
    printf("Testing 'cbba': %s\n", pdfa.accepts("cbba") ? "true" : "false");
    printf("Testing 'bbca': %s\n", pdfa.accepts("bbca") ? "true" : "false");
    printf("Testing 'cbbbbcabbcabbbbcacacacabbca': %s\n",
           pdfa.accepts("cbbbbcabbcabbbbcacacacabbca") ? "true" : "false");

    // Clear the sets for re-use
    X.clear();
    delta.clear();
    acc.clear();

    // Equivalent NFA to the regex of a(b|bbb*|b*a)|b
    X.insert({7, 2, 3, 8});
    set<int> P({7, 3});
    set<tuple<int, char, set<int>>>
            deltaPrime({tuple<int, char, set<int>>(7, 'a', set<int>({2, 3})),
                        tuple<int, char, set<int>>(2, 'a', set<int>({8})),
                        tuple<int, char, set<int>>(2, 'b', set<int>({2, 3})),
                        tuple<int, char, set<int>>(3, 'b', set<int>({8}))});
    acc.insert(8);

    NondeterministicFiniteAutomaton nfa(X, P, deltaPrime, acc);

    printf("\nNFA equivalent to regex of a(b|bbb*|b*a)|b\n");
    printf("Testing 'abbb': %s\n", nfa.accepts("abbb") ? "true" : "false");
    printf("Testing 'abb': %s\n", nfa.accepts("abb") ? "true" : "false");
    printf("Testing 'abba': %s\n", nfa.accepts("abba") ? "true" : "false");
    printf("Testing 'a': %s\n", nfa.accepts("a") ? "true" : "false");
    printf("Testing 'aab': %s\n", nfa.accepts("aab") ? "true" : "false");

    return 0;
}

