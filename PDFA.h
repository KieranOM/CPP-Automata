#ifndef CPP_AUTOMATA_PDFA_H
#define CPP_AUTOMATA_PDFA_H

#include <set>
#include <tuple>

// Class assumes a well-formed Partial DFA is created
class PartialDeterministicFiniteAutomaton {
private:
    // Finite set of states X
    std::set<int> X;
    // Initial state, where p belongs to X;
    int p;
    // Transition PARTIAL function delta: X x Sigma -> X
    std::set<std::tuple<int, char, int>> delta;
    // Set of accepting states
    std::set<int> acc;
public:
    // Method to run the automata with an input
    bool accepts(std::string word);

    PartialDeterministicFiniteAutomaton(std::set<int> states, int initialState,
                                       std::set<std::tuple<int, char, int>> transitionFunctions,
                                       std::set<int> acceptingStates);
};


#endif
