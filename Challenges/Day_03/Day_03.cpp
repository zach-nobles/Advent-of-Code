#include "Day_03.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Gear {

    public:
        vector<vector<char>>* gridPtr;
        int nrows;
        int ncols;
        vector<int> nums;
        int x;
        int y;
        string numStr1;
        string numStr2;
        int Res;

        Gear(vector<vector<char>> *gridPtr, int y, int x) : gridPtr(gridPtr), x(x), y(y),
                                                            nrows(gridPtr->size()), 
                                                            ncols((*gridPtr)[0].size()) {}

        bool searchAdjacent() {
            vector<int> x_Adjacent = {x-1, x, x+1};
            vector<int> y_Adjacent = {y-1, y, y+1};
            string numStr;
            for (int ycur : y_Adjacent) {
                if (ycur < 0 || ycur >= nrows) continue;
                for (int xcur : x_Adjacent) {
                    if (xcur < 0 || xcur >= ncols) continue;
                    char c = gridPtr->at(ycur).at(xcur);
                    if (isdigit(c)) {
                        while (isdigit(c)) {
                            xcur--;
                            if (xcur < 0) break;
                            c = gridPtr->at(ycur).at(xcur);
                        }
                        xcur++;
                        c = gridPtr->at(ycur).at(xcur);
                        cout << "Starting at: " << c << endl;
                        while (isdigit(c)) {
                            numStr+=c;
                            gridPtr->at(ycur).at(xcur) = 'X';
                            xcur++;
                            if (xcur == ncols) break;
                            c = gridPtr->at(ycur).at(xcur);
                        }
                        cout << "Number is: " << numStr << endl;
                        nums.push_back(stoi(numStr));
                        return true;
                    }
                }
            }
            return false;
        }

};



void Day_03a() {
    vector<vector<char>> charGrid;
    ifstream inputFile("Challenges/Day_03/input.txt");

    // Read the file character by character
    std::string line;
    while (std::getline(inputFile, line)) {
        // Create a vector to hold characters of the current line
        std::vector<char> charLine;

        // Iterate over each character in the line
        for (char c : line) {
            if (c == '.') c = '.';
            else if (!isdigit(c)) c = 'X';
            charLine.push_back(c);
        }

        // Add the vector of characters to the 2D vector
        charGrid.push_back(charLine);
    }
    vector<int> numVec;
    for (size_t i = 0; i < charGrid.size(); i++) {
        for (size_t j = 0; j < charGrid[i].size(); j++) {
            char c = charGrid[i][j];
            string numStr = "";
            if (isdigit(c)) {
                int j_start = j;
                while(isdigit(c)) {
                    numStr+=c;
                    if (j == charGrid[i].size()) break;
                    j++;
                    c = charGrid[i][j];
                }
                int j_end = j-1;
                for (int j_curr = j_start-1; j_curr<=j_end+1; j_curr++) {
                    if (j_curr <= 0 || j_curr >= charGrid[i].size()) continue;

                    if (j_curr == j_start-1 && isalpha(charGrid[i][j_curr])) {
                        numVec.push_back(stoi(numStr));
                        break;
                    }
                    if (j_curr == j_end+1 && isalpha(charGrid[i][j_curr])) {
                        numVec.push_back(stoi(numStr));
                        break;
                    }

                    if (i >= 1 && isalpha(charGrid[i-1][j_curr])) {
                        numVec.push_back(stoi(numStr));
                        break;
                    }
                    if (i < charGrid.size()-1 && isalpha(charGrid[i+1][j_curr])) {
                        numVec.push_back(stoi(numStr));
                        break;
                    }
                }
            }
        }
    }
    int sum = 0;
    for(auto num : numVec) {
        sum+=num;
    }
    cout << sum << endl;
    inputFile.close();
}

void Day_03b() {
    vector<vector<char>> charGrid;
    ifstream inputFile("Challenges/Day_03/input.txt");

    // Read the file character by character
    std::string line;
    while (std::getline(inputFile, line)) {
        // Create a vector to hold characters of the current line
        std::vector<char> charLine;

        // Iterate over each character in the line
        for (char c : line) {
            if (!isdigit(c) && c!='*') c = 'X';
            charLine.push_back(c);
        }

        // Add the vector of characters to the 2D vector
        charGrid.push_back(charLine);
    }
    int sum = 0;
    for (size_t i = 0; i < charGrid.size(); i++) {
        for (size_t j = 0; j < charGrid[i].size(); j++) {
            char c = charGrid[i][j];
            string numStr = "";
            if (c=='*') {
                Gear gear(&charGrid,i,j);
                while(gear.searchAdjacent()){
                    if (gear.nums.size() == 2){
                        sum += gear.nums[0]*gear.nums[1];
                        break;
                    }
                }
            }
        }
    }
    cout << sum << endl;
}

