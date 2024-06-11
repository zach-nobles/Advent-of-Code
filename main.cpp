// main.cpp
#include <iostream>
#include <string>

#include "Challenges/Day_04/Day_04.hpp"

using namespace std;
int main() 
{
    std::string cards_input = "Challenges/Day_04/cards.txt";
    ScatchCards Cards(cards_input);
    int total_points = Cards.calculateCardsNum();
    std::cout << total_points << std::endl;
    
    return 0;
}