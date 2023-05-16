#include <iostream>
#include <fstream>
#include <array>
#include <random>

void save_stage(std::array<int, 6> _health){
    std::fstream file("save_progress.txt", std::ios::out | std::ios::trunc);
    for(int i=0;i<6;i++){
        file<<_health[i]<<' ';
    }
}

int main(){
    std::array<int, 6> health={10,20,30,40,50,60};
    save_stage(health);
}