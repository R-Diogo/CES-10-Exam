#include <iostream>
#include <fstream>
#include <array>
#include <random>
#include <map>

enum class Job {
    Going,
    Strenuous,
    Median,
};

struct Stats {
    int poder_gaga;
    int mela_aula;
};

enum class Status {
    Smooth,
    Tired,
};

enum class Attacks : int{
    got_nothing = 11,
    what_times_ends = 12,
    help_me = 13,
    want_comp = 21,
    full_nightlong = 22,
    always_went_for_ELE = 31,
    gonna_quit = 32,
    gonna_see_the_norm = 41,
    hole_your_xxx = 42,
    disconnect_ITA = 43,
    forgot_key = 51,
    friday_no_office_hour = 52,
    test_worth_12 = 53,
    theory_important = 61,
    test_easy = 62,
    no_need_calculate = 63,
};

struct Character {
    std::string name;
    Job job;
    Stats stats;
    Status status;
    Attacks attacks[3];
};

void attack_move(Attacks _attack){
    switch(_attack){
        case Attacks::got_nothing:
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
            attack_move(_character.attacks[0]);
            break;
        case 2:
            attack_move(_character.attacks[1]);
            break;
        case 3:
            attack_move(_character.attacks[2]);
            break;
        //adicionar mais coisas tipo sair usar poção etc (mais pro final)
    }
}
//implementar quem começa
void first_fight(Character _verri, Character _gripen, Character _catatau, Character _catabol){
    while(true){

    }
}

int main(){
    Character gripen = {
        "Gripen", Job::Going, {100, 10}, Status::Smooth,{Attacks::always_went_for_ELE, Attacks::gonna_quit}};

    Character catatau = {
        "Catatau", Job::Strenuous, {10, 100}, Status::Smooth,{Attacks::want_comp,Attacks::full_nightlong}};

    Character catabol = {
        "Catabol", Job::Median, {10, 10}, Status::Smooth,{Attacks::got_nothing, Attacks::what_times_ends, Attacks::help_me}};

    Character yu = {
        "Yu", Job::Going, {80, 20}, Status::Smooth,{Attacks::gonna_see_the_norm, Attacks::hole_your_xxx, Attacks::disconnect_ITA}};

    Character verri = {
        "Verri", Job::Median, {70, 30}, Status::Smooth,{Attacks::forgot_key, Attacks::friday_no_office_hour, Attacks::test_worth_12}};

    Character nobili = {
        "Nobili", Job::Strenuous, {40, 60}, Status::Smooth,{Attacks::theory_important, Attacks::test_easy, Attacks::no_need_calculate}};
    
    return 0;
}