#include <iostream>

#include "EnergyCard.h"
#include "PokemonCard.h"
#include "TrainerCard.h"


int main() {

    PokemonCard card = PokemonCard("testName", "testType", "testName", 1, 100, 3, "testAttackPuissante", 80, 1, "testAttackFaible", 25);
    card.displayInfo();

    EnergyCard card2 = EnergyCard("testType");
    card2.displayInfo();

    TrainerCard card3 = TrainerCard("testName", "testEffect");
    card3.displayInfo();

}
