
/**
 * @file main.cpp
 * @brief Main entry point for the Vigenere Encryption program.
 */

#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/userInput.h"
#include "inc/constants.h"


int main(int argv, char *argc[]) {
    UserInput userInput = Utilities::parseUserInput(argv, argc);

    if (!Utilities::validateInput(userInput)) {
        std::cout << Constants::helpMessage << std::endl;
        return 0;
    }

    Utilities::runSubprograms(userInput);

    return 0;
}
