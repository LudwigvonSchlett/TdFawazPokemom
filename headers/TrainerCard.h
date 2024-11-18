//
// Created by ludwig_van_schlett on 13/11/24.
//

#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"


class TrainerCard: public Card {

    public:
        TrainerCard(std::string _cardName, std::string _trainerEffect);
        ~TrainerCard() = default;

        void displayInfo() const override;

        std::string getTrainerEffect() const;

    private:
        const std::string trainerEffect;



};



#endif //TRAINERCARD_H
