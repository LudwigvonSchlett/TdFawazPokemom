//
// Created by ludwig_van_schlett on 13/11/24.
//

#ifndef CARD_H
#define CARD_H
#include <string>


class Card {

    public:
        Card(std::string _cardName);
        virtual ~Card() = default;

        virtual void displayInfo() const = 0;

    protected:
        const std::string cardName;

};



#endif //CARD_H
