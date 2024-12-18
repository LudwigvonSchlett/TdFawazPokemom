//
// Created by ludwig_van_schlett on 13/11/24.
//

#include "../headers/Player.h"

using Attack = std::tuple<int, std::string, int>;

Player::Player(std::string _playerName):
    playerName(std::move(_playerName))
{

}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << " :" << std::endl;

    for (const Card* card : benchCard) {
        if (card != nullptr) {
            card->displayInfo();
        }
    }

}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << " :" << std::endl;

    for (const PokemonCard* pokemonCard : actionCard) {
        if (pokemonCard != nullptr) {
            pokemonCard->displayInfo();
        }
    }

}

PokemonCard *Player::getPokemonCardPtr(int pokemonIndex) {

    if (pokemonIndex < 0 || pokemonIndex >= actionCard.size()) {
        throw std::out_of_range("Invalid pokemeon index");
    }

    PokemonCard* pokemonCardPtr = actionCard[pokemonIndex];

    return pokemonCardPtr;

}


void Player::addCardToBench(Card* cardPtr) {
    benchCard.push_back(cardPtr);
}

void Player::activatePokemonCard(int cardIndex) {

    if (cardIndex < 0 || cardIndex >= benchCard.size()) {
        throw std::out_of_range("Invalid card index");
    }

    auto* pokemonCardPtr = dynamic_cast<PokemonCard*>(benchCard[cardIndex]);

    if (pokemonCardPtr == nullptr) {
        throw std::invalid_argument("Card is not a PokemonCard");
    }

    actionCard.push_back(pokemonCardPtr);
    benchCard.erase(benchCard.begin() + cardIndex);

    std::cout << playerName << " is activating a Pokemon Card " << pokemonCardPtr->getCardName() << std::endl;

}

void Player::attachEnergyCard(int cardIndex, int pokemonIndex) {
    if (cardIndex < 0 || cardIndex >= benchCard.size()) {
        throw std::out_of_range("Invalid card index");
    }

    auto* energyCardPtr = dynamic_cast<EnergyCard*>(benchCard[cardIndex]);

    if (energyCardPtr == nullptr) {
        throw std::invalid_argument("Card is not a EnergyCard");
    }

    PokemonCard* pokemonCardPtr = getPokemonCardPtr(pokemonIndex);

    if (energyCardPtr->getEnergyType() != pokemonCardPtr->getEnergyType()) {
        //std::cout << "energyType :" << energyCardPtr->getEnergyType() << std::endl;
        //std::cout << "pokemonType :" << pokemonCardPtr->getEnergyType() << std::endl;
        throw std::invalid_argument("EnergyCard is not of the same type as the PokemonCard");
    }

    pokemonCardPtr->addEnergy();

    benchCard.erase(benchCard.begin() + cardIndex);

    std::cout << playerName << " is attaching the Energy Card of type " << energyCardPtr->getEnergyType() << " to the Pokemon "
            << pokemonCardPtr->getCardName() << std::endl;

}

void Player::useTrainer(int cardIndex) {

    if (cardIndex < 0 || cardIndex >= benchCard.size()) {
        throw std::out_of_range("Invalid card index");
    }

    auto* trainerCardPtr = dynamic_cast<TrainerCard*>(benchCard[cardIndex]);

    if (trainerCardPtr == nullptr) {
        throw std::invalid_argument("Card is not a TrainerCard");
    }

    std::string cardEffect = trainerCardPtr->getTrainerEffect();

    std::cout << playerName << " is using the Trainer Card : " << trainerCardPtr->getCardName() << "'s effect to : "
            << cardEffect << std::endl;

    if (cardEffect == "heal all your action pokemon") {
        effectHealAll();
    }

}


void Player::attack(int player1pokemonIndex, int attackIndex, Player player2, int player2pokemonIndex) {

    PokemonCard* pokemonCardPtr = getPokemonCardPtr(player1pokemonIndex);

    PokemonCard* pokemonCardPtr2 = player2.getPokemonCardPtr(player2pokemonIndex);

    Attack attack = pokemonCardPtr->getAttack(attackIndex);

    if (std::get<0>(attack) > pokemonCardPtr->getEnergy()) {
        throw std::invalid_argument("Pokemon doesn't have enough energy");
    }

    int remainingHp = pokemonCardPtr2->getHp() - std::get<2>(attack);

    pokemonCardPtr2->setHp(remainingHp);

    std::cout << playerName << " attacking " << player2.playerName << "'s Pokemon " << pokemonCardPtr2->getCardName()
        << " with the Pokemon " << pokemonCardPtr->getCardName() << " with its attack : " << std::get<1>(attack) << std::endl;

    std::cout << "Reducing " << player2.playerName << "'s Pokemon's HP by " << std::get<2>(attack) << std::endl;

    if (pokemonCardPtr2->getHp() > 0) {
        std::cout << "Pokemon " << pokemonCardPtr2->getCardName() << " is still alive" << std::endl;
    }
    else {
        std::cout << "Pokemon " << pokemonCardPtr2->getCardName() << " has fainted" << std::endl;
    }

    //pokemonCardPtr->attack(attackIndex, pokemonCardPtr2);

}

void Player::effectHealAll() {

    for (unsigned int i = 0; i < actionCard.size(); ++i) {

        PokemonCard* pokemonCardPtr = getPokemonCardPtr(i);
        pokemonCardPtr->setHp(pokemonCardPtr->getMaxHp());

    }

}

