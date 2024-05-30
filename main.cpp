// main.cpp
#include <iostream>
#include <string>

#include "Challenges/Day_03/Day_03.hpp"

using namespace std;
int main() 
{
    std::string engine_input = "Challenges/Day_03/engine_schematic.txt";
    EngineFix engine(engine_input);
    int sum = engine.gearRatioSum();
    cout << sum << endl;

    return 0;
}