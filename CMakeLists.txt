cmake_minimum_required(VERSION 3.12)
project(CPP_Automata)

set(CMAKE_CXX_STANDARD 14)

add_executable(CPP_Automata main.cpp DFA.cpp DFA.h PDFA.cpp PDFA.h NFA.cpp NFA.h)