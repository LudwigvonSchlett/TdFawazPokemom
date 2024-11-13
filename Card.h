//
// Created by ludwig_van_schlett on 13/11/24.
//

#ifndef CARD_H
#define CARD_H
#include <string>


class Card {

    public:
        const std::string cardName;

        Card(std::string _cardName);
        virtual ~Card() = default;
        virtual void displayInfo() const = 0;

};



#endif //CARD_H
