// main.cpp
#include <iostream>
#include <string>

#include "Challenges/Day_01/Day_01.hpp"

using namespace std;
int main() {
    std::string document = "Challenges/Day_01/document.txt";
    Calibration Cal(document);
    double sum = Cal.calibrationSum();
    cout << sum <<endl;

    return 0;
}
