//
// Created by ludwig_van_schlett on 13/11/24.
//

#ifndef POKEMONCARD_H
#define POKEMONCARD_H
#include <vector>

#include "Card.h"


class PokemonCard: public Card {

    public:
        using Attack = std::tuple<int, std::string, int>;

        PokemonCard(std::string _cardName, std::string _pokemonType, std::string _familyName, int _evolutionLevel, int _maxHP,
            int _costAttack1, std::string _attackDesc1, int _attackDamage1,
            int _costAttack2, std::string _attackDesc2, int _attackDamage2);
        ~PokemonCard() = default;

        void displayInfo() const override;

        void addEnergy();
        std::string getEnergyType() const;
        void attack(int attackIndex, PokemonCard* pokemonCard);

    private:
        const std::string pokemonType;
        const std::string familyName;
        const int evolutionLevel;
        const int maxHP;
        int hp;
        int energy;
        //std::vector<std::tuple<int, std::string, int>> attacks;
        std::vector<Attack> attacks;

};



#endif //POKEMONCARD_H
