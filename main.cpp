#include <iostream>
#include <fstream>
#include <array>
#include <random>
#include <map>


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


struct Character {
    std::string name;
    Job job;
    Status status;
    Movement moves[3];
    int tired;
};


struct Potion {
    std::string name;
    Potion_Type potion_type[2];
    int num_potions[2];
};


void load_character(std::fstream&, std::array<Character, 6>&);


void load_potion(std::fstream&, std::array<Potion, 2>&);


Status string_status(std::string);


void display(Character);


void attack_move(Movement, int&, int&);


void make_move(Character, int&, int&);


void ai_attack(Character, Character, Character, Character);


void fight(std::array<Character, 6>, bool, int);


void default_file(std::fstream&);


int main(){
    std::array<Character, 6> characters;
    std::array<Potion, 2> potions;
    std::string file_name;
    std::cout << "Enter a valid file with your current safe stage (if you don't have one enter one you would like to create):\n";
    std::cin >> file_name;
    std::fstream stage(file_name, std::ios::in);


    if(!stage){
        stage.clear();
        stage.open(file_name, std::ios::out | std::ios::trunc);
        default_file(stage);        
        stage.close();
    }
   
    if(std::string test; !(stage >> test)){
        stage.clear();
        stage.close();
        std::fstream stage(file_name, std::ios::out | std::ios::trunc);
        default_file(stage);  
        stage.close();    
    }


    stage.open(file_name, std::ios::in);
    load_character(stage, characters);
    load_potion(stage, potions);
       
    //ta funcionando o load_character mas tem q deixar melhor eu acho
    bool professor_turn=false;


    for(int i=3;i<6;i++){
        if(characters[i].status!=Status::Tired){
            fight(characters, professor_turn, i);
        }
    }
    return 0;
}


Status string_status(std::string _stats){
    if(_stats == "Smooth") return Status::Smooth;
    else if(_stats == "Tires") return Status::Tired;
    else if(_stats == "Dizzy") return Status::Dizzy;
}


void load_character(std::fstream& _stage, std::array<Character, 6>& _character){
    std::string _name, _stats;
    int _tired;
    for(int i = 0; i < 6; i++){
        _stage >> _name >> _stats >> _tired;
        Status _status = string_status(_stats);
        if(_name == "Catatau"){
            _character[i] = {
            "Catatau", Job::Strenuous, _status, {Movement::comp_comp, Movement::full_nightlong, Movement::tired_insane}, _tired};
        }
        else if(_name == "Catabol"){
            _character[i] ={
            "Catabol", Job::Going, _status,{Movement::got_nothing, Movement::when_end, Movement::help_here}, _tired};  
        }
        else if(_name == "Gripen"){
            _character[i]={
            "Gripen", Job::Median, _status,{Movement::gonna_quit, Movement::always_ELE, Movement::gripen_3attack}, _tired};
        }
        else if(_name == "Yu"){
            _character[i]={
            "Yu", Job::Professor, _status,{Movement::hole_your_xxx, Movement::see_norm, Movement::disconnect_ITA}, _tired};
        }
        else if(_name == "Nobili"){
            _character[i]={
            "Nobili", Job::Professor, _status,{Movement::no_class, Movement::counter_example, Movement::nobili_3attack}, _tired};
        }
        else{
            _character[i] = {
            "Lopes", Job::Professor, _status,{Movement::lopes_1attack, Movement::lopes_2attack, Movement::lopes_3attack}, _tired};
        }
    }
}


void load_potion(std::fstream& _stage, std::array<Potion, 2>& _potion){
    std::string _potion_name;
    int num_potion1, num_potion2;
    for(int i = 0; i < 2; i++){
        _stage >> _potion_name >> num_potion1 >> num_potion2;
        if(_potion_name == "Verri"){
            _potion[i] = {"Verri", {Potion_Type::no_key, Potion_Type::friday_no_class}, {num_potion1, num_potion2}};
        }
        else{
            _potion[i] = {"Fritz_Rene",{Potion_Type::no_chem_test, Potion_Type::way_back_home}, {num_potion1, num_potion2}};
        }
    }
}


void fight(std::array<Character,6> _characters, bool _professor_turn, int num_professor){
    while(true){
        if(_professor_turn){
            //ai_attack(_professor, _catatau, _catabol, _gripen);
            //ta sugou, ainda tenho q pensar como implementar, pq a função tem que alterar a vida de mais de um player
            _professor_turn=false;
        }
        else{
            int make_tired = 0, get_tired = 0;
            for(int j=0; j<3; j++){
                if(_characters[0].status == Status::Smooth){
                    make_move(_characters[0], make_tired, get_tired);
                    _characters[num_professor].tired += make_tired;
                    _characters[0].tired += get_tired;
                }
            }
            _professor_turn = true;
        }
    }
}


void attack_move(Movement _attack, int& _make, int& _get){
    switch(_attack){
        case Movement::comp_comp:
            _make = 15;
            _get = 5;
            break;
        case Movement::full_nightlong:
            _make = 25;
            _get = 30;
            break;
        case Movement::tired_insane:
            _get = -30;
            break;
        //add os outros
    }
}
void make_move(Character _character, int& make, int& get){
    char attack_choice;
    display(_character);
    std::cin >> attack_choice;
    switch (attack_choice){
        case '1':
            attack_move(_character.moves[0], make, get);
            break;
        case '2':
            attack_move(_character.moves[1], make, get);
            break;
        case '3':
            attack_move(_character.moves[2], make, get);
            break;
        case '4':


            break;
        case '5':


            break;
        //adicionar mais coisas tipo sair usar poção etc (mais pro final)
    }
}


void display(Character _character){
    std::cout << "Choose an option:\n";
    if(_character.name == "Catatau"){
        std::cout << "1. comp_comp | 2. full_nightlong | 3. tired_insane | ";
    } else if(_character.name == "Gripen"){
        std::cout << "1. always_ELE | 2. gonna_quit | 3. gripen_3attack | ";
    } else if(_character.name == "Catabol"){
        std::cout << "1. got_nothing | 2. when_end | 3. help_here | ";
    }
    std::cout << "4. Potion | 5. Save and Quit\n";
}


void save_and_quit(std::fstream &_stage, std::string file_name){
    std::fstream _stage(file_name, std::ios::out | std::ios::trunc);
   
}


void default_file (std::fstream &_stage){
    std::array< std::string, 6u> character = {"Catatau", "Catabol", "Gripen", "Yu", "Nobili", "Lopes"};
    for(std::size_t i = 0u; i < 6u; ++i){
        _stage << character[i] << " Smooth 0\n";
    }
        _stage << "Verri 3 3\n";
        _stage << "Fritz_Rene 3 3\n";    
}
