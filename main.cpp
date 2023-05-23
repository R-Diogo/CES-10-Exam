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
    Potion, //tem q implementar q so tem uma quantidade fixa de poções
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
    see_norm,
    hole_your_xxx,
    disconnect_ITA,
    forgot_key,
    friday_no_office_hour,
    test_worth_12,
    theory_important,
    test_easy,
    no_need_calculate ,
};

struct Character {
    std::string name;
    Job job;
    Status status;
    Movement moves[3];
    int tired;
};

Character load_character(std::fstream&);

void attack_move(Movement);

void make_move(Character);

void ai_attack(Character, Character, Character, Character);

void fight(Character, Character, Character, Character, bool);

int main(){
    //mano eu demorei um seculo para achar q tinha q por o struct no começo (mad :X)
    struct Character catatau = {
        "Catatau", Job::Strenuous, Status::Smooth,{Movement::comp_comp,Movement::full_nightlong, Movement::tired_insane}, 0};
    struct Character catabol = {
        "Catabol", Job::Median, Status::Smooth,{}, 0};
    struct Character gripen = {
        "Gripen", Job::Going, Status::Smooth,{Movement::gonna_quit}, 0};
    struct Character yu = {
        "Yu", Job::Going, Status::Smooth,{Movement::see_norm, Movement::hole_your_xxx, Movement::disconnect_ITA}, 0};
    struct Character nobili = {
        "Nobili", Job::Strenuous, Status::Smooth,{Movement::theory_important, Movement::test_easy, Movement::no_need_calculate}, 0};
    struct Character jenlo = {
        "Jennifer Lopes", Job::Strenuous, Status::Smooth,{Movement::see_norm, Movement::test_easy}, 0};
    struct Character verri = {
        "Verri", Job::Median, Status::Smooth,{Movement::forgot_key, Movement::friday_no_office_hour, Movement::test_worth_12}, 0};
    struct Character fritz_rene = {
        "Fritz and Rene", Job::Potion, Status::Smooth,{}, 0};
    std::array<Character,9> all_characters={
        gripen, catatau, catabol, yu, nobili, jenlo, verri, fritz_rene};
    std::string file_name;
    std::cout<<"Enter a valid file with your current safe stage (if you don't have one enter None):\n";
    std::cin>>file_name;
    std::fstream file(file_name, std::ios::in);
    //eu to em duvida ainda com usa o file na função, tipo se toda vez que eu chamo a função ele reabre ou continua da onde parou
    for(int i=0;i<9;i++){
        all_characters[i]=load_character(file);
    }
    bool professor_turn; //tem que pegar isso do arquivo tambem
    if(yu.status != Status::Tired){
        fight(yu, catatau, catabol, gripen, professor_turn);
    }
    if(nobili.status != Status::Tired){
        fight(nobili, catatau, catabol, gripen, professor_turn);
    }
    if(jenlo.status != Status::Tired){
        fight(jenlo, catatau, catabol, gripen, professor_turn);
    }
    return 0;
}

Character load_character(std::fstream& _file){
    //minha ideia é colocar no arquivo tipo:
    //Catatau Status(ai tem q add os status sonolento etc) vida
    //ai com base nos professores que a gente leu a gente ja sabe o stage que a gente ta
    //tipo se um professor morreu a gente n ta nesse stage 
}
void fight(Character _professor, Character _catatau, Character _catabol, Character _gripen, bool _professor_turn){
    while(true){
        if(_professor_turn){
            ai_attack(_professor, _catatau, _catabol, _gripen);
            //ta sugou, ainda tenho q pensar como implementar, pq a função tem que alterar a vida de mais de um player
        }
        else{
            if(_catatau.status==Status::Smooth){
                make_move(_catatau);
                //acho q eu vou mudar para retornar o dano q deu no professor
            }
            //... para os outros
        }
    }
}

void attack_move(Movement _attack){
    switch(_attack){
        case Movement::got_nothing:
            //fazer o que faz
        //add os outros
    }
}
void make_move(Character _character){
    int attack_choice;
    //implementar bagui pra ver as opções
    std::cin>>attack_choice;
    switch (attack_choice){
        case 1:
            attack_move(_character.moves[0]);
            break;
        case 2:
            attack_move(_character.moves[1]);
            break;
        case 3:
            attack_move(_character.moves[2]);
            break;
        //adicionar mais coisas tipo sair usar poção etc (mais pro final)
    }
}