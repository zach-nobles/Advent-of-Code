// main.cpp
#include <iostream>
#include "Challenges/Day_00/Day_00.h"
#include "Challenges/Day_03/Day_03.h"
#include "Challenges/Day_04/Day_04.h"
#include "Challenges/Day_06/Day_06.h"
#include "Challenges/Day_07/Day_07.h"
#include "Challenges/Day_08/Day_08.h"

using namespace std;

constexpr string set_text_yellow() {
    return "\033[33m";
}

constexpr string set_text_white() {
    return "\033[0m";
}

int main() {
    cout << endl << set_text_yellow() << "[RUNNING] Advent of Code Project" << set_text_white() << endl << endl;
    Day_00();
    cout << set_text_yellow() << "\n[COMPLETED] Advent of Code Project" << set_text_white() << endl << endl;
    return 0;
}
