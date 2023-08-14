#include "Reverser.h"
#include <cmath>

int Reverser::reverseDigit(int value) {
    if(value < 0) {
        return -1;  // error case
    }
    if(value < 10) {
        return value;
    }

    int lastDigit = value % 10;
    return lastDigit * pow(10, int(log10(value))) + reverseDigit(value/10);
}

std::string Reverser::reverseString(std::string characters) {
    if(characters.length() == 0) {
        return characters;
    }
    if(characters == "ERROR") {
        return "ERROR";
    }
    return characters.back() + reverseString(characters.substr(0, characters.length()-1));
}
