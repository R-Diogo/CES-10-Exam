#include "head.hpp"

int main(){
    std::array<Character, NUM_CHARACTERS> characters;
    std::array<Potion_Type, NUM_POTIONS> potions_type;
    std::string file_name;

    auto stage = read_file(characters, potions_type, file_name);

    start_game(characters, potions_type, stage, file_name);

    return 0;
}