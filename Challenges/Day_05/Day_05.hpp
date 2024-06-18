#include <vector>
#include <string>
#include <unordered_map>
#include <array>

class SeedLocation 
{
  public:
    SeedLocation(std::string puzzle_input);
    unsigned long lowestLocationNum();
    unsigned long lowestLocationNumRanges();

  private:
    void parseDoc(const std::string& puzzle_input);
    unsigned long mapInputToOutput(const unsigned long input, std::string current_map);

    std::vector<unsigned long> seeds_;
    std::unordered_map<std::string, std::vector<std::array<unsigned long, 3>>> maps_;
};
