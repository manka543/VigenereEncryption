
/**
 * @file main.cpp
 * @brief The main entry point for the Vigenere Encryption program.
 */

#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/userInput.h"
#include "inc/constants.h"

/**
 * @brief The main function of the program.
 * @param argv The number of command-line arguments.
 * @param argc An array containing the command-line arguments.
 * @return An integer representing the exit status of the program.
 */
int main(int argv, char *argc[]) {
    UserInput userInput = Utilities::parseUserInput(argv, argc);

    if (!Utilities::validateInput(userInput)) {
        std::cout << Constants::helpMessage << std::endl;
        return 0;
    }

    Utilities::runSubprograms(userInput);

    return 0;
}
