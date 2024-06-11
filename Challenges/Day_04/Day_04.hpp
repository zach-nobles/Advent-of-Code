#include <vector>
#include <string>
#include <map>

class ScatchCards 
{
  public:
    ScatchCards(std::string cards_input);
    int totalPoints();
    int calculateCardsNum();

  private:
    int calculateCardPoints(const std::vector<int>& myNums, const std::vector<int>& winningNums);
    std::vector<int> getMyNums(const std::string& card);
    std::vector<int> getWinningNums(const std::string& card);
    int calculateFollowingCardsCopies(const std::vector<int>& my_nums, const std::vector<int>& winning_nums);
    void readDoc(const std::string& cards_input);

    std::vector<std::string> lines_;
};
