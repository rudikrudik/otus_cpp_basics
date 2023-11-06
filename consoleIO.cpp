#include <iostream>


static std::string red = "\033[91m";
static std::string green = "\033[32m";
static std::string bold = "\033[1m";
static std::string standart = "\033[0m";

void printHello(){
    std::cout << bold << "Hi! Enter your name, please: " << standart;
};

void printWin(unsigned int score){
    std::cout << std::endl << bold << green <<"You WIN! Attempts = " << score << standart << std::endl;
};

void printLose(){
    std::cout << std::endl << bold << red <<"You LOSE!" << standart << std::endl;
};

void printLess(unsigned int number){
    std::cout <<"Less than " << bold << number << standart << std::endl;
};

void printGreater(unsigned int number){
    std::cout <<"Greater than " << bold << number << standart << std::endl;
};

void printComputerHello(std::string &name){
    std::cout << bold << "Hello " << name << '!' << standart << std::endl;
    std::cout << bold << "The opponent guessed a number. Beginning of the game!" << standart << std::endl;
};

void printEnterAnswer(){
    std::cout << "Enter you answer: ";
}

void printScoreTable(){
    std::cout << std::endl << bold << "High scores table: " << standart << std::endl;
};