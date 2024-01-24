#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/decrypt.h"
#include "inc/breakEncryption.h"
#include "inc/flags.h"
#include "inc/userInput.h"
#include "inc/constants.h"



int main(int argv, char *argc[]) {
    UserInput userInput{};
    int argsEvaluated{1}; // we ignore first arg because is path to executable file
    while (argsEvaluated < argv) {
        std::string currentArg = argc[argsEvaluated];
        if (currentArg == Constants::encryptFlag) {
            userInput.pickedMode = flags::encrypt;
        } else if (currentArg == Constants::decryptFlag) {
            userInput.pickedMode = flags::decrypt;
        } else if (currentArg == Constants::breakingKeyFlag) {
            userInput.pickedMode = flags::breakingKey;
        } else if (currentArg == Constants::onlyFindKeyLengthFlag) {
            userInput.pickedMode = flags::breakingKeyLength;
        }else if (currentArg == Constants::inputFileSwitch && argsEvaluated + 1 < argv) {
            userInput.filePaths.inputFile = argc[argsEvaluated + 1];
        } else if (currentArg == Constants::outputFileSwitch && argsEvaluated + 1 < argv) {
            userInput.filePaths.outputFile = argc[argsEvaluated + 1];
        } else if (currentArg == Constants::keyFileSwitch && argsEvaluated + 1 < argv) {
            userInput.filePaths.keyFile = argc[argsEvaluated + 1];
        } else if (currentArg == Constants::maxLengthToAnalyseSwitch && argsEvaluated + 1 < argv) {
            userInput.maxTextLengthToAnalyse = std::stoi(argc[argsEvaluated + 1]);
        }  else if (currentArg == Constants::specifyKeyLengthSwitch && argsEvaluated + 1 < argv) {
            userInput.isKeyLenSpecified = true;
            userInput.keyLength = std::stoi(argc[argsEvaluated + 1]);
        } else {
            // do nothing
        }
        argsEvaluated++;
    }
    if (!Utilities::validateInput(userInput.pickedMode, userInput.filePaths)) {
        std::cout << Constants::helpMessage << std::endl;
        return 0;
    }
    switch (userInput.pickedMode) {
        case flags::encrypt: {
            std::string plainText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
            std::string key = Utilities::loadTextFromFile(userInput.filePaths.keyFile);
            std::string cypherText = Encrypt::encrypt(plainText, key);
            Utilities::saveTextToFile(userInput.filePaths.outputFile, cypherText);
            break;
        }
        case flags::decrypt: {
            std::string cypherText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
            std::string key = Utilities::loadTextFromFile(userInput.filePaths.keyFile);
            std::string plainText = Decrypt::decrypt(cypherText, key);
            Utilities::saveTextToFile(userInput.filePaths.outputFile, plainText);
            break;
        }
        case flags::breakingKey: {
            std::string cypherText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
            std::string key = BreakEncryption::findKey(cypherText, userInput.maxTextLengthToAnalyse);
            Utilities::saveTextToFile(userInput.filePaths.keyFile, key);
            std::string plainText = Decrypt::decrypt(cypherText, key);
            Utilities::saveTextToFile(userInput.filePaths.outputFile, plainText);
            break;
        }
        case flags::breakingKeyLength:{
            std::string cypherText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
            std::string cleanText = Utilities::cleanText(cypherText, userInput.maxTextLengthToAnalyse);
            std::vector<std::pair<int, int>> keyLengthPoints = BreakEncryption::kasiskiExamination(cleanText);
            Utilities::saveKeyLengthScores(userInput.filePaths.keyFile, keyLengthPoints);
            break;
        }
        default: {
            std::cout << "Error!!!" << std::endl;
            return 1;
        }
    }

    return 0;
}
