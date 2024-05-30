#include "Day_03.hpp"

#include <iostream>
#include <fstream>

EngineFix::EngineFix(std::string engine_input) 
{
  readDoc(engine_input);
}

void EngineFix::readDoc(const std::string& engine_input)
{
  std::ifstream input(engine_input);

  if (!input) 
  {
    std::cout << "Unable to open file" << std::endl;
    return;
  }
  std::string line;
  while (std::getline(input, line))
  {
    lines_.push_back(line);
  }
}

bool EngineFix::isPartNum(const size_t lineIdx, const size_t digPos1, const size_t digPos2)
{
  const size_t linesNum = lines_.size();
  const size_t lineLength = lines_[lineIdx].size();

  for (const auto& symbol : symbols)
  {
    // Handle left and right of the number 
    if (digPos1 > 0) 
    {
      if (lines_[lineIdx][digPos1 - 1] == symbol) return true;
    }
    if (digPos2 < lineLength - 1) 
    {
      if (lines_[lineIdx][digPos2 + 1] == symbol) return true;
    }

    // Handle above the number
    if (lineIdx > 0)
    {
      for (size_t i = digPos1; i <= digPos2; i++)
      {
        if (lines_[lineIdx - 1][i] == symbol) return true;
      }
      if (digPos1 > 0) 
      {
        if (lines_[lineIdx - 1][digPos1 - 1] == symbol) return true;
      }
      if (digPos2 < lineLength - 1)
      {
        if (lines_[lineIdx - 1][digPos2 + 1] == symbol) return true;
      }
    }

    // Handle below the number 
    if (lineIdx < linesNum - 1)
    {
      for (size_t i = digPos1; i <= digPos2; i++)
      {
        if (lines_[lineIdx + 1][i] == symbol) return true;
      }
      if (digPos1 > 0) 
      {
        if (lines_[lineIdx + 1][digPos1 - 1] == symbol) return true;
      }
      if (digPos2 < lineLength - 1)
      {
        if (lines_[lineIdx + 1][digPos2 + 1] == symbol) return true;
      }
    }
  }

  return false;
}

int EngineFix::gearRatio(const size_t lineIdx, const size_t gearPos)
{
  const size_t linesNum = lines_.size();
  const size_t lineLength = lines_[lineIdx].size();
  std::vector<int> gearNums {};

  auto extractNumber = [&](const size_t r, const size_t c) 
  {
    if (!std::isdigit(lines_[r][c])) return;

    size_t start = c, end = c;
    while (start > 0 && std::isdigit(lines_[r][start - 1])) start--;
    while (end < lines_[r].size() - 1 && std::isdigit(lines_[r][end + 1])) end++;
    
    gearNums.push_back(std::stoi(lines_[r].substr(start, end - start + 1)));
  };

  // Handle left and right of * 
  if (gearPos > 0) 
  {
    if (std::isdigit(lines_[lineIdx][gearPos - 1])) extractNumber(lineIdx, gearPos - 1);
  }
  if (gearPos < lineLength - 1) 
  {
    if (std::isdigit(lines_[lineIdx][gearPos + 1])) extractNumber(lineIdx, gearPos + 1);
  }

  // Handle above *
  if (lineIdx > 0)
  {
    if (std::isdigit(lines_[lineIdx - 1][gearPos])) extractNumber(lineIdx - 1, gearPos);
    
    if (gearPos > 0 && std::isdigit(lines_[lineIdx - 1][gearPos - 1]) && !std::isdigit(lines_[lineIdx - 1][gearPos])) 
    {
      extractNumber(lineIdx - 1, gearPos - 1);
    }

    if (gearPos < lineLength - 1 && std::isdigit(lines_[lineIdx - 1][gearPos + 1]) && !std::isdigit(lines_[lineIdx - 1][gearPos])) 
    {
      extractNumber(lineIdx - 1, gearPos + 1);
    }
  }

  // Handle below *
  if (lineIdx < linesNum - 1)
  {
    if (std::isdigit(lines_[lineIdx + 1][gearPos])) extractNumber(lineIdx + 1, gearPos);
    
    if (gearPos > 0 && std::isdigit(lines_[lineIdx + 1][gearPos - 1]) && !std::isdigit(lines_[lineIdx + 1][gearPos])) 
    {
      extractNumber(lineIdx + 1, gearPos - 1);
    }

    if (gearPos < lineLength - 1 && std::isdigit(lines_[lineIdx + 1][gearPos + 1]) && !std::isdigit(lines_[lineIdx + 1][gearPos])) 
    {
      extractNumber(lineIdx + 1, gearPos + 1);
    }
  }

  // Return a gear ratio only if gearNums has EXACTLY two digits
  if (gearNums.size() == 2) return gearNums[0] * gearNums[1];
  else return 0;
}

int EngineFix::partNumSum()
{
  const size_t linesNum = lines_.size();
  int sum = 0;

  for (size_t lineIdx = 0; lineIdx < linesNum; lineIdx++)
  {
    size_t i = 0;

    while (i < lines_[lineIdx].size())
    {
      if (std::isdigit(lines_[lineIdx][i]))
      {
        size_t digPos1 = i;
        size_t digPos2 = i;
        while (digPos2 < lines_[lineIdx].size() && std::isdigit(lines_[lineIdx][digPos2]))
        {
          digPos2++;
        }

        if (isPartNum(lineIdx, digPos1, digPos2 - 1))
        {
          sum += std::stoi(lines_[lineIdx].substr(digPos1, digPos2 - digPos1));
        }
        i = digPos2;
      }
      else i++;
    }
  }

  return sum;
}

int EngineFix::gearRatioSum()
{
  const size_t linesNum = lines_.size();
  int sum = 0;

  for (size_t lineIdx = 0; lineIdx < linesNum; lineIdx++)
  {
    for (size_t i = 0; i < lines_[lineIdx].size(); i++)
    {
      if (lines_[lineIdx][i] == '*')
      {
        sum += gearRatio(lineIdx, i);
      }
    }
  }

  return sum;
}
