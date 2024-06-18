#include <vector>
#include <string>
#include <array>

class RacesRecord 
{
  public:
    RacesRecord(std::string puzzle_input);
    long numOfWaysProduct();
    long long numOfWaysProductCombined();

  private:
    void parseDoc(const std::string& puzzle_input);
    long calcDistance(const long time, const long holding_time);
    void removeSpaces();

    std::vector<long> times_;
    std::vector<long> distances_;
    long combined_time_;
    long combined_distance_;
};
