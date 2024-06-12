// main.cpp
#include <iostream>
#include <string>

#include "Challenges/Day_05/Day_05.hpp"

using namespace std;
int main() 
{
    std::string puzzle_input = "Challenges/Day_05/maps.txt";
    SeedLocation locations(puzzle_input);
    unsigned long min_location = locations.lowestLocationNumRanges();
    std::cout << min_location << std::endl;
    return 0;
}