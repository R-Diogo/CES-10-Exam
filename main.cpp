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
    renefritz_1potion,
    renefritz_2potion,
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

void load_potion(std::fstream&, Potion&);

Status string_status(std::string);

void display(Character);

void attack_move(Movement, int&, int&);

void make_move(Character, int&, int&);

void ai_attack(Character, Character, Character, Character);

void fight(Character, Character, Character, Character, bool);

int main(){
    std::array<Character, 6> characters;
    Potion verri, fritz_rene;
    std::string file_name;
    std::cout<<"Enter a valid file with your current safe stage (if you don't have one enter one you would like to create):\n";
    std::cin>>file_name;
    std::fstream stage(file_name, std::ios::in);
    load_character(stage, characters);
    load_potion(stage, verri);
    load_potion(stage, fritz_rene);
    //ta funcionando o load_character mas tem q deixar melhor eu acho
    //tambem tem q fazer funcionar se n tiver nenhum arquivo previamente salvo
    bool professor_turn=false;
    if(characters[3].status != Status::Tired){
        fight(characters[3], characters[0], characters[1], characters[2], professor_turn);
    }
    if(characters[4].status != Status::Tired){
        fight(characters[4], characters[0], characters[1], characters[2], professor_turn);
    }
    if(characters[5].status != Status::Tired){
        fight(characters[5], characters[0], characters[1], characters[2], professor_turn);
    }
    return 0;
}

Status string_status(std::string _stats){
    if(_stats=="Smooth") return Status::Smooth;
    else if(_stats=="Tires") return Status::Tired;
    else if(_stats=="Dizzy") return Status::Dizzy;
}

void load_character(std::fstream& _stage, std::array<Character, 6>& _character){
    std::string _name, _stats;
    int _tired;
    for(int i=0;i<6;i++){
        _stage>>_name>>_stats>>_tired;
        Status _status = string_status(_stats);
        if(_name=="Catatau"){
            _character = {
            "Catatau", Job::Strenuous, _status, {Movement::comp_comp, Movement::full_nightlong, Movement::tired_insane}, _tired};
        }
        else if(_name=="Catabol"){
            _character ={
            "Catabol", Job::Going, _status,{Movement::got_nothing, Movement::when_end, Movement::help_here}, _tired};  
        }
        else if(_name=="Gripen"){
            _character={
            "Gripen", Job::Median, _status,{Movement::gonna_quit, Movement::always_ELE, Movement::gripen_3attack}, _tired};
        }
        else if(_name=="Yu"){
            _character={
            "Yu", Job::Professor, _status,{Movement::hole_your_xxx, Movement::see_norm, Movement::disconnect_ITA}, _tired};
        }
        else if(_name=="Nobili"){
            _character={
            "Nobili", Job::Professor, _status,{Movement::no_class, Movement::counter_example, Movement::nobili_3attack}, _tired};
        }
        else{
            _character={
            "Lopes", Job::Professor, _status,{Movement::lopes_1attack, Movement::lopes_2attack, Movement::lopes_3attack}, _tired};
        }
    }
}

void load_potion(std::fstream& _stage, Potion& _potion){
    std::string _potion_name;
    int num_potion1, num_potion2;
    _stage>>_potion_name>>num_potion1>>num_potion2;
    if(_potion_name=="Verri"){
        _potion={"Verri", {Potion_Type::no_key, Potion_Type::friday_no_class}, {num_potion1, num_potion2}};
    }
    else{
        _potion={"Fritz_Rene",{Potion_Type::renefritz_1potion, Potion_Type::renefritz_2potion}, {num_potion1, num_potion2}};
    }
}

void fight(Character _professor, Character _catatau, Character _catabol, Character _gripen, bool _professor_turn){
    while(true){
        if(_professor_turn){
            //ai_attack(_professor, _catatau, _catabol, _gripen);
            //ta sugou, ainda tenho q pensar como implementar, pq a função tem que alterar a vida de mais de um player
            _professor_turn=false;
        }
        else{
            int make_tired=0, get_tired=0;
            if(_catatau.status==Status::Smooth){
                make_move(_catatau, make_tired, get_tired);
                _professor.tired+=make_tired;
                _catatau.tired+=get_tired;
                std::cout<<"Yu is "<<_professor.tired<<" tired and Catatau is "<<_catatau.tired<<" tired\n";
            }
            if(_catabol.status==Status::Smooth){
                make_move(_catabol, make_tired, get_tired);
                _professor.tired+=make_tired;
                _catabol.tired+=get_tired;
            }
            if(_gripen.status==Status::Smooth){
                make_move(_gripen, make_tired, get_tired);
                _professor.tired+=make_tired;
                _catabol.tired+=get_tired;
            }
            _professor_turn=true;
        }
    }
}

void attack_move(Movement _attack, int& _make, int& _get){
    switch(_attack){
        case Movement::comp_comp:
            _make=15;
            _get=5;
            break;
        case Movement::full_nightlong:
            _make=25;
            _get=30;
            break;
        case Movement::tired_insane:
            _get=-30;
            break;
        //add os outros
    }
}
void make_move(Character _character, int& make, int& get){
    int attack_choice;
    display(_character);
    std::cin>>attack_choice;
    switch (attack_choice){
        case 1:
            attack_move(_character.moves[0], make, get);
            break;
        case 2:
            attack_move(_character.moves[1], make, get);
            break;
        case 3:
            attack_move(_character.moves[2], make, get);
            break;
        //adicionar mais coisas tipo sair usar poção etc (mais pro final)
    }
}

void display(Character _character){
    std::cout<<"Choose an option:\n";
    if(_character.name=="Catatau"){
        std::cout<<"1. comp_comp | 2. full_nightlong | 3. tired_insane | ";
    }
    std::cout<<"4. Potion | 5. Save and Quit\n";
}