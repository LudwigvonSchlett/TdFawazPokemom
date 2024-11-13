//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/Player.h"

#include <iostream>
#include <ostream>

#include "../headers/EnergyCard.h"

#include <stdexcept>

Player::Player(std::string _playerName):
    playerName(_playerName)
{

}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << " :" << std::endl;

    for (const Card* card : benchCard) {
        if (card != nullptr) {
            card->displayInfo();
        }
    }

}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << " :" << std::endl;

    for (const PokemonCard* pokemonCard : actionCard) {
        if (pokemonCard != nullptr) {
            pokemonCard->displayInfo();
        }
    }

}

void Player::addCardToBench(Card* cardPtr) {
    benchCard.push_back(cardPtr);
}

void Player::activatePokemonCard(int cardIndex) {
    if (cardIndex < 0 || cardIndex >= benchCard.size()) {
        throw std::out_of_range("Invalid card index");
    }

    auto* pokemonCardPtr = dynamic_cast<PokemonCard*>(benchCard[cardIndex]);

    if (pokemonCardPtr == nullptr) {
        throw std::invalid_argument("Card is not a PokemonCard");
    }

    actionCard.push_back(pokemonCardPtr);
    benchCard.erase(benchCard.begin() + cardIndex);
}

void Player::attachEnergyCard(int cardIndex, int pokemonIndex) {
    if (cardIndex < 0 || cardIndex >= benchCard.size()) {
        throw std::out_of_range("Invalid card index");
    }

    if (pokemonIndex < 0 || pokemonIndex >= actionCard.size()) {
        throw std::out_of_range("Invalid pokemeon index");
    }

    PokemonCard* pokemonCardPtr = actionCard[pokemonIndex];

    auto* energyCardPtr = dynamic_cast<EnergyCard*>(benchCard[cardIndex]);

    if (energyCardPtr == nullptr) {
        throw std::invalid_argument("Card is not a EnergyCard");
    }

    if (energyCardPtr->getEnergyType() != pokemonCardPtr->getEnergyType()) {
        //std::cout << "energyType :" << energyCardPtr->getEnergyType() << std::endl;
        //std::cout << "pokemonType :" << pokemonCardPtr->getEnergyType() << std::endl;
        throw std::invalid_argument("EnergyCard is not of the same type as the PokemonCard");
    }

    pokemonCardPtr->addEnergy();

    benchCard.erase(benchCard.begin() + cardIndex);

}


