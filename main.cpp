// main.cpp
#include <iostream>
#include <string>

#include "Challenges/Day_06/Day_06.hpp"

using namespace std;
int main() 
{
    std::string puzzle_input = "Challenges/Day_06/records.txt";
    RacesRecord records(puzzle_input);
    long num_ways = records.numOfWaysProductCombined();
    std::cout << num_ways <<std::endl;
    return 0;
}