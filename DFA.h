#ifndef AUTOMATA_DFA_H
#define AUTOMATA_DFA_H

#include <set>
#include <tuple>

// Class assumes a well-formed DFA is created
class DeterministicFiniteAutomaton {
private:
    // Finite set of states X
    std::set<int> X;
    // Initial state, where p belongs to X
    int p;
    // Transition function delta: X x Sigma -> X
    std::set<std::tuple<int, char, int>> delta;
    // Set of accepting states
    std::set<int> acc;
public:
    // Method to run the automaton with an input
    bool accepts(std::string word);

    DeterministicFiniteAutomaton(std::set<int> states, int initialState,
                                 std::set<std::tuple<int, char, int>> transitionFunction,
                                 std::set<int> acceptingStates);
};

#endif