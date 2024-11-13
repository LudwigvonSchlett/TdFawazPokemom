cmake_minimum_required(VERSION 3.29)
project(TdFawazPokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(TdFawazPokemon main.cpp
        src/Card.cpp
        headers/Card.h
        src/PokemonCard.cpp
        headers/PokemonCard.h
        src/EnergyCard.cpp
        headers/EnergyCard.h
        src/TrainerCard.cpp
        headers/TrainerCard.h
        src/Player.cpp
        headers/Player.h
)
