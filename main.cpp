#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/decrypt.h"
#include "inc/breakEncryption.h"
#include "inc/flags.h"
#include "inc/filePathStruct.h"
#include "inc/constants.h"



int main(int argv, char *argc[]) {
    flags pickedMode{flags::error};
    FilePaths filePaths = {};
    int argsEvaluated{1}; // we ignore first arg because is path to executable file
    while (argsEvaluated < argv) {
        std::string currentArg = argc[argsEvaluated];
        if (currentArg == Constants::encryptFlag) {
            pickedMode = flags::encrypt;
        } else if (currentArg == Constants::decryptFlag) {
            pickedMode = flags::decrypt;
        } else if (currentArg == Constants::breakingKeyFlag) {
            pickedMode = flags::breakingKey;
        } else if (currentArg == Constants::inputFileSwitch && argsEvaluated + 1 < argv) {
            filePaths.inputFile = argc[argsEvaluated + 1];
        } else if (currentArg == Constants::outputFileSwitch && argsEvaluated + 1 < argv) {
            filePaths.outputFile = argc[argsEvaluated + 1];
        } else if (currentArg == Constants::keyFileSwitch && argsEvaluated + 1 < argv) {
            filePaths.keyFile = argc[argsEvaluated + 1];
        } else {
            // do nothing
        }
        argsEvaluated++;
    }
    if (!Utilities::validateInput(pickedMode, filePaths)) {
        std::cout << Constants::helpMessage << std::endl;
        return 0;
    }
    switch (pickedMode) {
        case flags::encrypt: {
            std::string plainText = Utilities::loadTextFromFile(filePaths.inputFile);
            std::string key = Utilities::loadTextFromFile(filePaths.keyFile);
            std::string cypherText = Encrypt::encrypt(plainText, key);
            Utilities::saveTextToFile(filePaths.outputFile, cypherText);
            break;
        }
        case flags::decrypt: {
            std::string cypherText = Utilities::loadTextFromFile(filePaths.inputFile);
            std::string key = Utilities::loadTextFromFile(filePaths.keyFile);
            std::string plainText = Decrypt::decrypt(cypherText, key);
            Utilities::saveTextToFile(filePaths.outputFile, plainText);
            break;
        }
        case flags::breakingKey: {
            std::string cypherText = Utilities::loadTextFromFile(filePaths.inputFile);
            std::string key = BreakEncryption::findKey(cypherText);
            Utilities::saveTextToFile(filePaths.keyFile, key);
            std::string plainText = Decrypt::decrypt(cypherText, key);
            Utilities::saveTextToFile(filePaths.outputFile, plainText);
            break;
        }
        default: {
            std::cout << "Error!!!" << std::endl;
            return 1;
        }
    }

    return 0;
}
