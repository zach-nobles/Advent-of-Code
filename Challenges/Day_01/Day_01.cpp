#include "Day_01.hpp"

#include <iostream>
#include <fstream>

Calibration::Calibration(std::string document) 
{
  deserializeDoc(document);
  initializeMap();
}

void Calibration::initializeMap() 
{
  for (size_t i = 0; i < nums_words_.size(); i++)
  {
    words_to_nums[nums_words_[i]] = nums_[i];
  }
}

void Calibration::deserializeDoc(const std::string& document)
{
  std::ifstream doc(document);

  if (!doc) 
  {
    std::cout << "Unable to open file" << std::endl;
    return;
  }

  std::string line;
  while (std::getline(doc, line))
  {
    lines_.push_back(line);
  }
}

int Calibration::calibrationVal(std::string line) 
{
  std::vector<std::pair<std::string, size_t>> num_idx;

  for (const auto& num : nums_)
  {
    size_t pos = line.find(num);
    while (pos != std::string::npos) 
    {
      num_idx.push_back(std::make_pair(num, pos));
      pos = line.find(num, pos + 1);
    }
  }

  for (auto& num_word : nums_words_)
  {
    size_t pos = line.find(num_word);
    while (pos != std::string::npos) 
    {
      num_idx.push_back(std::make_pair(words_to_nums[num_word], pos));
      pos = line.find(num_word, pos + 1);
    }
  }

  if (num_idx.empty()) 
  {
    return 0;
  }

  // Reorder the vec in ascending order
  std::sort(num_idx.begin(), num_idx.end(), [](const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b) 
  {
    return a.second < b.second;
  });

  // Select the numbers with the first and last idx
  std::string firstNum = num_idx.front().first;
  std::string lastNum = num_idx.back().first;

  std::string num = firstNum + lastNum;
  return std::stoi(num);
}

double Calibration::calibrationSum()
{
  double calSum = 0.0;
  for (auto& line : lines_)
  {
    calSum += calibrationVal(line);
  }

  return calSum;
}

 