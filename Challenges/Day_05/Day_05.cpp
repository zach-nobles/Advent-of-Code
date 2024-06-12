#include "Day_05.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

SeedLocation::SeedLocation(std::string puzzle_input) 
{
  parseDoc(puzzle_input);
}

void SeedLocation::parseDoc(const std::string& puzzle_input)
{
  std::ifstream input(puzzle_input);

  if (!input) 
  {
    throw std::runtime_error("Unable to open file");
  }

  std::string line;
  std::string current_map;

  while (std::getline(input, line))
  {
    if (line.empty()) continue;
    if (line.find("seeds:") != std::string::npos)
    {
      std::istringstream seeds_stream(line.substr(line.find(" ")));
      
      unsigned long seed;
      while (seeds_stream >> seed)
      {
        seeds_.push_back(seed);
      }
    }
    else if (line.find("map:") != std::string::npos)
    {
      current_map = line.substr(0, line.find(" map:"));
    }
    else if (std::isdigit(line[0]) && !current_map.empty())
    {
      std::istringstream stream(line);
      unsigned long destination, source, length;
      while (stream >> destination >> source >> length)
      {
        maps_[current_map].push_back({destination, source, length});
      }
    }
  }
}

unsigned long SeedLocation::mapInputToOutput(const unsigned long input, std::string current_map)
{
  for (const auto& arr : maps_[current_map])
  {
    if (input >= arr[1] && input <= arr[1] + arr[2])
    {
      const unsigned long idx = input - arr[1];
      return arr[0] + idx; 
    }
  }
  return input;
}

unsigned long SeedLocation::lowestLocationNum()
{
  unsigned long min_location = std::numeric_limits<unsigned long>::max();
  for (auto& seed : seeds_)
  {
    const unsigned long soil = mapInputToOutput(seed, "seed-to-soil");
    const unsigned long fertilizer = mapInputToOutput(soil, "soil-to-fertilizer");
    const unsigned long water = mapInputToOutput(fertilizer, "fertilizer-to-water");
    const unsigned long light = mapInputToOutput(water, "water-to-light");
    const unsigned long temperature = mapInputToOutput(light, "light-to-temperature");
    const unsigned long humidity = mapInputToOutput(temperature, "temperature-to-humidity");
    unsigned long location = mapInputToOutput(humidity, "humidity-to-location");

    if (location < min_location) min_location = location;
  }

  return min_location;
}

unsigned long SeedLocation::lowestLocationNumRanges()
{
  if (seeds_.size() % 2 != 0) throw std::runtime_error("There is not a range for every starting seed!");

  unsigned long min_location = std::numeric_limits<unsigned long>::max();
  for (size_t i = 0; i < seeds_.size(); i+=2)
  {
    std::cout << "Processing range " << seeds_[i + 1] << std::endl;
    for (unsigned long k = 0; k < seeds_[i + 1]; k++)
    {
      const unsigned long soil = mapInputToOutput(seeds_[i] + k, "seed-to-soil");
      const unsigned long fertilizer = mapInputToOutput(soil, "soil-to-fertilizer");
      const unsigned long water = mapInputToOutput(fertilizer, "fertilizer-to-water");
      const unsigned long light = mapInputToOutput(water, "water-to-light");
      const unsigned long temperature = mapInputToOutput(light, "light-to-temperature");
      const unsigned long humidity = mapInputToOutput(temperature, "temperature-to-humidity");
      unsigned long location = mapInputToOutput(humidity, "humidity-to-location");

    if (location < min_location) min_location = location;
    }
  }

  return min_location;
}



