//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/EnergyCard.h"

#include <iostream>
#include <ostream>

EnergyCard::EnergyCard(std::string _energyType):
    Card(("Energy")),
    energyType(_energyType)
{

}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card  : -- ";
    std::cout << "Card name : " << cardName;
    std::cout << ", Type : " << energyType;
}
