#include <ctime>
#include <cstdlib>

unsigned int randomNumber(int range){
    srand(static_cast<unsigned int>(time(nullptr)));
    const unsigned int result = rand() % range + 1;
    return result;
};