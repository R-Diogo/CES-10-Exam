#include "head.hpp"

void config_page(std::ostream& os, std::istream& is){

    char option;

        os <<   "-----------------------------------------------------------------------------------------------------------------\n"       
                "\t\t\t\t\t  Welcome to our CES-10 Exam\n \t\t\t\tMade by: Diogo Bueno, Lucas Barros, " 
                "Luiz Felipe\n \t\t\t\t\t\t    T27.2\n"
                "-----------------------------------------------------------------------------------------------------------------\n"
                "Please enter 1 if you'd like to start the game or enter 2 if you'd to see a brief description\n"
                "1. Start game | 2. Brief description of the attacks, potions and mechanisms\n";
    is >> option;

    switch (option) {
        case '1':
            break;
        case '2':
            tutorial();
            break;
    }  
}

void tutorial(std::ostream& os, std::istream& is){
    char option;
    bool start = false;
    os <<   "--------------------------------------------------- Tutorial ----------------------------------------------------\n"
            "Welcome to our RPG in which it basically consist of a battle in ITA, where we (students)\n "
            "will be fighting against all odds versus our institution and professors :D\n\n"
            "This page is responsable to set a brief description about the mechanisms of the game like\n"
            "students and professors attacks, potions, status...\n\n"

            "Please, enter a valid digit corresponding to the option you'd like to read about:\n"
            "1. Students | 2. Professors | 3. Potions | 4. Few mechanichs about the game | 5. Go back to the inicial page\n";

    while(start = true and is >> option){
        tutorial_texts(option, start);  
        os <<   "Please, enter a valid digit corresponding to the option you'd like to read about:\n"
                "1. Students | 2. Professors | 3. Potions | 4. Few mechanichs about the game | 5. Go back to the inicial page\n";
    }
}

void tutorial_texts(char option, bool& start, std::ostream& os){
    switch (option) {
        case '1':
            os <<   "\n-------------------------------------------- The Students - Blue Team -------------------------------------------\n\n"
                    "1. Catatau\n"
                    "\t1st attack: comp-comp\n"
                    "\t\tThe insane cancer is driving himself crazy in order to get COMP as his graduation.\n"
                    "\tTo achieve this goal, the madness student studies stopless damaging the teacher in 15hp\n"
                    "\tbesides of damaging himself in 5hp.\n\n"

                    "\t2nd attack: full nightlong\n"
                    "\t\tDespite of had insanely studied during the bimester, the madness cancer concludes that it\n"
                    "\twas not enough and decides to study all the night long damaging himself in 30hp and attacking the\n"
                    "\tenemy in 25hp.\n\n"

                    "\t3rd attack: insanely tired\n"
                    "\t\tAfter the insanely gagá the madness cancer finaly realizes that he's exhausted and decides to\n"
                    "\ttake a break. In order to relax, the tired cancer takes one day off to watch anime all day long skipping \n"
                    "\tthe next turn. As a consequence of the anime day, Catatau regenerates 30hp and will be able to make a\n"
                    "\tstronger attack, on his next playable turn, increasing his attack in 20%.\n\n";
            break;

        case '2':
            os <<   "\n-------------------------------------------- The Teachers - Red Team --------------------------------------------\n\n"
                    "1. Yu\n"
                    "\t1st attack: Hole is your XXX\n"
                    "\t\tThe student splips over himself and asks a question to the teacher wondering how he could \n"
                    "\tdraw the hole furiously the teacher screams to the student saying 'Hole is your XXX' dammaging\n"
                    "\tthe student in 25% hp.\n\n"

                    "\t2nd attack: Let's check on RUMAER\n"
                    "\t\tYu in a moment of doubt after a tricky question made by a smart student can't answer but\n"
                    "\tdammages the curious student in 15hp and himself in 5hp\n\n"

                    "\t3rd attack: Disconnect from ITA\n"
                    "\t\tYu executes the student of a fatality movement causing damage of 30hp if he can kill the\n"
                    "\tstudent or damage 5hp if he can't kill the student\n\n"


                    "2. Chernobilli\n"
                    "\t1st attack: Classes canceled\n"
                    "\t\tAs the recents changes in the fund building had affected many classes, Mr Nobilli gives \n"
                    "\tthe power to the class to choose if they wanna to move to 'online' classes. Without knowing \n"
                    "\tthat the class would not exist anymore, T2 accepts happily without knowing about the danger \n"
                    "\tfuture... Because of that, Mr Nobilli damages the student in 15hp and heals himself in 10hp\n\n"

                    "\t2nd attack: Counter example\n"
                    "\t\tMr Nobilli magicaly summons a miraculous absurd counter example that proof his afimartive \n"
                    "\ton the weekly test, damaging the students in 25hp\n\n"

                    "\t3rd attack: TBD\n"


                    "3. John Lopes\n"
                    "\t1st attack: Have Fun!\n"
                    "\t\tMr John Loko claims that the college period is a moment of fun and entertainment that \n"
                    "\tyou can learn and act as your will says. The students, everyday being more exhausted, see \n"
                    "\tthat it all was a big bizuleu and realizes that the extreme opposite way isdominating \n"
                    "\ttheir lives, damaging the students in 15hp while Mr John Loko regenerates 5hp.\n\n"

                    "\t2nd attack: Equals but diferents\n"
                    "\t\tMr John Loko decides to use the same notation of the most advanced book of quantum chemistry \n"
                    "\tin which the author explains the phenomenon using two terms, J and S, that are equals but \n"
                    "\tdifferents at the same time, breaking all the physics and dimensional equality in the equations.\n"
                    "\tThis technique seems to be a new tactic to make the students more confused, making all the 3 of \n"
                    "\tthem dizzy.\n\n"

                    "\t3rd attack: The final test will be easy, confia\n\n";
            break;

        case '3':
            os <<   "--------------------------------------------------- Potions -----------------------------------------------------\n"
                    "1. Verri\n\n"
                    "a) Forgot the Key\n"
                    "\t\tAs a heroic act, Mr. Verri forgets the room key and as we all are energyless, Mr. Verri \n"
                    "\tdecides to cancel the class, giving a chance to our students rest a little,  regenerating our tired\n"
                    "\tstudents in 20hp.\n\n"
                    "b) Free Friday\n"
                    "\t\tAs a still unknown reason, Mr Verri tends to cancel the friday classes, letting our exhausted \n"
                    "\tstudents relax on fridays and regenerates 10hp.\n\n"

                    "2. Fritz and Rene\n\n"
                    "a) No test anymore\n"
                    "\t\tAfter a bunch of errors in the weekly tests, the ones made against the will of your heroes \n"
                    "\tFritz and Rene, they decided to cancel all the tests of the semester giving a humble score of\n"
                    "\t10 to all students of the hardest class in T27, the T2.\n\n"
                    "b) Fora de Forma\n\n"
                    "\t\tWhile others classes are summoned every week by their QUI-18 teachers in order to stay long \n"
                    "\thours in lab wasting energy, our heroic pair, Fritz and Rene, summons the T2 students weekly to \n"
                    "\tthe glorious “Fora de Forma, MARCHE!” after a long half hour which one quarter o hour is destinated\n"
                    "\tto the students Maju and Cristal to suck energy from our heroes.\n\n";
            break;
        case '4':
            // aqui colocar uma breve descrição das mecanicas do jogo
            break;
        case '5':
            os <<   "------------------------------------------------ End of Tutorial ------------------------------------------------\n";
            config_page();
            start = true;
            break;

    }
}

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
    std::array<std::string, 6u> character = {"Catatau", "Catabol", "Gripen", "Yu", "Nobili", "Lopes"};
    std::array<std::string, 3u> themes = {"MPG-03", "MAT-12", "QUIM-18"};
    std::array<Attack, 18u> attacks;
    attacks[0] = {"comp_comp", 30, 10};
    attacks[1] = {"full_nightlong", 30, 25, false, "Dizzy"};
    attacks[2] = {"tired_insane", 0, -30, false, "Sleepy"};
    attacks[3] = {"got_nothing", 15, 5};
    attacks[4] = {"when_end", 15, 5};
    attacks[5] = {"help_here", 15, 5};
    attacks[6] = {"always_ELE", 15, 5};
    attacks[7] = {"lets_go_to_DAE", 15, 5};
    attacks[8] = {"mat17_intankable", 15, 5};
    attacks[9] = {"hole_your_xxx", 25, 0, true};
    attacks[10] = {"see_norm", 15, 5};
    attacks[11] = {"disconnect_ITA", 30, 10, false, "None", false, true};
    attacks[12] = {"no_class", 15, -20};
    attacks[13] = {"counter_example", 25, 5};
    attacks[14] = {"nobili_3attack", 15, 5};
    attacks[15] = {"HaveFun", 15, -5};
    attacks[16] = {"AllSame", 10, 0, false, "Dizzy", true};
    attacks[17] = {"lopes_3attack", 15, 5};
    for(std::size_t i = 0u; i < 6u; ++i){
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
    for(std::size_t i = 0u; i < 2u; i++){
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
        potions_type.push_back(_potion_type);
    }
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
        os << "Ok! I will need the following informations:\n The name of the character, the theme of the character(if students None) and three attacks described by name, damage dealt, damage taken, if it is in percentage, change the status of the character, if this effect is in the enemy and if this attack is an execute.\n";
        os << " The boolean informations enter 0 for false and 1 for true, you can use negative numbers to heal, the percentage will be only used in the damage dealt and the status change can be None, Dizzy or Sleepy.\n";
        is >> new_character.name >> new_character.theme;
        for(std::size_t i = 0; i < 3u; i++){
            is >> new_character.attack[i].move >> new_character.attack[i].make_tired >> new_character.attack[i].get_tired >> new_character.attack[i].percentage >>
            new_character.attack[i].status_change >> new_character.attack[i].change_enemy >> new_character.attack[i].execute;
        }
        characters.push_back(new_character);
    }else{
        os << "Ok! Which one do you want to delete?\n";
        for(std::size_t i = 0; i < characters.size(); i++){
            os << i+1 << ". " << characters[i].name << ((i%3 == 2)? '\n' : ' ');
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
        os << "The boolean informations enter 0 for false and 1 for true.\n";
        is >> new_potion.name;
        for(std::size_t i = 0; i < 3u; i++){
            is >> new_potion.potion[i].potion_name >> new_potion.potion[i].rest;
        }
        potions_type.push_back(new_potion);
    }else{
        os << "Ok! Which one do you want to delete?\n";
        for(std::size_t i = 0; i < potions_type.size(); i++){
            os << i+1 << ". " << potions_type[i].name << ((i%3 == 2)? '\n' : ' ');
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
    bool pass_round_s = false, pass_round_p = false, end_fight = false, professor_turn = false;
    while(true){
        if(professor_turn){
            if(pass_round_p){
                pass_round_p = false;
                professor.status = Status::Smooth;
            }
            else{
                pass_round_p = true;
            }
            ai_attack(students, professor);
            end_fight = fight_end(students, professor);
            display_tired(students, professor);
            professor_turn = false;
        }
        else{
            std::size_t choosen_student = choose_student(students);
            if(students[choosen_student].status == Status::Dizzy || students[choosen_student].status == Status::Sleepy){
                if(pass_round_s){
                    pass_round_s = false;
                    students[choosen_student].status = Status::Smooth;
                }
                else{
                    pass_round_s = true;
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
        for(std::size_t j = 0; j < students.size(); j++){
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
            attack_move(students[_choosen_student], professor, students[_choosen_student].attack[2]);
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
        for(std::size_t i = 0; i < potions_type.size(); i++){
            os << i+1 << ". " << potions_type[i].name << (i == potions_type.size()-1 ? "\n" : " | ");
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
    for(std::size_t i = 0; i < students.size(); i++){
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
    stage << "eos\n";
    for(std::size_t i = 0u; i < professors.size(); ++i){
        std::string status = status_string(professors[i].status);
        stage << professors[i].name << ' ' << status << ' ' << professors[i].tired << ' ' << professors[i].theme << '\n';
        for(std::size_t j = 0; j < 3; j++){
            stage << professors[i].attack[j].move << ' ' << professors[i].attack[j].make_tired << ' ' << professors[i].attack[j].get_tired << ' ' <<
            professors[i].attack[j].percentage << ' ' << professors[i].attack[j].status_change << ' ' << professors[i].attack[j].change_enemy << ' ' <<
            professors[i].attack[j].execute << '\n';
        }
    }
    stage << "eop\n";
    std::cout << potions_type.size();
    for(std::size_t i = 0u; i < potions_type.size(); ++i){
        stage << potions_type[i].name << '\n';
        for(std::size_t j = 0u; j < 2; j++){
            stage << potions_type[i].potion[j].potion_name << ' ' << potions_type[i].potion[j].rest << ' ' << potions_type[i].potion[j].num_potions << '\n';
        }
    }
    stage.close();
    exit(0);
}
