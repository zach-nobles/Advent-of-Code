#ifndef DAY_07_H
#define DAY_07_H

using namespace std;


enum class HAND_TYPE {
    FIVE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    THREE_OF_A_KIND,
    TWO_PAIR,
    ONE_PAIR,
    HIGH_CARD,
};

string to_string(HAND_TYPE hand_type);
int strength(char card);

void Day_07a();
void Day_07b();

#endif