//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/TrainerCard.h"

TrainerCard::TrainerCard(const std::string &_cardName, std::string _trainerEffect):
    Card(_cardName),
    trainerEffect(std::move(_trainerEffect))
{

}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card : -- ";
    std::cout << "Trainer name : " << cardName;
    std::cout << ", Effect : " << trainerEffect;
}

std::string TrainerCard::getTrainerEffect() const {

    return trainerEffect;

}

