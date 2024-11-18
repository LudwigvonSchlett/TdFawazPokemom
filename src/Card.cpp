//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/Card.h"

#include <utility>

Card::Card(std::string _cardName) :
    cardName(std::move(_cardName))
{

}

std::string Card::getCardName() const {

    return cardName;

}