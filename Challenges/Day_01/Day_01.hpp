#include <vector>
#include <string>
#include <map>

class Calibration 
{
  public:
    Calibration(std::string document);
    double calibrationSum();

  private:
    void readDoc(const std::string& document);
    int calibrationVal(std::string line);
    void initializeMap();

    std::vector<std::string> lines_;
    std::unordered_map<std::string, std::string> words_to_nums;
    std::vector<std::string> nums_ {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    std::vector<std::string> nums_words_ {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
};

