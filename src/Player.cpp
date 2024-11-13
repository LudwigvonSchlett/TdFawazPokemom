//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/Player.h"

#include <stdexcept>

Player::Player(std::string _playerName):
    playerName(_playerName)
{

}

void Player::addCardToBench(Card* cardPtr) {
    benchCard.push_back(cardPtr);
}

void Player::activatePokemonCard(int cardIndex) {
    if (cardIndex < 0 || cardIndex >= benchCard.size()) {
        throw std::out_of_range("Invalid card index.");
    }

    auto* pokemonCardPtr = dynamic_cast<PokemonCard*>(benchCard[cardIndex]);

    if (pokemonCardPtr == nullptr) {
        throw std::invalid_argument("Card does not exist or is not a PokemonCard");
    }

    actionCard.push_back(pokemonCardPtr);

    benchCard.erase(benchCard.begin() + cardIndex);
}
