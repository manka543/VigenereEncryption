#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/decrypt.h"
#include "inc/breakEncryption.h"
#include "inc/flags.h"
#include "inc/userInput.h"
#include "inc/constants.h"



int main(int argv, char *argc[]) {
    UserInput userInput = Utilities::parseUserInput(argv, argc);

    if (!Utilities::validateInput(userInput.pickedMode, userInput.filePaths)) {
        std::cout << Constants::helpMessage << std::endl;
        return 0;
    }



    return 0;
}
