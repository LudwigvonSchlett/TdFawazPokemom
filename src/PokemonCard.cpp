//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/PokemonCard.h"

#include <iostream>
#include <ostream>

PokemonCard::PokemonCard(std::string _cardName, std::string _pokemonType, std::string _familyName, int _evolutionLevel, int _maxHP,
                         int _costAttack1, std::string _attackDesc1, int _attackDamage1,
                         int _costAttack2, std::string _attackDesc2, int _attackDamage2):
    Card((_cardName)),
    pokemonType(_pokemonType),
    familyName(_familyName),
    evolutionLevel(_evolutionLevel),
    maxHP(_maxHP),
    hp(_maxHP),
    energy(0),
    attacks({std::make_tuple(_costAttack1, _attackDesc1, _attackDamage1),
               std::make_tuple(_costAttack2, _attackDesc2, _attackDamage2)})
{

}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card : -- ";
    std::cout << "Pokemon name : " << cardName;
    std::cout << ", Type : " << pokemonType;
    std::cout << ", Evolution Level : " << evolutionLevel;
    std::cout << " of the family \"" << familyName << "\"";
    std::cout << ", HP : " << hp << "/" << maxHP;
    //std::cout << energy << std::endl;
}

void PokemonCard::addEnergy() {
    energy++;
}

std::string PokemonCard::getEnergyType() const {
    return  pokemonType;
}
