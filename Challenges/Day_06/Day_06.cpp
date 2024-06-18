#include "Day_06.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

long countDigits(const long number)
{
  if (number == 0) return 1;
  return long(std::log10(number)) + 1;
}

RacesRecord::RacesRecord(std::string puzzle_input)
{
  parseDoc(puzzle_input);
}

void RacesRecord::parseDoc(const std::string& puzzle_input)
{
  std::ifstream input(puzzle_input);
  
  if (!input) 
  {
    throw std::runtime_error("Unable to open file!");
  }

  std::string line; 
  while (std::getline(input, line))
  {
    if (line.empty()) continue;
    else if (line.find("Time") != std::string::npos)
    {
      std::istringstream time_stream(line.substr(line.find(" ")));

      long time;
      while (time_stream >> time)
      {
        times_.push_back(time);
      }
    }
    else if (line.find("Distance") != std::string::npos)
    {
      std::istringstream distance_stream(line.substr(line.find(" ")));

      long distance;
      while(distance_stream >> distance)
      {
        distances_.push_back(distance);
      }
    }
  }
}

long RacesRecord::calcDistance(const long time, const long holding_time)
{
  const long speed = holding_time;
  const long remaing_time = time - holding_time;

  return long(speed * remaing_time); 
}

long RacesRecord::numOfWaysProduct()
{
  const long num_races = times_.size();
  std::vector<long> num_ways(num_races);

  for (long i = 0; i < num_races; i++)
  {
    for (long t = 0; t <= times_[i]; t++)
    {
      const long distance = calcDistance(times_[i], t);
      if (distance > distances_[i]) num_ways[i]++;
    }
  }

  long product = 1;
  for (const auto& num_way : num_ways)
  {
    product *= num_way;
  }

  return product;
}

void RacesRecord::removeSpaces()
{
  combined_time_ = 0;
  for (long time : times_) 
  {
    long digits = countDigits(time);
    combined_time_ = combined_time_ * std::pow(10, digits) + long(time);
  }

  combined_distance_ = 0;
  for (long dist : distances_) 
  {
    long digits = countDigits(dist);
    combined_distance_ = combined_distance_ * std::pow(10, digits) + dist;
  }
}

long long RacesRecord::numOfWaysProductCombined()
{
  removeSpaces();
  long num_ways{};
  for (long t = 0; t <= combined_time_; t++)
  {
    const long distance = calcDistance(combined_time_, t);
    if (distance > combined_distance_) num_ways++;
  }

  return num_ways;
}
