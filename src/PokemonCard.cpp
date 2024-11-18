//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/PokemonCard.h"

#include <iostream>
#include <ostream>

using Attack = std::tuple<int, std::string, int>;

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
    attacks({Attack(_costAttack1, _attackDesc1, _attackDamage1),
               Attack(_costAttack2, _attackDesc2, _attackDamage2)})
{

}

void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card : -- " << "Pokemon name : " << cardName << ", Type : " << pokemonType
                << ", Evolution Level : " << evolutionLevel << " of the family \"" << familyName << "\""
                << ", HP : " << hp << "/" << maxHP << ", Energy : " << energy << std::endl;

    std::cout << "Attacks:" << std::endl;

    for (unsigned int i = 0; i < attacks.size(); ++i) {
        std::cout << "Attack #" << (i + 1) << ":" << std::endl;
        std::cout << "  Cost: " << std::get<0>(attacks[i]) << std::endl;
        std::cout << "  Description: " << std::get<1>(attacks[i]) << std::endl;
        std::cout << "  Damage: " << std::get<2>(attacks[i]) << std::endl;
    }

}

void PokemonCard::addEnergy() {
    energy++;
}

std::string PokemonCard::getEnergyType() const {
    return  pokemonType;
}

/*

void PokemonCard::attack(int attackIndex, PokemonCard* pokemonCard) {

    if (attackIndex > attacks.size()) {
        throw std::out_of_range("Invalid attack index");
    }

    Attack attack = attacks[attackIndex];

    if (std::get<0>(attack) > energy) {
        throw std::invalid_argument("Pokemon doesn't have enough energy");
    }

    pokemonCard->hp -= std::get<2>(attack);

}

*/

Attack PokemonCard::getAttack(int attackIndex) {

    if (attackIndex > attacks.size()) {
        throw std::out_of_range("Invalid attack index");
    }

    return attacks[attackIndex];

}

int PokemonCard::getEnergy() const {

    return energy;

}

int PokemonCard::getMaxHp() const {

    return maxHP;

}


int PokemonCard::getHp() const {

    return hp;

}

void PokemonCard::setHp(int _hp) {

    hp = _hp;

}


