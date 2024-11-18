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

        void displayBench() const;
        void displayAction() const;

        PokemonCard* getPokemonCardPtr(int pokemonIndex);

        void addCardToBench(Card* cardPtr);
        void activatePokemonCard(int cardIndex);
        void attachEnergyCard(int cardIndex, int pokemonIndex);
        void useTrainer(int cardIndex);
        void attack(int player1pokemonIndex, int attackIndex, Player player2, int player2pokemonIndex);

    private:
        const std::string playerName;
        std::vector<Card*> benchCard;
        std::vector<PokemonCard*> actionCard;

        void effectHealAll();


};



#endif //PLAYER_H
