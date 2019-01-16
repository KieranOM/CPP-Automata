#include "PDFA.h"

bool PartialDeterministicFiniteAutomaton::accepts(std::string word) {
    int state = p;
    // Loop through the input
    for (int i = 0; i < word.length(); i++) {
        char current = word[i];
        bool found = false;
        // Loop through the transition functions to find the next state
        std::tuple<int, char, int> transition;
        for (std::set<std::tuple<int, char, int>>::iterator itr = delta.begin(); itr != delta.end(); ++itr) {
            transition = *itr;
            // Check if the function matches the state and character
            if (std::get<0>(transition) == state && std::get<1>(transition) == current) {
                found = true;
                break;
            }
        }
        // Check if a transition was found
        if (found) {
            // Apply the transition function
            state = std::get<2>(transition);
        } else {
            return false;
        }
    }
    return acc.count(state);
};

PartialDeterministicFiniteAutomaton::PartialDeterministicFiniteAutomaton(std::set<int> states, int initialState,
                                                                       std::set<std::tuple<int, char, int>> partialTransitionFunction,
                                                                       std::set<int> acceptingStates) {
    X = states;
    p = initialState;
    delta = partialTransitionFunction;
    acc = acceptingStates;
}
