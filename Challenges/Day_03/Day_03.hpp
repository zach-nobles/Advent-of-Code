#include <vector>
#include <string>

class EngineFix 
{
  public:
    EngineFix(std::string engine_input);
    int partNumSum();
    int gearRatioSum();
    int gearRatio(const size_t lineIdx, const size_t gearPos);

  private:
    void readDoc(const std::string& engine_input);
    bool isPartNum(const size_t lineIdx, const size_t digPos1, const size_t digPos2);

    std::vector<std::string> lines_;
    std::vector<char> symbols = {'@', '#', '$', '%', '&', '*', '-', '+', '=', '/'};
};
