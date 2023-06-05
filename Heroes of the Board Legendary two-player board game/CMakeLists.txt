cmake_minimum_required(VERSION 3.25)
project(Heroes_of_the_Board_Legendary_two_player_board_game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Heroes_of_the_Board_Legendary_two_player_board_game main.cpp Board.cpp Board.h Pieces.cpp Pieces.h Ranged.cpp Ranged.h Melee.cpp Melee.h Bowman.cpp Bowman.h Elf.cpp Elf.h Mage.cpp Mage.h Spearman.cpp Spearman.h Ranger.cpp Ranger.h Swordsman.cpp Swordsman.h Knight.cpp Knight.h)
