#ifndef TOOLS_H
#define TOOLS_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Day_06a();
void Day_06b();
vector<string> split(const string& line, char delimiter);
vector<string> split(ifstream& line, char delimiter);

#endif