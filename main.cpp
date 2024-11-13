#include <iostream>

#include "headers/EnergyCard.h"
#include "headers/PokemonCard.h"
#include "headers/TrainerCard.h"


int main() {

    std::cout << "-----" << std::endl;
    std::cout << "Test cartes" << std::endl;
    std::cout << "-----" << std::endl;

    PokemonCard card = PokemonCard("testName", "testType", "testName", 1, 100, 3, "testAttackPuissante", 80, 1, "testAttackFaible", 25);
    card.displayInfo();
    std::cout << std::endl;

    EnergyCard card2 = EnergyCard("testType");
    card2.displayInfo();
    std::cout << std::endl;


    TrainerCard card3 = TrainerCard("testName", "testEffect");
    card3.displayInfo();
    std::cout << std::endl;

    std::cout << "-----" << std::endl;
    std::cout << "Test combat" << std::endl;
    std::cout << "-----" << std::endl;


}
