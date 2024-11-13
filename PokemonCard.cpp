//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "PokemonCard.h"

#include <iostream>
#include <ostream>

PokemonCard::PokemonCard(std::string _cardName, std::string _pokemonType, std::string _familyName, int _evolutionLevel, int _maxHP,
                         int _costAttack1, std::string _attackDesc1, int _attackDamage1,
                         int _costAttack2, std::string _attackDesc2, int _attackDamage2):

    cardName(_cardName),
    pokemonType(_pokemonType),
    familyName(_familyName),
    evolutionLevel(_evolutionLevel),
    maxHP(_maxHP),
    hp(_maxHP),
    energy(0),
    attacks([std::tuple(_costAttack1, _attackDesc1, _attackDamage1) std::tuple(_costAttack2, _attackDamage2, _attackDamage2)])
{

}

void PokemonCard::displayInfo() const {
    std::cout << cardName << std::endl;
    std::cout << pokemonType << std::endl;
    std::cout << familyName << std::endl;
    std::cout << evolutionLevel << std::endl;
    std::cout << maxHP << std::endl;
    std::cout << hp << std::endl;
    std::cout << energy << std::endl;
}

