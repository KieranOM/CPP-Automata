#include "NFA.h"
#include <iterator>
#include <algorithm>

bool NondeterministicFiniteAutomaton::accepts(std::string word) {
    std::set<int> possibleStates = P;
    std::set<int> tempPossibleStates;
    // Loop through the input
    for (int i = 0; i < word.length(); i++) {
        char current = word[i];
        bool found = false;
        // Loop through the possible states
        for (std::set<int>::iterator itr = possibleStates.begin(); itr != possibleStates.end(); ++itr) {
            bool foundForThisState = false;
            int state = *itr;
            std::tuple<int, char, std::set<int>> transition;
            // Add next states based on current possible state
            for (std::set<std::tuple<int, char, std::set<int>>>::iterator relItr = delta.begin();
                 relItr != delta.end(); ++relItr) {
                transition = *relItr;
                // Check if the relation matches the state and character
                if (std::get<0>(transition) == state && std::get<1>(transition) == current) {
                    std::set<int> poss = std::get<2>(transition);
                    found = true;
                    foundForThisState = true;
                    break;
                }
            }
            if (foundForThisState) {
                // Union temporary states with found states into temporary states
                std::set<int> transitionStates = std::get<2>(transition);
                tempPossibleStates.insert(transitionStates.begin(), transitionStates.end());
            }
        }
        if (found) {
            possibleStates = tempPossibleStates;
            tempPossibleStates.clear();
        } else {
            tempPossibleStates.clear();
            return false;
        }
    }
    // Intersect possible states with accepting states to see if it is possible to end in an accepting state
    std::set<int> intersect;
    std::set_intersection(possibleStates.begin(), possibleStates.end(), acc.begin(), acc.end(),
                          std::inserter(intersect, intersect.begin()));
    return intersect.size() > 0;
};

NondeterministicFiniteAutomaton::NondeterministicFiniteAutomaton(std::set<int> states, std::set<int> initialStates,
                                                                 std::set<std::tuple<int, char, std::set<int>>> transitionRelation,
                                                                 std::set<int> acceptingStates) {
    X = states;
    P = initialStates;
    delta = transitionRelation;
    acc = acceptingStates;
}