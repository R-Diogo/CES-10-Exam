#include "head.hpp"

int main(){
    std::vector<Character> students;
    std::vector<Character> professors;
    std::vector<Potion_Type> potions_type;
    std::string file_name;

    config_page();

    auto stage = read_file(students, professors, potions_type, file_name);

    change_characters_potions(students, professors, potions_type);

    start_game(students, professors,  potions_type, stage, file_name);

    return 0;
}
