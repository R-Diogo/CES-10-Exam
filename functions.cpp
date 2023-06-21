#include "head.hpp"

//get file entry and returns file with the current stage content
std::fstream read_file(std::array<Character, NUM_CHARACTERS>& characters, std::array<Potion_Type, NUM_POTIONS>& potions_type, std::string& file_name, std::ostream& os, std::istream& is){
    std::cout << "Enter a valid file with your current safe stage (if you don't have one enter one you would like to create):\n";
    std::cin >> file_name;
    std::fstream stage(file_name);
   
    non_existent_file(stage, file_name);
    empty_file(stage, file_name);
    load_stage(stage, file_name, characters, potions_type);
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
    std::array< std::string, NUM_CHARACTERS> character = {"Catatau", "Catabol", "Gripen", "Yu", "Nobili", "Lopes"};
    for(std::size_t i = 0u; i < NUM_CHARACTERS; ++i){
        stage << character[i] << " Smooth 0\n";
    }
    std::array <std::string, 2> potion = {"Verri", "Fritz_Rene"};
    for(std::size_t i = 0u; i < NUM_POTIONS; i++){
        stage << potion[i] << " 3 3\n";
    }  
}

void load_stage(std::fstream & stage, std::string _file_name, std::array<Character, NUM_CHARACTERS>& characters, std::array<Potion_Type, NUM_POTIONS>& potions_type){
    stage.open(_file_name, std::ios::in);
    load_character(stage, characters);
    load_potion(stage, potions_type);
    stage.close();
}

void load_character(std::fstream& stage, std::array<Character, NUM_CHARACTERS>& character){
    std::string _name, _status;
    int _tired;
    for(std::size_t i = 0u; i < NUM_CHARACTERS; i++){
        stage >> _name >> _status >> _tired;
        Status status = string_status(_status);

        switch(i){
            case 0:
                character[0] = {
                "Catatau", Job::Strenuous, status,{
                {"comp_comp", 0, -100}, {"full_nightlong", 30, 25, false, "Dizzy"}, {"tired_insane", 0, -30, true, "Sleepy"}}, _tired};
                break;
            case 1:
                character[1] = {
                "Catabol", Job::Going, status,{
                {"got_nothing", 15, 5}, {"when_end", 15, 5}, {"help_here", 15, 5}}, _tired};
                break;
            case 2:
                character[2] = {
                "Gripen", Job::Median, status,{
                {"gonna_quit", 15, 5}, {"always_ELE", 15, 5}, {"gripen_3attack", 15, 5}}, _tired};
                break;
            case 3:
                character[3] = {
                "Yu", Job::Strenuous, status,{
                {"hole_your_xxx", 25, 0, true}, {"see_norm", 15, 5}, {"disconnect_ITA", 30, 10, false, "None", false, true}}, _tired};
                break;
            case 4:
                character[4] = {
                "Nobili", Job::Median, status,{
                {"no_class", 15, -20}, {"counter_example", 25, 5}, {"nobili_3attack", 15, 5}}, _tired};
                break;
            case 5:
                character[5] = {
                "Lopes", Job::Going, status,{
                {"HaveFun", 15, -5}, {"AllSame", 10, 0, false, "Dizzy", true}, {"lopes_3attack", 15, 5}}, _tired};
                break;
        }
    }
}

//recieves string with status and returns the corresponding Status
Status string_status(std::string _status){
    if(_status == "Smooth") return Status::Smooth;
    else if(_status == "Tired") return Status::Tired;
    else if(_status == "Dizzy") return Status::Dizzy;
    else return Status::Sleepy;
}

void load_potion(std::fstream& stage, std::array<Potion_Type, NUM_POTIONS>& potion_type){
    unsigned num_potion1, num_potion2;
    std::string potion_type_name;
    for(std::size_t i = 0u; i < NUM_POTIONS; i++){
        stage >> potion_type_name;
        stage >> num_potion1 >> num_potion2;
        switch(i){
            case 0:
                potion_type[0] = {"Verri", {{"no_key", 10, num_potion1}, {"friday_no_class", 10, num_potion2}}};
                break;
            case 1:
                potion_type[1] = {"Fritz_Rene", {{"no_chem_test", 10, num_potion1}, {"way_back_home", 10, num_potion2}}};
                break;
        }
    }
}

//starts game with current stage
void start_game(std::array<Character, NUM_CHARACTERS>& characters, std::array<Potion_Type, NUM_POTIONS>& potions_type, std::fstream& stage, std::string& file_name){
    bool save_quit = false;
    bool won;
    for(std::size_t i = NUM_STUDENTS; i < NUM_CHARACTERS; i++){
        if(characters[i].status != Status::Tired){
            fight(characters, potions_type, i, save_quit);
            won = display_result(characters, i);
            if(save_quit || !won){
                save_and_quit(stage, file_name, characters, potions_type);
            }
        }
    }
}

//starts fight agains professor
void fight(std::array<Character, NUM_CHARACTERS>& characters, std::array<Potion_Type, NUM_POTIONS>& potions_type, std::size_t num_professor, bool & save_quit){
    bool passed_round = false, end_fight = false, professor_turn = false;
    while(true){
        if(professor_turn){
            ai_attack(characters, num_professor);
            end_fight = fight_end(characters, num_professor);
            display_tired(characters, num_professor);
            professor_turn = false;
        }
        else{
            std::size_t choosen_student = choose_student(characters);
            if(characters[choosen_student].status == Status::Dizzy || characters[choosen_student].status == Status::Sleepy){
                if(passed_round){
                    passed_round = false;
                    characters[choosen_student].status = Status::Smooth;
                }
                else{
                    passed_round=true;
                }
            }
            make_move(characters, characters[num_professor], potions_type, save_quit, choosen_student);
            end_fight = fight_end(characters, num_professor);
            display_tired(characters, num_professor);
            professor_turn = true;
        }
        if(end_fight || save_quit) break;
    }
}

//decides on professor attack and make it
void ai_attack(std::array<Character, NUM_CHARACTERS>& characters, std::size_t _num_professor){
    int max_tired_student = 0;
    std::size_t aux = 0u;
    for(std::size_t i = 0u; i < NUM_STUDENTS; ++i){
        if(characters[i].tired > max_tired_student && characters[i].status != Status::Tired){
            max_tired_student = characters[i].tired;
            aux = i;
        }
    }
    int movement = can_kill(characters[_num_professor], max_tired_student);
    if(movement != -1){
        attack_move(characters[_num_professor], characters[aux], movement);
    }
    else{
        Character* possible_students[NUM_STUDENTS] = {};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::size_t position_array=0;
        for(std::size_t j=0; j<NUM_STUDENTS; j++){
            if(characters[j].status != Status::Tired){
                possible_students[position_array] = &characters[j];
                position_array++;
            }
        }
        std::uniform_int_distribution<> distr_student(0,position_array-1);
        std::uniform_int_distribution<> distr_attack(0,2);
        std::size_t num_student = distr_student(gen), num_attack = distr_attack(gen);
        attack_move(characters[_num_professor], *possible_students[num_student], num_attack);
    }
}

//analyze if professor can "kill" any student, return the attack corresponding number to "kill" or -1 if he can't "kill"
int can_kill(Character _professor, int _max_tired_student){
    int max_tired_attack = 0;
    int attack_number;
    for(std::size_t i = 0u; i < 3u; i++){
        int make;
        auto _attack = _professor.attack[i];
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
void attack_move(Character& character_dealer, Character& character_taker, int attack_num, std::ostream& os){
    auto _attack = character_dealer.attack[attack_num];
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
    os << character_taker.name << " got more tired because of " << character_dealer.name << " " << character_dealer.attack[attack_num].move << " movement\n";
}

//update Status of characters and checks if the fight should be ended
bool fight_end(std::array<Character, NUM_CHARACTERS>& characters, std::size_t _num_professor){
    unsigned num_tired = 0;
    for(std::size_t i = 0u; i < NUM_STUDENTS; ++i){
        if(characters[i].tired >= 100) {
            num_tired++;
            characters[i].status = Status::Tired;
        }
    }
    if(characters[_num_professor].tired >= 100) characters[_num_professor].status = Status::Tired;

    if(characters[_num_professor].status == Status::Tired || num_tired == NUM_STUDENTS) return true;
    else return false;
}

//display the "life" of all characters
void display_tired(std::array<Character, NUM_CHARACTERS> _characters, std::size_t _num_professor, std::ostream& os){
    unsigned lenght = name_lenght(_characters);
    for(std::size_t i = 0u; i < NUM_STUDENTS; ++i){
        os << std::setw(lenght) << _characters[i].name << std::left <<
            make_bar(_characters[i].tired) <<
            _characters[i].tired << std::setw(5) << "/100 " << status_string(_characters[i].status)<< std::left << '\n';
    }
    os << std::setw(lenght) << _characters[_num_professor].name << std::left <<
        make_bar(_characters[_num_professor].tired) <<
        _characters[_num_professor].tired << std::setw(5) << "/100 " << status_string(_characters[_num_professor].status) << std::left << '\n';
}

//returns biggest name lenght
unsigned name_lenght(std::array<Character, NUM_CHARACTERS> _characters){
    unsigned max = 0;
    for(std::size_t i = 0; i < NUM_CHARACTERS; i++){
        if(_characters[i].name.length() > max) max = _characters[i].name.length();
    }
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
std::size_t choose_student(std::array<Character, NUM_CHARACTERS> _characters, std::istream& is, std::ostream& os){
    os << "Choose a student :\n";
    while(true){
        for(std::size_t i = 0u; i < NUM_STUDENTS; i++){
            os << i + 1 << ". " << (_characters[i].status != Status::Tired ? "■ " : "□ ") << _characters[i].name << ' ';
        }
        os<<'\n';
        std::size_t choosen_character;
        is >> choosen_character;
        choosen_character--;
        if(_characters[choosen_character].status == Status::Tired){
            os << "Enter a student that is not tired (the blank squares represents that the student is tired)\n";
        }
        else return choosen_character;
    }
}

//options of the round
void make_move(std::array<Character, NUM_CHARACTERS>& characters, Character& professor, std::array<Potion_Type, NUM_POTIONS>& potions_type, bool& save_quit, std::size_t choosen_student, std::istream& is, std::ostream& os){
    char attack_choice;
    display_options(characters[choosen_student]);
    is >> attack_choice;
    switch (attack_choice){
        case '1':
            attack_move(characters[choosen_student], professor, 0);
            break;
        case '2':
            attack_move(characters[choosen_student], professor, 1);
            break;
        case '3':
            attack_move(characters[choosen_student], professor, 2);
            break;
        case '4':
            if(!has_potions(potions_type)){
                os << "You don't have more potions.\n";
                make_move(characters, professor, potions_type, save_quit, choosen_student);
                break;
            }
            potion_type_options(characters, potions_type);
            break;
        case '5':
            save_quit = true;
            break;
    }
}

//displays options of the round
void display_options(Character _character, std::ostream& os){
    os << "Choose a move:\n";
    if(_character.status != Status::Smooth) os << status_string(_character.status) << ' ';
    for(std::size_t i = 0; i < 3u; i++){
        os << i+1 << ". " << _character.attack[i].move <<  " | ";
    }
    os << "4. Potion | 5. Save and Quit\n";
}

bool has_potions(std::array<Potion_Type, NUM_POTIONS> _potions_type, int k){
    bool has = false;
    for(std::size_t i = (k == -1)? 0 : k; i < (k == -1)? NUM_POTIONS : k+1; i++){
        for(std::size_t j = 0; j < 2; j++){
            if(_potions_type[i].potion[j].num_potions != 0){
                has = true;
                break;
            }
        }
        if(has) break;
    }
    return has;
}

//displays types of potions available
void potion_type_options(std::array<Character, NUM_CHARACTERS>& characters, std::array<Potion_Type, NUM_POTIONS>& potions_type, std::istream& is, std::ostream& os){
    std::size_t num_type;
    while(true){
        os << "Choose a potion type:\n";
        for(std::size_t i = 0; i < NUM_POTIONS; i++){
            os << i+1 << ". " << potions_type[i].name << (i == NUM_POTIONS-1 ? "\n" : " | ");
        }
        is >> num_type;
        num_type--;
        if(has_potions(potions_type, num_type)) break;
        else{
            os << potions_type[num_type].name << " has no potions, please enter another one\n";
        }
    }
    potion_options(characters, potions_type[num_type]);
}

//effectively uses the potion
void potion_options(std::array<Character, NUM_CHARACTERS>& characters, Potion_Type& potions, std::ostream& os){
    std::size_t potion_number = display_potions(potions);
    for(std::size_t i = 0; i < NUM_STUDENTS; i++){
        if(characters[i].status != Status::Tired){
            characters[i].tired -= potions.potion[potion_number].rest;
        }
    }
    potions.potion[potion_number].num_potions--;
    os << "Students rested because the potion " << potions.potion[potion_number].potion_name << " was used.\n";
}

//display potions available
std::size_t display_potions(Potion_Type _potions, std::ostream& os, std::istream& is){
    os << "Choose a potion:\n";
    std::size_t potion_number;
    while(true){
        for(std::size_t i = 0; i < 2u; i++){
            os << i+1 << ". " << _potions.potion[i].potion_name << potion_bar(_potions.potion[i]);
        }
        os << "\n";
        is >> potion_number;
        potion_number--;
        if(_potions.potion[potion_number].num_potions != 0){
            break;
        }
        else{
            os << "Please choose a valid potion, the empty squares represents the potions you still have\n";
        }
    }
    return potion_number;
}

//makes potion amount bar
std::string potion_bar(Potion _potion){
    std::string pot_bar = " |";
    for(unsigned i = 0; i < 3-_potion.num_potions; i++) pot_bar += "■";
    for(unsigned i = 0; i < _potion.num_potions; i++) pot_bar += "□";
    pot_bar += "| ";
    return pot_bar;
}

//checks if the fight was won, lost or stopped and displays the result
bool display_result(std::array<Character, NUM_CHARACTERS> _characters, std::size_t _professor_num, std::ostream& os){
    unsigned students_tired = 0;
    for(std::size_t i = 0; i < NUM_STUDENTS; i++){
        if(_characters[i].status == Status::Tired){
            students_tired++;
        }
    }
    os<<'\n';
    if(students_tired == NUM_STUDENTS){
        os << "-------------------\n" << "☠ Oh no you LOST! ☠\n" << "-------------------\n";
        return false;
    }
    else if (_characters[_professor_num].status == Status::Tired){
        os << "----------------------------------\n" << "|✧ Congrats you survived ";
        switch(_professor_num - NUM_STUDENTS){
            case 0:
                os<<"MPG-03 ✧|\n";
                break;
            case 1:
                os<<"MAT-12 ✧|\n";
                break;
            case 2:
                os<<"QUIM-18 ✧|\n";
                break;
        }
        os << "----------------------------------\n\n";
        return true;
    }
    return true;
}

void save_and_quit(std::fstream& stage, std::string _file_name, std::array<Character, NUM_CHARACTERS>& characters, std::array<Potion_Type, NUM_POTIONS>& potions_type){
    stage.open(_file_name, std::ios::out | std::ios::trunc);
   
    for(std::size_t i = 0u; i < NUM_CHARACTERS; ++i){
        std::string status = status_string(characters[i].status);
        stage << characters[i].name << ' ';
        stage << status << ' ';
        stage << characters[i].tired << '\n';
    }
    for(std::size_t i = 0u; i < NUM_POTIONS; ++i){
        stage << potions_type[i].name << ' ';
        stage << potions_type[i].potion[0].num_potions << ' ';
        stage << potions_type[i].potion[1].num_potions << '\n';
    }
    stage.close();
    exit(0);
}