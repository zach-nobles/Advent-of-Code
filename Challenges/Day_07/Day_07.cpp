#include <iostream>
#include <memory>
#include <unordered_map>
#include <algorithm>
#include <cmath>

#include "Day_07.h"
#include "../tools/tools.h"

using namespace std;

int strength(char card) {
    switch (card) {
    case 'A': return 13;
    case 'K': return 12;
    case 'Q': return 11;
    case 'T': return 9;
    case '9': return 8;
    case '8': return 7;
    case '7': return 6;
    case '6': return 5;
    case '5': return 4;
    case '4': return 3;
    case '3': return 2;
    case '2': return 1;
    default: return 0;
    }
};


class Player {
    public:

        Player() {}

        vector<char> cards_;
        long long bet_;
        long long wins_ = 0;
        HAND_TYPE hand_type_;
        string name;

        bool vs(shared_ptr<Player> opponent) {
            if (this->hand_type_ < opponent->hand_type_) {
                return true;
            } 
            else if (this->hand_type_ == opponent->hand_type_) {
                for (size_t i = 0; i < this->cards_.size(); i++) {
                    if (strength(this->cards_[i]) > strength(opponent->cards_[i])) {
                        return true;
                    } else if (strength(this->cards_[i]) < strength(opponent->cards_[i])) {
                        return false;
                    }

                }
            }
            return false;
        }

        int number_of_jokers() {
            int n_jokers = 0;
            for (auto card : cards_) {
                if (card == 'J') {
                    n_jokers++;
                }
            }
            return n_jokers;
        }
};

class Dealer {

    public:

        Dealer() {}

        vector<shared_ptr<Player>> players_;
        long long payout_ = 0;
        
        void add_player(string hand) {
            players_.push_back(make_shared<Player>());
            shared_ptr<Player> new_player = players_.back();
            new_player->name = "Player " + to_string(players_.size());
            
            vector<string> items = split(hand,' ');
            string cards_string = items[0];
            for (char card : cards_string) {
                new_player->cards_.push_back(card);
            }
            new_player->bet_ = stoll(items[1]);
        }

        void read_bets() {
            for (auto player : players_) {
                cout << player->name << "'s bet is: $" << player->bet_ << endl;
            }
        }

        void score_player_hand(shared_ptr<Player> player) {
            player->hand_type_ = find_hand_type(player);
        }

        void score_all_players_hand() {
            for (auto player : players_) {
                score_player_hand(player);
            }  
        }

        HAND_TYPE find_hand_type(shared_ptr<Player> player) {
            vector<char> card_options {'A','K','Q','T','9','8','7','6','5','4','3','2'};
            vector<int> card_occurances(card_options.size(),0);

            int card_options_index = 0;
            for (auto card_option : card_options) {
                for (auto player_card : player->cards_) {
                    if (player_card == card_option) {
                        card_occurances[card_options_index]++;
                    }
                }
                card_options_index++;
            }
            int highest_num_of_matches = *max_element(card_occurances.begin(), card_occurances.end());

            switch (highest_num_of_matches + player->number_of_jokers()) {
                case 5:
                    return HAND_TYPE::FIVE_OF_A_KIND;
                case 4:
                    return HAND_TYPE::FOUR_OF_A_KIND;
                case 3:
                    card_occurances.erase(max_element(card_occurances.begin(), card_occurances.end()));
                    if (*max_element(card_occurances.begin(), card_occurances.end()) == 2) {
                        return HAND_TYPE::FULL_HOUSE;
                    }
                    return HAND_TYPE::THREE_OF_A_KIND;
                case 2:
                    card_occurances.erase(max_element(card_occurances.begin(), card_occurances.end()));
                    if (*max_element(card_occurances.begin(), card_occurances.end()) == 2) {
                        return HAND_TYPE::TWO_PAIR;
                    }
                    return HAND_TYPE::ONE_PAIR;
                default:
                    return HAND_TYPE::HIGH_CARD;
            }
        }

        void head_to_head_matchups() {
            for (auto player1 : players_) {
                for (auto player2 : players_) {
                    if (player1 == player2) {continue;}
                    if (player1->vs(player2)) { // win
                        player1->wins_++;
                    }
                }
            }
        }

        void calculate_payout() {
            for (auto player : players_) {
                payout_ += player->bet_ * (player->wins_+1);
            }
        }
};



void Day_07b() {

    shared_ptr<Dealer> dealer = make_shared<Dealer>();

    ifstream inputFile("Challenges/Day_07/input.txt");
    vector<string> hands = split(inputFile,'\n');

    for (auto hand : hands) {
        dealer->add_player(hand);
    }

    dealer->score_all_players_hand();

    dealer->head_to_head_matchups();

    dealer->calculate_payout();

    cout << "Total Cash: " << dealer->payout_ << endl;
}