#ifndef CPP_AUTOMATA_NFA_H
#define CPP_AUTOMATA_NFA_H

#include <set>
#include <tuple>

class NondeterministicFiniteAutomaton {
private:
    // Finite set of states X
    std::set<int> X;
    // Set of initial states
    std::set<int> P;
    // Transition relation (x, sigma) belongs to R which is a subset of X x X
    std::set<std::tuple<int, char, std::set<int>>> delta;
    // Set of accepting states
    std::set<int> acc;
public:
    // Method to run the automata with an input
    bool accepts(std::string word);

    NondeterministicFiniteAutomaton(std::set<int> states, std::set<int> initialStates,
                                    std::set<std::tuple<int, char, std::set<int>>> transitionRelation,
                                    std::set<int> acceptingStates);
};


#endif
