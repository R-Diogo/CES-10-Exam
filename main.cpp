#include <iostream>
#include <fstream>
#include <array>
#include <random>

std::size_t constexpr NUM_STUDENTS = 3u;
std::size_t constexpr NUM_CHARACTERS = 6u;
std::size_t constexpr NUM_POTIONS = 2u;

enum class Job {
    Going,
    Strenuous,
    Median,
    Professor,
};

enum class Status{
    Smooth,
    Tired,
    Dizzy,
    Sleepy
};

enum class Movement{
    comp_comp,
    full_nightlong,
    tired_insane,
    got_nothing,
    when_end,
    help_here,
    always_ELE,
    gonna_quit,
    gripen_3attack,
    hole_your_xxx,
    see_norm,
    disconnect_ITA,
    no_class,
    counter_example,
    nobili_3attack,
    lopes_1attack,
    lopes_2attack,
    lopes_3attack,
};

enum class Potion_Type{
    no_key,
    friday_no_class,
    no_chem_test,
    way_back_home,
};

struct Attack {
    Movement move;
    int make_tired;
    int get_tired;
    bool percentage = false;
    std::string status_change = "None";
};

struct Character {
    std::string name;
    Job job;
    Status status;
    Attack attack[3];
    int tired;
};

struct Potion {
    std::string name;
    Potion_Type potion_type[2];
    int num_potions[2];
};

void empty_or_non_existent_file(std::fstream &, std::string);

void default_file(std::fstream&);

void load_stage(std::fstream &, std::string, std::array<Character, NUM_CHARACTERS>&, std::array<Potion, NUM_POTIONS>&);

void load_character(std::fstream&, std::array<Character, NUM_CHARACTERS>&);

Status string_status(std::string);

void load_potion(std::fstream&, std::array<Potion, NUM_POTIONS>&);

void fight(std::array<Character, NUM_CHARACTERS>&, bool&, size_t, bool&);

void ai_attack(std::array<Character, NUM_CHARACTERS>&, std::size_t);

int can_kill(Character, int);

void make_move(Character&, Character&, bool&);

void display_attack(std::string, Movement, std::string, std::ostream& = std::cout);

void display_tired(std::array<Character, NUM_CHARACTERS>, size_t, std::ostream& = std::cout);

bool move_end(std::array<Character, NUM_CHARACTERS>&, size_t);

void display_options(Character, std::ostream& = std::cout);

void attack_move(Character&, Character&, int);

void save_and_quit(std::fstream&, std::string, std::array<Character, NUM_CHARACTERS>&, std::array<Potion, NUM_POTIONS>& );

std::string status_string(Status);


int main(){
    std::array<Character, NUM_CHARACTERS> characters;
    std::array<Potion, NUM_POTIONS> potions;
    std::string file_name;

    std::cout << "Enter a valid file with your current safe stage (if you don't have one enter one you would like to create):\n";
    std::cin >> file_name;
    std::fstream stage(file_name);
    
    //não ta funcionando quando coloca um file não vazio.
    empty_or_non_existent_file(stage, file_name);
    load_stage(stage, file_name, characters, potions);

    bool save_quit = false;
    for(std::size_t i = NUM_STUDENTS; i < NUM_CHARACTERS; i++){
        bool professor_turn = false;
        if(characters[i].status != Status::Tired){
            fight(characters, professor_turn, i, save_quit);
            if(save_quit){
                save_and_quit(stage, file_name, characters, potions);
            }
        }
    }
    return 0;
}

void empty_or_non_existent_file(std::fstream &file, std::string _file_name){
        file.open(_file_name, std::ios::in);
        if(!file){
            file.clear();
            file.open(_file_name, std::ios::out | std::ios::trunc);
            default_file(file);  
        }
        if(std::string test; !(file >> test)){
            file.clear();
            file.close();
            std::fstream file(_file_name, std::ios::out | std::ios::trunc);
            default_file(file);  
        }
        file.close();
}

void default_file (std::fstream &_stage){
    std::array< std::string, NUM_CHARACTERS> character = {"Catatau", "Catabol", "Gripen", "Yu", "Nobili", "Lopes"};
    for(std::size_t i = 0u; i < NUM_CHARACTERS; ++i){
        _stage << character[i] << " Smooth 0\n";
    }
    std::array <std::string, 2> potion = {"Verri", "Fritz_Rene"};
    for(std::size_t i = 0u; i < NUM_POTIONS; i++){
        _stage << potion[i] << " 3 3\n";
    }  
}

void load_stage(std::fstream &_stage, std::string _file_name, std::array<Character, NUM_CHARACTERS>& _characters, std::array<Potion, NUM_POTIONS>& _potions ){
    _stage.open(_file_name, std::ios::in);
    load_character(_stage, _characters);
    load_potion(_stage, _potions);
    _stage.close();
}

void load_character(std::fstream& _stage, std::array<Character, NUM_CHARACTERS>& _character){
    std::string _name, _stats;
    int _tired;
    for(std::size_t i = 0u; i < NUM_CHARACTERS; i++){
        _stage >> _name >> _stats >> _tired;
        Status _status = string_status(_stats);

        if(_name == "Catatau"){
            _character[i] = {
            "Catatau", Job::Strenuous, _status,{
                {Movement::comp_comp, 15, 5}, {Movement::full_nightlong, 30, 25, false, "Dizzy"}, {Movement::tired_insane, 0, -30, true, "Sleepy"}}, _tired}; 
        }
        else if(_name == "Catabol"){
            _character[i] = {
            "Catabol", Job::Going, _status,{
                {Movement::got_nothing, 15, 5}, {Movement::when_end, 15, 5}, {Movement::help_here, 15, 5}}, _tired};  
        }
        else if(_name == "Gripen"){
            _character[i] = {
            "Gripen", Job::Median, _status,{
                {Movement::gonna_quit, 15, 5}, {Movement::always_ELE, 15, 5}, {Movement::gripen_3attack, 15, 5}}, _tired};
        }
        else if(_name == "Yu"){
            _character[i] = {
            "Yu", Job::Professor, _status,{
                {Movement::hole_your_xxx, 15, 5, true}, {Movement::see_norm, 15, 5}, {Movement::disconnect_ITA, 15, 5}}, _tired};
        }
        else if(_name == "Nobili"){
            _character[i] = {
            "Nobili", Job::Professor, _status,{
                {Movement::no_class, 15, 5}, {Movement::counter_example, 15, 5}, {Movement::nobili_3attack, 15, 5}}, _tired};
        }
        else{
            _character[i] = {
            "Lopes", Job::Professor, _status,{
                {Movement::lopes_1attack, 15, 5}, {Movement::lopes_2attack, 15, 5}, {Movement::lopes_3attack, 15, 5}}, _tired};
        }
    }
}

Status string_status(std::string _stats){
    if(_stats == "Smooth") return Status::Smooth;
    else if(_stats == "Tired") return Status::Tired;
    else if(_stats == "Dizzy") return Status::Dizzy;
    else if(_stats == "Sleepy") return Status::Sleepy;
}

void load_potion(std::fstream& _stage, std::array<Potion, NUM_POTIONS>& _potion){
    std::string _potion_name;
    int num_potion1, num_potion2;
    for(std::size_t i = 0u; i < NUM_POTIONS; i++){
        _stage >> _potion_name >> num_potion1 >> num_potion2;
        if(_potion_name == "Verri"){
            _potion[i] = {"Verri", {Potion_Type::no_key, Potion_Type::friday_no_class}, {num_potion1, num_potion2}};
        }
        else if(_potion_name == "Fritz_Rene"){
            _potion[i] = {"Fritz_Rene", {Potion_Type::no_chem_test, Potion_Type::way_back_home}, {num_potion1, num_potion2}};
        }
    }
}

void fight(std::array<Character, NUM_CHARACTERS> &_characters, bool &_professor_turn, std::size_t num_professor, bool &_save_quit){
    bool passed_round = false;
    bool end_fight = false;
    while(true){
        if(_professor_turn){
            ai_attack(_characters, num_professor);
            display_tired(_characters, num_professor);
            end_fight = move_end(_characters, num_professor);
            _professor_turn = false;
        }
        else{
            int make_tired = 0, get_tired = 0;
            for(std::size_t j = 0u; j < NUM_STUDENTS; j++){
                if(_characters[j].status == Status::Smooth){
                    make_move(_characters[j], _characters[num_professor], _save_quit);
                    display_tired(_characters, num_professor);
                    end_fight = move_end(_characters, num_professor);
                    if(end_fight || _save_quit) break;
                }
                else if(_characters[j].status != Status::Tired){
                    if(passed_round){
                        passed_round = false;
                        _characters[j].status = Status::Smooth;
                    }
                    else{
                        passed_round=true;
                    }
                }
            }
            _professor_turn = true;
        }
        if(end_fight || _save_quit) break;
    }
}

void ai_attack(std::array<Character, NUM_CHARACTERS>& _characters, std::size_t num_professor){
    int max_tired_student = 0;
    std::size_t aux = 0;
    for(std::size_t i = 0u; i < NUM_STUDENTS; ++i){
        if(_characters[i].tired > max_tired_student && _characters[i].status != Status::Tired){
            max_tired_student = _characters[i].tired;
            aux = i;
        }
    }
    int movement = can_kill(_characters[num_professor], max_tired_student);
    if(movement != -1){
        attack_move(_characters[num_professor], _characters[aux], movement);
        display_attack(_characters[num_professor].name, _characters[num_professor].attack[movement].move, _characters[aux].name);
    }
    else{
        Character possible_students[NUM_STUDENTS] = {};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::size_t position_array=0;
        for(std::size_t j=0; j<NUM_STUDENTS; j++){
            if(_characters[j].status != Status::Tired){
                possible_students[position_array] = _characters[j];
                position_array++;
            }
        }
        std::uniform_int_distribution<> distr_student(0,position_array-1);
        std::uniform_int_distribution<> distr_attack(0,2);
        std::size_t num_student = distr_student(gen), num_attack = distr_attack(gen);
        attack_move(_characters[num_professor], possible_students[num_student], num_attack);
        display_attack(_characters[num_professor].name, _characters[num_professor].attack[num_attack].move, possible_students[num_student].name);
    }
            //aqui quero ver qual o ataque mais forte entre os professores vivos
            //a ideia é que  se a IA pode eliminar um aluno, ela vai
            // daí o professor com o ataque mais potente ataca o aluno mais cansado
            //o aluno mais cansado é determinado no loop anterior
            //só não consegui achar o ataque mais potente ainda pq ele não é armazenado no próprio personagem aparentemente
}

int can_kill(Character _professor, int max_tired_student){
    int max_tired = 0;
    int attack_number;
    for(std::size_t i=0; i<3u; i++){
        int make;
        auto _attack = _professor.attack[i];
        if(_attack.percentage){
            make = (100 - max_tired_student)*_attack.make_tired;
            if(make > max_tired){
                max_tired = make;
                attack_number = i;
            }
        }
        else{
            make = _attack.make_tired;
            if(make > max_tired){
                max_tired = make;
                attack_number = i;
            }
        }
    }
    if(max_tired_student + max_tired >= 100) return attack_number;
    else return -1;
}

void display_attack(std::string name_dealer, Movement move, std::string name_taker, std::ostream& os){
    os << name_taker << " got more tired because of " << name_dealer << " " /*<< move */<< "movement\n";
}

void make_move(Character &_character, Character &_professor, bool &_save_quit){
    char attack_choice;
    display_options(_character);
    std::cin >> attack_choice;
    switch (attack_choice){
        case '1':
            attack_move(_character, _professor, 0);
            break;
        case '2':
            attack_move(_character, _professor, 1);
            break;
        case '3':
            attack_move(_character, _professor, 2);
            break;
        case '4':
            //implementar usar poção
            break;
        case '5':
            _save_quit = true;
            break;
    }
}

void display_options(Character _character, std::ostream& os){
    os << "Choose an option:\n";
    if(_character.name == "Catatau"){
        os << "1. comp_comp | 2. full_nightlong | 3. tired_insane | ";
    } else if(_character.name == "Gripen"){
        os << "1. always_ELE | 2. gonna_quit | 3. gripen_3attack | ";
    } else if(_character.name == "Catabol"){
        os << "1. got_nothing | 2. when_end | 3. help_here | ";
    }
    os << "4. Potion | 5. Save and Quit\n";
}

void attack_move(Character &_character_dealer, Character &_character_taker, int attack_num){
    auto _attack = _character_dealer.attack[attack_num];
    if(_attack.status_change != "None"){
        _character_dealer.status = string_status(_attack.status_change);
    }
    if(_attack.percentage){
        _character_taker.tired += ((100-_character_taker.tired)*_attack.make_tired)/100;
    }else{
        _character_taker.tired += _attack.make_tired;
    }
    _character_dealer.tired += _attack.get_tired;
}

void display_tired(std::array<Character, NUM_CHARACTERS> _characters, std::size_t num_professor, std::ostream& os){
    for(std::size_t i=0; i<NUM_STUDENTS; i++){
        os << _characters[i].name << " is " << _characters[i].tired << " '%' tired\n";
    }
    os << _characters[num_professor].name << " is " << _characters[num_professor].tired << " '%' tired\n";
}

bool move_end(std::array<Character, NUM_CHARACTERS>& _characters, std::size_t num_professor){
    unsigned num_tired = 0;
    for(std::size_t i=0; i<NUM_STUDENTS; i++){
        if(_characters[i].tired >= 100) num_tired++;
    }
    if(_characters[num_professor].tired >= 100 || num_tired == NUM_STUDENTS) return true;
    else return false;
}

void save_and_quit(std::fstream &_stage, std::string _file_name, std::array<Character, NUM_CHARACTERS>& _characters, std::array<Potion, NUM_POTIONS>& _potions){
    _stage.open(_file_name, std::ios::out | std::ios::trunc);
   
    for(std::size_t i = 0u; i < NUM_CHARACTERS; ++i){
        std::string status = status_string(_characters[i].status);
        _stage << _characters[i].name << ' ';
        _stage << status << ' ';
        _stage << _characters[i].tired << '\n';
    }
    for(std::size_t i = 0u; i < NUM_POTIONS; ++i){
        _stage << _potions[i].name << ' ';
        _stage << _potions[i].num_potions[0] << ' ';
        _stage << _potions[i].num_potions[1] << '\n';
    }
    _stage.close();
    exit(0);
}

std::string status_string(Status _status){
    if(_status == Status::Smooth) return "Smooth";
    else if(_status == Status::Tired) return "Tired";
    else if(_status == Status::Dizzy) return "Dizzy";
    else return "Sleepy";
}