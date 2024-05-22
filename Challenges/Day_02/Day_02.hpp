#include <vector>
#include <string>
#include <map>

class PuzzleSolver 
{
  public:
    PuzzleSolver(std::string puzzleInput);
    size_t idSum();
    double minPowerSum();

  private:
    void readDoc(const std::string& puzzleInput);
    bool isPossible(const std::string game);
    std::vector<size_t> fewestSetNum(const std::string game);

    std::vector<std::string> lines_;
};
