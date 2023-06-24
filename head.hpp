#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <random>
#include <iomanip>
#include <string>


constexpr std::size_t NUM_STUDENTS = 3u;
constexpr std::size_t NUM_CHARACTERS = 6u;
constexpr std::size_t NUM_POTIONS = 2u;

enum class Status{
    Smooth,
    Tired,
    Dizzy,
    Sleepy
};

struct Attack {
    std::string move;
    int make_tired;
    int get_tired;
    bool percentage = false;
    std::string status_change = "None";
    bool change_enemy = false;
    bool execute = false;
};

struct Character {
    std::string name;
    Status status = Status::Smooth;
    Attack attack[3];
    int tired = 0;
    std::string theme = "None";
};

struct Potion{
    std::string potion_name;
    unsigned rest;
    unsigned num_potions = 3;
};

struct Potion_Type {
    std::string name;
    Potion potion[2];
};

std::fstream read_file(std::vector<Character>&, std::vector<Character>&, std::vector<Potion_Type>&, std::string&, std::ostream& = std::cout, std::istream& = std::cin);

void non_existent_file(std::fstream &, std::string);

void empty_file(std::fstream &, std::string);

void default_file(std::fstream&);

void load_stage(std::fstream &, std::string, std::vector<Character>&, std::vector<Character>&, std::vector<Potion_Type>&);

void load_character(std::fstream&, std::vector<Character>&, std::vector<Character>&);

Status string_status(std::string);

void load_potion(std::fstream&, std::vector<Potion_Type>&);

void change_characters_potions(std::vector<Character>&, std::vector<Character>&, std::vector<Potion_Type>&, std::ostream& = std::cout, std::istream& = std::cin);

void change_characters(std::vector<Character>&, std::ostream& = std::cout, std::istream& = std::cin);

void change_potions(std::vector<Potion_Type>&, std::ostream& = std::cout, std::istream& = std::cin);

void start_game(std::vector<Character>&, std::vector<Character>&, std::vector<Potion_Type>&, std::fstream&, std::string&);

void fight(std::vector<Character>&, Character&, std::vector<Potion_Type>&, bool&);

void ai_attack(std::vector<Character>&, Character&);

int can_kill(Character&, int);

void attack_move(Character&, Character&, Attack, std::ostream& = std::cout);

bool fight_end(std::vector<Character>&, Character&);

void display_tired(std::vector<Character>&, Character&, std::ostream& = std::cout);

unsigned name_lenght(std::vector<Character>&, Character&);

std::string make_bar (int);

std::string status_string(Status);

std::size_t choose_student(std::vector<Character>&, std::istream& = std::cin, std::ostream& = std::cout);

void make_move(std::vector<Character>&, Character&, std::vector<Potion_Type>&, std::size_t, bool&, std::istream& = std::cin, std::ostream& = std::cout);

void display_options(Character&, std::ostream& = std::cout);

bool has_potions(std::vector<Potion_Type>&, bool = true, std::size_t = 0);

void potion_type_options(std::vector<Character>&, std::vector<Potion_Type>&, std::istream& = std::cin, std::ostream& = std::cout);

void potion_options(std::vector<Character>&, Potion_Type&, std::ostream& = std::cout);

std::size_t display_potions(Potion_Type&, std::ostream& = std::cout, std::istream& = std::cin);

std::string potion_bar(Potion&);

bool display_result(std::vector<Character>&, Character&, std::ostream& = std::cout);

void save_and_quit(std::fstream&, std::string, std::vector<Character>&, std::vector<Character>&, std::vector<Potion_Type>&);