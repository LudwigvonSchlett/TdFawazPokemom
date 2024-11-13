#include <iostream>

#include "headers/EnergyCard.h"
#include "headers/Player.h"
#include "headers/PokemonCard.h"
#include "headers/TrainerCard.h"

using namespace std;

int main() {

    std::cout << "-----" << std::endl;
    std::cout << "Test cartes" << std::endl;
    std::cout << "-----" << std::endl;

    PokemonCard card = PokemonCard("testName", "testType", "testName", 1, 100, 3, "testAttackPuissante", 80, 1, "testAttackFaible", 25);
    card.displayInfo();
    std::cout << std::endl;

    EnergyCard card2 = EnergyCard("testType");
    card2.displayInfo();
    std::cout << std::endl;


    TrainerCard card3 = TrainerCard("testName", "testEffect");
    card3.displayInfo();
    std::cout << std::endl;

    std::cout << "-----" << std::endl;
    std::cout << "Test combat" << std::endl;
    std::cout << "-----" << std::endl;

    Player player1("Hadi");
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your active pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt", 20, 3, "thunder storm" , 30));

    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);

    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();

    Player player2("Germain");
    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock","heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "Leech Seed" , 15, 3, "Vine Whip", 25));

    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0 , 0);

    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();
}
