#include <iostream>

#include "Day_06.h"
#include "../tools/tools.h"

using namespace std;

void info_to_vector(const vector<string>& info, vector<int>& vec, bool skip_first_line) {
    for (auto item : info) {
        if (skip_first_line == true) {skip_first_line=false; continue;}
        vec.push_back(stoi(item));
    }
}
void info_to_ll(const vector<string>& info, long long& num, bool skip_first_line) {
    string numStr = "";
    for (auto item : info) {
        if (skip_first_line == true) {skip_first_line=false; continue;}
        numStr.append(item);
    }
    num = stoll(numStr);
}

void Day_06a() {

    ifstream inputFile("Challenges/Day_06/input.txt");
    vector<string> lines = split(inputFile,'\n');
    vector<string> duration_info = split(lines[0],' ');
    vector<string> distance_info = split(lines[1],' ');

    vector<pair<int,int>> races;

    vector<int> durations;
    info_to_vector(duration_info, durations, true /*skip first line*/);

    vector<int> distances;
    info_to_vector(distance_info, distances, true /*skip first line*/);

    for (size_t i = 0; i < durations.size(); i++) {
        races.push_back({});
        races[i].first = durations[i];
        races[i].second = distances[i];
    }
    
    int winning_combinations = 1;
    for (auto race : races) {
        int wins = 0;
        auto duration = race.first;
        auto distance = race.second;
        
        for (int charge_time = 0; charge_time < duration; charge_time++) {
            auto speed = charge_time;
            auto remaining_time = duration - charge_time;
            auto your_distance = remaining_time * speed;
            if (your_distance > distance) {wins++;}
        }
        winning_combinations *= wins;
    }

    cout << "\nNumber of Winning Combinations: " << winning_combinations << endl << endl;
    return;
}

void Day_06b() {

    ifstream inputFile("Challenges/Day_06/input.txt");
    vector<string> lines = split(inputFile,'\n');
    vector<string> duration_info = split(lines[0],' ');
    vector<string> distance_info = split(lines[1],' ');

    vector<pair<int,int>> races;

    long long duration;
    info_to_ll(duration_info, duration, true /*skip first line*/);

    long long distance;
    info_to_ll(distance_info, distance, true /*skip first line*/);
    
    int wins = 0;
    for (int charge_time = 0; charge_time < duration; charge_time++) {
        auto speed = charge_time;
        auto remaining_time = duration - charge_time;
        auto your_distance = remaining_time * speed;
        if (your_distance > distance) {wins++;}
    }

    cout << "\nNumber of Winning Scenarios: " << wins << endl << endl;

    return;
}
