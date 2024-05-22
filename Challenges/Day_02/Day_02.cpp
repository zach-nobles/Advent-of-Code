#include "Day_02.hpp"

#include <iostream>
#include <fstream>

namespace 
{
  const size_t RED_NUM = 12;
  const size_t GREEN_NUM = 13;
  const size_t BLUE_NUM = 14;
}

size_t numOfCubes(const std::string game, const size_t colorIdx)
{
  size_t i = colorIdx - 2;
  while (game[i] != ' ') i--;

  return std::stoi(game.substr(i, colorIdx - 2));
}

PuzzleSolver::PuzzleSolver(std::string puzzleInput) 
{
  readDoc(puzzleInput);
}

void PuzzleSolver::readDoc(const std::string& puzzleInput)
{
  std::ifstream input(puzzleInput);

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

bool PuzzleSolver::isPossible(const std::string game)
{
  // Red color
  size_t posRed = game.find("red");
  while (posRed != std::string::npos) 
  {
    const size_t cubesNum = numOfCubes(game, posRed);
    if (cubesNum > RED_NUM) return false;

    posRed = game.find("red", posRed + 1);
  }

  // Green color
  size_t posGreen = game.find("green");
  while (posGreen != std::string::npos) 
  {
    const size_t cubesNum = numOfCubes(game, posGreen);
    if (cubesNum > GREEN_NUM) return false;

    posGreen = game.find("green", posGreen + 1);
  }

  // Blue color
  size_t posBlue = game.find("blue");
  while (posBlue != std::string::npos) 
  {
    const size_t cubesNum = numOfCubes(game, posBlue);
    if (cubesNum > BLUE_NUM) return false;

    posBlue = game.find("blue", posBlue + 1);
  }

  return true;
}

std::vector<size_t> PuzzleSolver::fewestSetNum(const std::string game)
{
  std::vector<size_t> fewestNum(3, 0);

  // Red color
  size_t posRed = game.find("red");
  while (posRed != std::string::npos) 
  {
    const size_t cubesNum = numOfCubes(game, posRed);
    if (cubesNum > fewestNum[0]) fewestNum[0] = cubesNum;

    posRed = game.find("red", posRed + 1);
  }

  // Green color
  size_t posGreen = game.find("green");
  while (posGreen != std::string::npos) 
  {
    const size_t cubesNum = numOfCubes(game, posGreen);
    if (cubesNum > fewestNum[1]) fewestNum[1] = cubesNum;

    posGreen = game.find("green", posGreen + 1);
  }

  // Blue color
  size_t posBlue = game.find("blue");
  while (posBlue != std::string::npos) 
  {
    const size_t cubesNum = numOfCubes(game, posBlue);
    if (cubesNum > fewestNum[2]) fewestNum[2] = cubesNum;

    posBlue = game.find("blue", posBlue + 1);
  }

  return fewestNum;
}

size_t PuzzleSolver::idSum()
{
  size_t sum = 0;
  for (auto& line : lines_)
  {
    const size_t id = std::stoi(line.substr(4, line.find(':')));
    if(isPossible(line)) sum += id;
  }

  return sum;
}

double PuzzleSolver::minPowerSum()
{
  double powerSum = 0.0;
  for (auto& line : lines_)
  {
    const std::vector<size_t> fewestNum = fewestSetNum(line);
    double power = (double)(fewestNum[0] * fewestNum[1] * fewestNum[2]);
    powerSum += power;
  }

  return powerSum;
}