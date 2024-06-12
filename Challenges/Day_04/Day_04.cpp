#include "Day_04.hpp"

#include <iostream>
#include <fstream>

ScatchCards::ScatchCards(std::string cards_input) 
{
  readDoc(cards_input);
}

void ScatchCards::readDoc(const std::string& cards_input)
{
  std::ifstream input(cards_input);

  if (!input) 
  {
    throw std::runtime_error("Unable to open file");
  }
  std::string line;
  while (std::getline(input, line))
  {
    lines_.push_back(line);
  }
}

std::vector<int> ScatchCards::getMyNums(const std::string& card)
{
  std::vector<int> my_nums;

  int pos = card.find('|') + 1;
  while (pos < card.size())
  {
    if (std::isdigit(card[pos]))
    {
      int i = pos;
      while (card[i] != ' ') i++;

      my_nums.push_back(std::stoi(card.substr(pos, i - pos)));
      pos = i;
    }
    pos += 1;
  }

  return my_nums;
}

std::vector<int> ScatchCards::getWinningNums(const std::string& card)
{
  std::vector<int> winning_nums;

  int pos1 = card.find(':') + 1;
  int pos2 = card.find('|');
  while (pos1 < pos2)
  {
    if (std::isdigit(card[pos1]))
    {
      int i = pos1;
      while (card[i] != ' ') i++;

      winning_nums.push_back(std::stoi(card.substr(pos1, i - pos1)));
      pos1 = i;
    }
    pos1 += 1;
  }

  return winning_nums;
}

int ScatchCards::calculateCardPoints(const std::vector<int>& my_nums, const std::vector<int>& winning_nums)
{
  int points = 0;
  for (const auto& num : winning_nums)
  {
    if (std::find(my_nums.begin(), my_nums.end(), num) != my_nums.end()) 
    {
      points = (points == 0) ? 1 : points * 2;
    }
  }

  return points;
}

int ScatchCards::totalPoints()
{
  int total_points = 0;
  for (auto& line : lines_)
  {
    const std::vector<int> my_nums = getMyNums(line);
    const std::vector<int> winning_nums = getWinningNums(line); 
    total_points += calculateCardPoints(my_nums, winning_nums);
  }

  return total_points;
}

int ScatchCards::calculateFollowingCardsCopies(const std::vector<int>& my_nums, const std::vector<int>& winning_nums)
{
  int copies = 0;
  for (const auto& num : winning_nums)
  {
    if (std::find(my_nums.begin(), my_nums.end(), num) != my_nums.end()) 
    {
      copies++;
    }
  }

  return copies;
}

int ScatchCards::calculateCardsNum() 
{
    std::vector<int> effective_copies(lines_.size(), 1);

    for (int i = 0; i < lines_.size(); i++) {
      const std::vector<int> my_nums = getMyNums(lines_[i]);
      const std::vector<int> winning_nums = getWinningNums(lines_[i]); 
      int new_copies = calculateFollowingCardsCopies(my_nums, winning_nums);

      for (int j = i + 1; j <= i + new_copies && j < lines_.size(); j++) 
      {
        effective_copies[j] += effective_copies[i];
      }
    }

    int total_num = 0;
    for (int num : effective_copies) 
    {
      total_num += num;
    }

    return total_num;
}