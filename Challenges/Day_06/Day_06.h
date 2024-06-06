#ifndef DAY_06_H
#define DAY_06_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;


/// @brief Copy rows of info to rows of vec. If skip_first_line is true, first line is skipped.
/// @param info vector of strings assumed to be containing integers
/// @param vec vector of ints to be populated with contents of info.
/// @param skip_first_line bool used to skip first line of info (intention is to skip header)
void info_to_vector(const vector<string>& info, vector<int>& vec, bool skip_first_line);

/// @brief Concatenate rows of info to a number (num). If skip_first_line is true, first line is skipped.
/// @param info vector of strings assumed to be containing integers
/// @param vec long long to be populated with the appended integers of info (17 1 14 -> 17114).
/// @param skip_first_line bool used to skip first line of info (intention is to skip header)
void info_to_ll(const vector<string>& info, long long& num, bool skip_first_line);

void Day_06a();
void Day_06b();

#endif