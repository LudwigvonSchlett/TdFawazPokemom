cmake_minimum_required(VERSION 3.29)
project(TdFawazPokemon)

set(CMAKE_CXX_STANDARD 20)

add_executable(TdFawazPokemon main.cpp
        src/Card.cpp
        header/Card.h
        src/PokemonCard.cpp
        header/PokemonCard.h
        src/EnergyCard.cpp
        header/EnergyCard.h
        src/TrainerCard.cpp
        header/TrainerCard.h
        src/Player.cpp
        header/Player.h
)
