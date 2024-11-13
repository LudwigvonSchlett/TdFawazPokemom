//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../header/EnergyCard.h"

#include <iostream>
#include <ostream>

EnergyCard::EnergyCard(std::string _energyType):
    Card(("Energy")),
    energyType(_energyType)
{

}

void EnergyCard::displayInfo() const {
    std::cout << cardName << std::endl;
    std::cout << energyType << std::endl;
}
