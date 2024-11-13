//
// Created by ludwig_van_schlett on 13/11/24.
//

#ifndef ENERGYCARD_H
#define ENERGYCARD_H
#include "Card.h"


class EnergyCard: public Card {

    public:
        EnergyCard(std::string _energyType);
        ~EnergyCard() = default;

        void displayInfo() const override;

        const std::string cardName;
        const std::string energyType;


};



#endif //ENERGYCARD_H
