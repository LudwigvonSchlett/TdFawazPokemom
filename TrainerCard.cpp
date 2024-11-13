//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "TrainerCard.h"

#include <iostream>
#include <ostream>

TrainerCard::TrainerCard(std::string _cardName, std::string _trainerEffect):
    Card(_cardName),
    trainerEffect(_trainerEffect)
{

}

void TrainerCard::displayInfo() const {
    std::cout << cardName << std::endl;
    std::cout << trainerEffect << std::endl;
}

