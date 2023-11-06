#include <iostream>
#include <string>
#include "randomNumber.h"
#include "fileIO.h"
#include "consoleIO.h"

#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char *argv[]) {

#ifdef _WIN32
    DWORD con_mode;
    GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &con_mode);
    con_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), con_mode);
#endif

    unsigned int randomRange = 100;

    if(argc >= 2){
        std::string param = argv[1];
        if(param == "-table") {
            readFile();
            return 0;
        };

        if(param == "-max"){
            randomRange = std::stoul(argv[2]);
        };

        if(param == "-level"){
            switch (std::stoi(argv[2])) {
                case 1: randomRange = 10; break;
                case 2: randomRange = 50; break;
                case 3: randomRange = 100; break;
            };
        }
    };

    std::string name;
    printHello();
    std::cin >> name;
    printComputerHello(name);

    unsigned int randomNum;
    unsigned int answer;
    unsigned int score = 0;
    unsigned int scoreToLose = randomRange / 2;
    randomNum = randomNumber(randomRange);

    // Сам цикл игры
    while(score != scoreToLose){
        printEnterAnswer();
        std::cin >> answer;
        score++;
        if(randomNum == answer){
            scoreToLose = 0;
            printWin(score);
            writeFile(name, score);
            printScoreTable();
            readFile();
            break;
        }
        else if(randomNum < answer)
        {
            printLess(answer);
        }
        else{
            printGreater(answer);
        }
    };

    // Если игрок сделал больше попыток, то он проиграл
    if(score == scoreToLose) {
        printLose();
    };

    return 0;
}
