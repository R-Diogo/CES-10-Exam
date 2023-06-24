#include "head.hpp"

//get file entry and returns file with the current stage content
std::fstream read_file(std::vector<Character>& students, std::vector<Character>& professors, std::vector<Potion_Type>& potions_type, std::string& file_name, std::ostream& os, std::istream& is){
    std::cout << "Enter a valid file with your current safe stage (if you don't have one enter one you would like to create):\n";
    std::cin >> file_name;
    std::fstream stage(file_name);
   
    non_existent_file(stage, file_name);
    empty_file(stage, file_name);
    load_stage(stage, file_name, students, professors, potions_type);
    return stage; 
}

//checks if file exists
void non_existent_file(std::fstream &file, std::string _file_name){
        file.open(_file_name, std::ios::in);
        if(!file){
            file.clear();
            file.open(_file_name, std::ios::out | std::ios::trunc);
            default_file(file);
        }
        file.close();
}

//checks if file is empty
void empty_file(std::fstream &file, std::string _file_name){
    file.open(_file_name, std::ios::in);
    if(std::string test; !(file >> test)){
            file.clear();
            file.close();
            std::fstream file(_file_name, std::ios::out | std::ios::trunc);
            default_file(file);  
        }
        file.close();
}

//loads default start stage of the game
void default_file (std::fstream & stage){
    std::array<std::string, NUM_CHARACTERS> character = {"Catatau", "Catabol", "Gripen", "Yu", "Nobili", "Lopes"};
    std::array<std::string, 3u> themes = {"MPG-03", "MAT-12", "QUIM-18"};
    std::array<Attack, 3 * NUM_CHARACTERS> attacks;
    attacks[0] = {"comp_comp", 30, 10};
    attacks[1] = {"full_nightlong", 30, 25, false, "Dizzy"};
    attacks[2] = {"tired_insane", 0, -30, true, "Sleepy"};
    attacks[3] = {"got_nothing", 15, 5};
    attacks[4] = {"when_end", 15, 5};
    attacks[5] = {"help_here", 15, 5};
    attacks[6] = {"gonna_quit", 15, 5};
    attacks[7] = {"always_ELE", 15, 5};
    attacks[8] = {"gripen_3attack", 15, 5};
    attacks[9] = {"hole_your_xxx", 25, 0, true};
    attacks[10] = {"see_norm", 15, 5};
    attacks[11] = {"disconnect_ITA", 30, 10, false, "None", false, true};
    attacks[12] = {"no_class", 15, -20};
    attacks[13] = {"counter_example", 25, 5};
    attacks[14] = {"nobili_3attack", 15, 5};
    attacks[15] = {"HaveFun", 15, -5};
    attacks[16] = {"AllSame", 10, 0, false, "Dizzy", true};
    attacks[17] = {"lopes_3attack", 15, 5};
    for(std::size_t i = 0u; i < NUM_CHARACTERS; ++i){
        stage << character[i] << " Smooth 0 ";
        if(i > 2u) stage << themes[i-3];
        else stage << "None";
        stage << '\n';
        for(std::size_t j = 3*i; j < 3*(i+1); j++){
            stage << attacks[j].move << ' ' << attacks[j].make_tired << ' ' << attacks[j].get_tired << ' ' << attacks[j].percentage << ' ' << 
            attacks[j].status_change << ' ' << attacks[j].change_enemy << ' ' << attacks[i].execute << '\n';
        }
        if(i == 2u) stage << "eos\n"; //end of students
    }
    stage << "eop\n"; //end of professors
    std::array<Potion_Type, 2> potion_type;
    potion_type[0] = {"Verri", {{"no_key", 10, 3}, {"friday_no_class", 10, 3}}};
    potion_type[1] = {"Fritz_Rene", {{"no_chem_test", 10, 3}, {"way_back_home", 10, 3}}};
    for(std::size_t i = 0u; i < NUM_POTIONS; i++){
        stage << potion_type[i].name << '\n';
        for(std::size_t j = 0; j < 2; j++){
            stage << potion_type[i].potion[j].potion_name << ' ' << potion_type[i].potion[j].rest << ' ' << potion_type[i].potion[j].num_potions << '\n'; 
        }
    }  
}

void load_stage(std::fstream& stage, std::string _file_name, std::vector<Character>& students, std::vector<Character>& professors, std::vector<Potion_Type>& potions_type){
    stage.open(_file_name, std::ios::in);
    load_character(stage, students, professors);
    load_potion(stage, potions_type);
    stage.close();
}

void load_character(std::fstream& stage, std::vector<Character>& students, std::vector<Character>& professors){
    std::string _status;
    bool student = true;
    Character character;
    while(stage >> character.name){
        if(character.name == "eos"){
            student = false;
            stage >> character.name;
        }else if(character.name == "eop"){
            return;
        }
        stage >> _status >> character.tired >> character.theme;
        character.status = string_status(_status);
        for(std::size_t i = 0; i < 3; i++){
            Attack& att = character.attack[i];
            stage >> att.move >> att.make_tired >> att.get_tired >> att.percentage >> att.status_change >> att.change_enemy >> att.execute;
        }
        if(student) students.push_back(character);
        else professors.push_back(character);
    }
}

//recieves string with status and returns the corresponding Status
Status string_status(std::string _status){
    if(_status == "Smooth") return Status::Smooth;
    else if(_status == "Tired") return Status::Tired;
    else if(_status == "Dizzy") return Status::Dizzy;
    else return Status::Sleepy;
}

void load_potion(std::fstream& stage, std::vector<Potion_Type>& potions_type){
    Potion_Type _potion_type;
    while(stage >> _potion_type.name){
        for(std::size_t i = 0; i < 2; i++){
            stage >> _potion_type.potion[i].potion_name >> _potion_type.potion[i].rest >> _potion_type.potion[i].num_potions;
        }
    }
    potions_type.push_back(_potion_type);
}

void change_characters_potions(std::vector<Character>& students, std::vector<Character>& professors, std::vector<Potion_Type>& potions_type, std::ostream& os, std::istream& is){
    os << "Do you want to add or remove any character or potion?\n1. Yes | 2. No\n";
    char add;
    is >> add;
    if(add == '2') return;
    bool stop = false;
    while(!stop){
        os << "What do you want to do?\n1. Change students | 2. Change professors | 3. Change potions type | 4. Nothing\n";
        char num_change;
        is >> num_change;
        switch(num_change){
            case '1':
                change_characters(students);
                break;
            case '2':
                change_characters(professors);
                break;
            case '3':
                change_potions(potions_type);
                break;
            case '4':
                stop = true;
                break;
        }
    }
}

void change_characters(std::vector<Character>& characters, std::ostream& os, std::istream& is){
    os << "You want to:\n1. Add a new one | 2. Remove\n";
    char rm_add;
    is >> rm_add;
    if(rm_add == '1'){
        Character new_character;
        os << "Ok! I will need the following informations:\n The name of the character and three attacks described by name, damage dealt, damage taken, if it is in percentage, if change the status of the character, if this effect is in the enemy, if this attack is an execute\n";
        os << "The boolean informations enter 0 for false and 1 for true, you can use negative numbers to heal and the percentage will be only used in the damage dealt";
        is >> new_character.name;
        for(std::size_t i = 0; i < 3u; i++){
            is >> new_character.attack[i].move >> new_character.attack[i].make_tired >> new_character.attack[i].get_tired >> new_character.attack[i].percentage >>
            new_character.attack[i].status_change >> new_character.attack[i].change_enemy >> new_character.attack[i].execute;
        }
        characters.push_back(new_character);
    }else{
        os << "Ok! Which one do you want to delete?\n";
        for(std::size_t i = 0; i < characters.size(); i++){
            os << characters[i].name << ((i%3 == 2)? '\n' : ' ');
        }
        os << '\n';
        std::size_t num_del;
        is >> num_del;

        characters[num_del - 1] = characters.back();
        characters.pop_back();
    }
}

void change_potions(std::vector<Potion_Type>& potions_type, std::ostream& os, std::istream& is){
   os << "You want to:\n1. Add a new one | 2. Remove\n";
    char rm_add;
    is >> rm_add;
    if(rm_add == '1'){
        Potion_Type new_potion;
        os << "Ok! I will need the following informations:\n The name of the potion type and two potions described by name and heal.\n";
        os << "The boolean informations enter 0 for false and 1 for true";
        is >> new_potion.name;
        for(std::size_t i = 0; i < 3u; i++){
            is >> new_potion.potion[i].potion_name >> new_potion.potion[i].rest;
        }
        potions_type.push_back(new_potion);
    }else{
        os << "Ok! Which one do you want to delete?\n";
        for(std::size_t i = 0; i < potions_type.size(); i++){
            os << potions_type[i].name << ((i%3 == 2)? '\n' : ' ');
        }
        os << '\n';
        std::size_t num_del;
        is >> num_del;

        potions_type[num_del - 1] = potions_type.back();
        potions_type.pop_back();
    }   
}

//starts game with current stage
void start_game(std::vector<Character>& students, std::vector<Character>& professors, std::vector<Potion_Type>& potions_type, std::fstream& stage, std::string& file_name){
    bool save_quit = false;
    bool won;
    for(std::size_t i = 0; i < professors.size(); i++){
        if(professors[i].status != Status::Tired){
            fight(students, professors[i], potions_type, save_quit);
            won = display_result(students, professors[i]);
            if(save_quit || !won){
                save_and_quit(stage, file_name, students, professors, potions_type);
            }
        }
    }
}

//starts fight agains professor
void fight(std::vector<Character>& students, Character& professor, std::vector<Potion_Type>& potions_type, bool & save_quit){
    bool passed_round = false, end_fight = false, professor_turn = false;
    while(true){
        if(professor_turn){
            ai_attack(students, professor);
            end_fight = fight_end(students, professor);
            display_tired(students, professor);
            professor_turn = false;
        }
        else{
            std::size_t choosen_student = choose_student(students);
            if(students[choosen_student].status == Status::Dizzy || students[choosen_student].status == Status::Sleepy){
                if(passed_round){
                    passed_round = false;
                    students[choosen_student].status = Status::Smooth;
                }
                else{
                    passed_round=true;
                }
            }
            make_move(students, professor, potions_type, choosen_student, save_quit);
            end_fight = fight_end(students, professor);
            display_tired(students, professor);
            professor_turn = true;
        }
        if(end_fight || save_quit) break;
    }
}

//decides on professor attack and make it
void ai_attack(std::vector<Character>& students, Character& professor){
    int max_tired_student = 0;
    std::size_t aux = 0u;
    for(std::size_t i = 0u; i < students.size(); ++i){
        if(students[i].tired > max_tired_student && students[i].status != Status::Tired){
            max_tired_student = students[i].tired;
            aux = i;
        }
    }
    int movement = can_kill(professor, max_tired_student);
    if(movement != -1){
        attack_move(professor, students[aux], professor.attack[movement]);
    }
    else{
        std::vector<Character*> possible_students;
        std::random_device rd;
        std::mt19937 gen(rd());
        for(std::size_t j=0; j<NUM_STUDENTS; j++){
            if(students[j].status != Status::Tired){
                possible_students.push_back(&students[j]);
            }
        }
        std::uniform_int_distribution<> distr_student(0, possible_students.size()-1);
        std::uniform_int_distribution<> distr_attack(0,2);
        std::size_t num_student = distr_student(gen), num_attack = distr_attack(gen);
        attack_move(professor, *possible_students[num_student], professor.attack[num_attack]);
    }
}

//analyze if professor can "kill" any student, return the attack corresponding number to "kill" or -1 if he can't "kill"
int can_kill(Character& professor, int _max_tired_student){
    int max_tired_attack = 0;
    int attack_number;
    for(std::size_t i = 0u; i < 3u; i++){
        int make;
        auto _attack = professor.attack[i];
        if(_attack.percentage){
            make = ((100 - _max_tired_student)*_attack.make_tired)/100;
            if(make > max_tired_attack){
                max_tired_attack = make;
                attack_number = i;
            }
        }
        else if(_attack.execute){
            make = _attack.make_tired;
            if(make > max_tired_attack){
                max_tired_attack = make;
                attack_number = i;
            }
        }
        else{
            make = _attack.make_tired;
            if(make > max_tired_attack){
                max_tired_attack = make;
                attack_number = i;
            }
        }
    }
    if(_max_tired_student + max_tired_attack >= 100) return attack_number;
    else return -1;
}

//effectively performs the attack and display what was executed
void attack_move(Character& character_dealer, Character& character_taker, Attack _attack, std::ostream& os){
    if(character_dealer.status == Status::Sleepy){
        os << character_dealer.name << " couldn't move as " << character_dealer.name << " was Sleepy \n";
        return;
    }
    else if(character_dealer.status == Status::Dizzy){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> miss_attack(0,2);
        if(miss_attack(gen) != 0){
            os << character_dealer.name << " missed move as " << character_dealer.name << " was Dizzy \n";
            return;
        }
    }

    if(_attack.status_change != "None"){
        if(!_attack.change_enemy){
            character_dealer.status = string_status(_attack.status_change);
        }
        else{
            character_taker.status = string_status(_attack.status_change);
        }
    }
    if(_attack.percentage){
        character_taker.tired += ((100-character_taker.tired)*_attack.make_tired) / 100;
    }else if(_attack.execute){
        if(character_taker.tired + _attack.make_tired >=100) character_taker.tired += _attack.make_tired;
        else character_taker.tired += (_attack.make_tired/5);
    }else{
        character_taker.tired += _attack.make_tired;
    }
    character_dealer.tired += _attack.get_tired;
    os << character_taker.name << " got more tired because of " << character_dealer.name << " " << _attack.move << " movement\n";
}

//update Status of characters and checks if the fight should be ended
bool fight_end(std::vector<Character>& students, Character& professor){
    unsigned num_tired = 0;
    for(std::size_t i = 0u; i < students.size(); ++i){
        if(students[i].tired >= 100) {
            num_tired++;
            students[i].status = Status::Tired;
        }
    }
    if(professor.tired >= 100) professor.status = Status::Tired;

    if(professor.status == Status::Tired || num_tired == students.size()) return true;
    else return false;
}

//display the "life" of all characters
void display_tired(std::vector<Character>& students, Character& professor, std::ostream& os){
    unsigned lenght = name_lenght(students, professor);
    for(std::size_t i = 0u; i < students.size(); ++i){
        os << std::setw(lenght) << students[i].name << std::left <<
            make_bar(students[i].tired) <<
            students[i].tired << std::setw(5) << "/100 " << status_string(students[i].status)<< std::left << '\n';
    }
    os << std::setw(lenght) << professor.name << std::left <<
        make_bar(professor.tired) <<
        professor.tired << std::setw(5) << "/100 " << status_string(professor.status) << std::left << '\n';
}

//returns biggest name lenght
unsigned name_lenght(std::vector<Character>& students, Character& professor){
    unsigned max = 0;
    for(std::size_t i = 0; i < students.size(); i++){
        if(students[i].name.length() > max) max = students[i].name.length();
    }
    if(professor.name.length() > max) max = professor.name.length();
    return max;
}

//makes "life" bar
std::string make_bar(int _tired){
    std::string tired_bar = " |";
    unsigned full_squares, empty_squares;
    if(_tired > 100){
        full_squares = 10;
        empty_squares = 0;
    }
    else{
        full_squares = (_tired / 10 < 0 ? 0 : _tired / 10);
        empty_squares = 10 - full_squares;
    }
    for(unsigned i = 0u; i < full_squares; ++i) tired_bar += "■";
    for(unsigned i = 0u; i < empty_squares; ++i) tired_bar += "□";
    tired_bar += "| ";
    return tired_bar;
}

//recieves Status and returns the corresponding string of status
std::string status_string(Status _status){
    if(_status == Status::Smooth) return "Smooth";
    else if(_status == Status::Tired) return "Tired";
    else if(_status == Status::Dizzy) return "Dizzy";
    else return "Sleepy";
}

//selects students to use in the round
std::size_t choose_student(std::vector<Character>& students, std::istream& is, std::ostream& os){
    os << "Choose a student :\n";
    while(true){
        for(std::size_t i = 0u; i < students.size(); i++){
            os << i + 1 << ". " << (students[i].status != Status::Tired ? "■ " : "□ ") << students[i].name << ' ';
        }
        os<<'\n';
        std::size_t choosen_character;
        is >> choosen_character;
        choosen_character--;
        if(students[choosen_character].status == Status::Tired){
            os << "Enter a student that is not tired (the blank squares represents that the student is tired)\n";
        }
        else return choosen_character;
    }
}

//options of the round
void make_move(std::vector<Character>& students, Character& professor, std::vector<Potion_Type>& potions_type, std::size_t _choosen_student, bool& save_quit, std::istream& is, std::ostream& os){
    char attack_choice;
    display_options(students[_choosen_student]);
    is >> attack_choice;
    switch (attack_choice){
        case '1':
            attack_move(students[_choosen_student], professor, students[_choosen_student].attack[0]);
            break;
        case '2':
            attack_move(students[_choosen_student], professor, students[_choosen_student].attack[1]);
            break;
        case '3':
            attack_move(students[_choosen_student], professor, students[_choosen_student].attack[3]);
            break;
        case '4':
            if(!has_potions(potions_type)){
                os << "You don't have more potions.\n";
                make_move(students, professor, potions_type, _choosen_student, save_quit);
                break;
            }
            potion_type_options(students, potions_type);
            break;
        case '5':
            save_quit = true;
            break;
    }
}

//displays options of the round
void display_options(Character& student, std::ostream& os){
    os << "Choose a move:\n";
    if(student.status != Status::Smooth) os << status_string(student.status) << ' ';
    for(std::size_t i = 0; i < 3u; i++){
        os << i+1 << ". " << student.attack[i].move <<  " | ";
    }
    os << "4. Potion | 5. Save and Quit\n";
}

bool has_potions(std::vector<Potion_Type>& potions_type, bool all, std::size_t num){
    bool has = false;
    for(std::size_t i = (all)? 0 : num; i < (all)?  : num+1; i++){
        for(std::size_t j = 0; j < 2; j++){
            if(potions_type[i].potion[j].num_potions != 0){
                has = true;
                return has;
            }
        }
    }
    return has;
}

//displays types of potions available
void potion_type_options(std::vector<Character>& students, std::vector<Potion_Type>& potions_type, std::istream& is, std::ostream& os){
    std::size_t num_type;
    while(true){
        os << "Choose a potion type:\n";
        for(std::size_t i = 0; i < NUM_POTIONS; i++){
            os << i+1 << ". " << potions_type[i].name << (i == NUM_POTIONS-1 ? "\n" : " | ");
        }
        is >> num_type;
        num_type--;
        if(has_potions(potions_type, false, num_type)) break;
        else{
            os << potions_type[num_type].name << " has no potions, please enter another one\n";
        }
    }
    potion_options(students, potions_type[num_type]);
}

//effectively uses the potion
void potion_options(std::vector<Character>& students, Potion_Type& potions, std::ostream& os){
    std::size_t potion_number = display_potions(potions);
    for(std::size_t i = 0; i < NUM_STUDENTS; i++){
        if(students[i].status != Status::Tired){
            students[i].tired -= potions.potion[potion_number].rest;
        }
    }
    potions.potion[potion_number].num_potions--;
    os << "Students rested because the potion " << potions.potion[potion_number].potion_name << " was used.\n";
}

//display potions available
std::size_t display_potions(Potion_Type& potions, std::ostream& os, std::istream& is){
    os << "Choose a potion:\n";
    std::size_t potion_number;
    while(true){
        for(std::size_t i = 0; i < 2u; i++){
            os << i+1 << ". " << potions.potion[i].potion_name << potion_bar(potions.potion[i]);
        }
        os << "\n";
        is >> potion_number;
        potion_number--;
        if(potions.potion[potion_number].num_potions != 0){
            break;
        }
        else{
            os << "Please choose a valid potion, the empty squares represents the potions you still have\n";
        }
    }
    return potion_number;
}

//makes potion amount bar
std::string potion_bar(Potion& potion){
    std::string pot_bar = " |";
    for(unsigned i = 0; i < 3-potion.num_potions; i++) pot_bar += "■";
    for(unsigned i = 0; i < potion.num_potions; i++) pot_bar += "□";
    pot_bar += "| ";
    return pot_bar;
}

//checks if the fight was won, lost or stopped and displays the result
bool display_result(std::vector<Character>& students, Character& professor, std::ostream& os){
    unsigned students_tired = 0;
    for(std::size_t i = 0; i < students.size(); i++){
        if(students[i].status == Status::Tired){
            students_tired++;
        }
    }
    os<<'\n';
    if(students_tired == students.size()){
        os << "-------------------\n" << "☠ Oh no you LOST! ☠\n" << "-------------------\n";
        return false;
    }
    else if (professor.status == Status::Tired){
        os << "----------------------------------\n" << "|✧ Congrats you survived ";
        os << professor.theme << " ✧|\n";
        os << "----------------------------------\n\n";
        return true;
    }
    return true;
}

void save_and_quit(std::fstream& stage, std::string _file_name, std::vector<Character>& students, std::vector<Character>& professors, std::vector<Potion_Type>& potions_type){
    stage.open(_file_name, std::ios::out | std::ios::trunc);
   
    for(std::size_t i = 0u; i < students.size(); ++i){
        std::string status = status_string(students[i].status);
        stage << students[i].name << ' ' << status << ' ' << students[i].tired << ' ' << students[i].theme << '\n';
        for(std::size_t j = 0; j < 3; j++){
            stage << students[i].attack[j].move << ' ' << students[i].attack[j].make_tired << ' ' << students[i].attack[j].get_tired << ' ' <<
            students[i].attack[j].percentage << ' ' << students[i].attack[j].status_change << ' ' << students[i].attack[j].change_enemy << ' ' <<
            students[i].attack[j].execute << '\n';
        }
    }
    for(std::size_t i = 0u; i < NUM_POTIONS; ++i){
        stage << potions_type[i].name << '\n';
        for(std::size_t j = 0u; j < 2; j++){
            stage << potions_type[i].potion[j].potion_name << ' ' << potions_type[i].potion[j].rest << ' ' << potions_type[i].potion[j].num_potions << '\n';
        }
    }
    stage.close();
    exit(0);
}