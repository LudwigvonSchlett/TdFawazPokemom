cmake_minimum_required(VERSION 3.29)
project(TdFawazPokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(TdFawazPokemon main.cpp
        Card.cpp
        Card.h
        PokemonCard.cpp
        PokemonCard.h
        EnergyCard.cpp
        EnergyCard.h
        TrainerCard.cpp
        TrainerCard.h
)
