//
// Created by ludwig_van_schlett on 13/11/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"


class Player {

    public:
        Player(std::string _playerName);
        ~Player() = default;

    protected:
        const std::string playerName;
        std::vector<Card*> benchCard;
        std::vector<PokemonCard*> actionCard;

};



#endif //PLAYER_H
