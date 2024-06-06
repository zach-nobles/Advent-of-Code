#include "Day_01.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm> 

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
  string val_l = "";
  string val_r = "";

  map<string,string> mp;
  mp["one"]="1";
  mp["two"]="2";
  mp["three"]="3";
  mp["four"]="4";
  mp["five"]="5";
  mp["six"]="6";
  mp["seven"]="7";
  mp["eight"]="8";
  mp["nine"]="9";

  map<string,string> revmp;

  for(auto pair : mp)
  {
    string revmpKey = pair.first;
    reverse(revmpKey.begin(),revmpKey.end());
    revmp[revmpKey] = pair.second;
  }
  //   // Logging the reversed map
  // cout << "Reversed map contents:\n";
  // for (const auto& pair : revmp)
  // {
  //     cout << pair.first << " -> " << pair.second << endl;
  // }

  for(auto line : lines)
  {
    string revLine = line;
    reverse(revLine.begin(),revLine.end());
    // cout<< "rev line --> " << revLine << "\n";
    
    // LHS
    for(size_t i=0; i<line.size();i++)
    {
      if(!isdigit(line[i]))
      {
        for(auto pair:mp)
        {
          if(pair.first == line.substr(i,pair.first.size()))
          {
            val_l = pair.second;
            break;
          }
        }
      }
      else if(isdigit(line[i]))
      {
        val_l = line.substr(i,1);
        break;
      }
      if(!val_l.empty())
      {
        break;
      }
    }

    // RHS
    for(size_t i=0; i<revLine.size();i++)
    {
      if(!isdigit(revLine[i]))
      {
        for(auto pair:revmp)
        {
          if(pair.first == revLine.substr(i,pair.first.size()))
          {
            val_r = pair.second;
            break;
          }
        }
      }
      else if(isdigit(revLine[i]))
      {
        val_r = revLine.substr(i,1);
        break;
      }
      if(!val_r.empty())
      {
        break;
      }
    }
    cout<<"val_l = "<<val_l<<" | val_r = "<<val_r<<"\n";
    string valStr = val_l + val_r;
    val += stoi(valStr);
    val_l = "";
    val_r = "";
  }
  return val;
}

void Day_01()
{
  importText("Challenges/Day_01/input.txt");
  cout<<getValue(lines)<<"\n";
}
