#include <iostream>
#include <fstream>
#include <array>
#include <random>
#include <iomanip>


constexpr std::size_t NUM_STUDENTS = 3u;
constexpr std::size_t NUM_CHARACTERS = 6u;
constexpr std::size_t NUM_POTIONS = 2u;


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
    Job job;
    Status status;
    Attack attack[3];
    int tired;
};

struct Potion{
    std::string potion_name;
    unsigned rest;
    unsigned num_potions;
};

struct Potion_Type {
    std::string name;
    Potion potion[2];
};

std::fstream read_file(std::array<Character, NUM_CHARACTERS>&, std::array<Potion_Type, NUM_POTIONS>&, std::string&, std::ostream& = std::cout, std::istream& = std::cin);

void non_existent_file(std::fstream &, std::string);

void empty_file(std::fstream &, std::string);

void default_file(std::fstream&);

void load_stage(std::fstream &, std::string, std::array<Character, NUM_CHARACTERS>&, std::array<Potion_Type, NUM_POTIONS>&);

void load_character(std::fstream&, std::array<Character, NUM_CHARACTERS>&);

Status string_status(std::string);

void load_potion(std::fstream&, std::array<Potion_Type, NUM_POTIONS>&);

void start_game(std::array<Character, NUM_CHARACTERS>&, std::array<Potion_Type, NUM_POTIONS>&, std::fstream&, std::string&);

void fight(std::array<Character, NUM_CHARACTERS>&, std::array<Potion_Type, NUM_POTIONS>&, bool&, size_t, bool&);

void ai_attack(std::array<Character, NUM_CHARACTERS>&, std::size_t);

int can_kill(Character, int);

void attack_move(Character&, Character&, int, std::ostream& = std::cout);

bool fight_end(std::array<Character, NUM_CHARACTERS>&, size_t);

void display_tired(std::array<Character, NUM_CHARACTERS>, size_t, std::ostream& = std::cout);

unsigned name_lenght(std::array<Character, NUM_CHARACTERS>);

std::string make_bar (int);

std::string status_string(Status);

std::size_t choose_student(std::array<Character, NUM_CHARACTERS>, std::istream& = std::cin, std::ostream& = std::cout);

void make_move(std::array<Character, NUM_CHARACTERS>&, Character&, std::array<Potion_Type, NUM_POTIONS>&, bool&, std::size_t, std::istream& = std::cin, std::ostream& = std::cout);

void display_options(Character, std::ostream& = std::cout);

bool has_potions(std::array<Potion_Type, NUM_POTIONS>, int = -1);

void potion_type_options(std::array<Character, NUM_CHARACTERS>&, std::array<Potion_Type, NUM_POTIONS>&, std::istream& = std::cin, std::ostream& = std::cout);

void potion_options(std::array<Character, NUM_CHARACTERS>&, Potion_Type&, std::ostream& = std::cout);

std::size_t display_potions(Potion_Type, std::ostream& = std::cout, std::istream& = std::cin);

std::string potion_bar(Potion);

void display_result(std::array<Character, NUM_CHARACTERS>, std::size_t, std::ostream& = std::cout);

void save_and_quit(std::fstream&, std::string, std::array<Character, NUM_CHARACTERS>&, std::array<Potion_Type, NUM_POTIONS>& );