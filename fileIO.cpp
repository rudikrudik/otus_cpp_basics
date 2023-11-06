#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

const std::string filePath = "scores_table.txt";

#ifdef _WIN32
#define OFFSET_WRITE 5
#else
#define OFFSET_WRITE 4
#endif


bool checkFile(){
    std::ifstream file(filePath);
    if(file.is_open()){
        return true;
    }
    else{
        std::cout << "File missing. Changes will not be saved." << std::endl;
        return false;
    }
};

std::string intToString(unsigned int score){
    if(score <= 9){
        return "00" + std::to_string(score);
    }
    else if (score < 100){
        return "0" + std::to_string(score);
    }
    else if(score < 999){
        return std::to_string(score);
    }
    else{
        return "000";
    }
};

long long int findInFile(std::string &pattern){
    std::string line;
    std::ifstream file(filePath);

    if (checkFile()) {
        while (file) {
            std::getline(file, line);
            auto position = line.find(pattern);

            if (position != std::string::npos) {
                long long pos = file.tellg();
                return (pos - OFFSET_WRITE);
            };
        };
    };
    return std::string::npos;
};

void readFile() {
    std::string line;
    std::ifstream file(filePath);

    if (checkFile()) {
        while (file) {
            std::getline(file, line);
            auto position = line.find(' ');

            if (position != std::string::npos) {
                std::string name = line.substr(0, position);
                std::string score = line.substr(position + 1);
                std::cout.width(30);
                std::cout << std::setw(25) << std::left << name << score << std::endl;
            }
        };
    };
};

void writeFile(std::string &name, unsigned int score){
    auto position = findInFile(name);

    if(position != std::string::npos) {
        std::ofstream file(filePath, std::ios::in);
        file.seekp(position);
        file << intToString(score);
        file.close();
    }
    else
    {
        std::ofstream file(filePath, std::ios::app);
        file << name << ' ' << intToString(score) << '\n';
        file.close();
    };
};


