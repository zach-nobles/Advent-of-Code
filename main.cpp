// main.cpp
#include <iostream>
#include <string>

#include "Challenges/Day_02/Day_02.hpp"

using namespace std;
int main() 
{
    std::string puzzle_input = "Challenges/Day_02/puzzle_input.txt";
    PuzzleSolver Puzzle(puzzle_input);
    double sum = Puzzle.minPowerSum();
    cout << sum << endl;

    return 0;
}