#include <iostream>
#include <vector>

#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>

int main() {
    Referee ref;
    Human humanPlayer("Mei");
    Computer computerPlayer;

    std::vector<Player*> results;
    for (int game = 0; game < 5; ++game) {
        Player* winner = ref.refGame(&humanPlayer, &computerPlayer);
        results.push_back(winner);
    }

    for (size_t i = 0; i < results.size(); i++) {
        if (results[i] == nullptr) {
            std::cout << "Game " << (i + 1) << ": It's a Tie" << std::endl;
        }
        else {
            std::cout << "Game " << (i + 1) << ": " << results[i]->getName() << " Wins" << std::endl;
        }
    }

    return 0;
}