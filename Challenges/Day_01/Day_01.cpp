#include "Day_01.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> lines;

void importText(string fileName)
{
  ifstream inputfile(fileName);
  string line;
  while (getline(inputfile,line))
  {
    lines.push_back(line);
  }
}

int getValue(vector<string>  lines)
{
  int val = 0;

  for(auto line : lines)
  {
    int l = 0;
    int r = line.size()-1;

    while(!isdigit(line[l]) && l < r)
    { 
      l++;
    }
    while(!isdigit(line[r]) && l < r)
    { 
      r--;
    }
    string val_l = line.substr(l,1);
    string val_r = line.substr(r,1);
    string valStr = val_l + val_r;
    val += stoi(valStr);
  }

  return val;
}

void Day_01()
{
  importText("Challenges/Day_01/input.txt");
  cout<<getValue(lines)<<"\n";

}
