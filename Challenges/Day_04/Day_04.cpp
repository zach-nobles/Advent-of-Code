#include "Day_04.h"
#include "../tools/tools.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;
    
void Day_04a() {

    int totalScore = 0;

    ifstream inputFile("Challenges/Day_04/input.txt");
    vector<string> lines = split(inputFile,'\n');
    
    std::string line;
    for (auto line : lines) {
        string card = split(line,':')[1];
        vector<string> hand = split(card,'|');
        string winningHand = hand[0];
        string yourHand = hand[1];

        vector<string> winningNumsStr = split(winningHand,' ');
        vector<string> yourNumsStr = split(yourHand,' ');
        
        unordered_map<string,string> winningNums;
        int matches = 0;
        for (string numStr : winningNumsStr) {
            winningNums.insert({numStr,numStr});
        }
        for (string numStr : yourNumsStr) {
            if (numStr == "") continue;
            if (winningNums.find(numStr) != winningNums.end()) {
                matches++;
        }
        }
        int cardScore = 0;
        if (matches>0) {
            cardScore += 1;
            matches--;
        }
        while (matches>0) {
            cardScore = cardScore*2;
            matches--;
        }
        totalScore += cardScore;
    }
    cout << totalScore << endl;
}

void Day_04b() {

    vector<int> numOfEachCard;
    int totalCards = 0;
    int cardNum = 0;

    ifstream inputFile("Challenges/Day_04/input.txt");
    vector<string> lines = split(inputFile,'\n');
    
    std::string line;
    for (auto line : lines) numOfEachCard.push_back(1);

    for (auto line : lines) {

        cardNum++;
        int matches = 0;
        
        string card = split(line,':')[1];
        vector<string> hand = split(card,'|');
        string winningHand = hand[0];
        string yourHand = hand[1];

        vector<string> winningNumsStr = split(winningHand,' ');
        vector<string> yourNumsStr = split(yourHand,' ');
        
        unordered_map<string,string> winningNums;
        for (string numStr : winningNumsStr) {
            winningNums.insert({numStr,numStr});
        }
        for (string numStr : yourNumsStr) {
            if (numStr == "") continue;
            if (winningNums.find(numStr) != winningNums.end()) {
                matches++;
            }
        }
        while (matches>0) {
            numOfEachCard[cardNum-1+matches] += numOfEachCard[cardNum-1];
            matches--;
        }
        cout << "I have " << numOfEachCard[cardNum-1] << " of card " << cardNum << endl;
    }

    for (int num : numOfEachCard) totalCards+=num;
    cout << totalCards << endl;
}
