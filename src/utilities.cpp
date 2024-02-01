
/**
 * @file utilities.cpp
 * @brief Implementation of utility functions used in the program.
 */

#include "../inc/utilities.h"
#include "constants.h"
#include "encrypt.h"
#include "decrypt.h"
#include "breakEncryption.h"

void Utilities::saveTextToFile(std::string &path, std::string &text) {
    std::ofstream fileStream(path);
    fileStream << text;
    fileStream.close();
}

std::string Utilities::loadTextFromFile(std::string &path) {
    std::ifstream fileStream(path);
    std::string text{}, tmpText{};
    while (std::getline(fileStream, tmpText)) {
        text += tmpText + '\n';
    }

    fileStream.close();
    return text;
}

std::string Utilities::validateKey(const std::string &key){
    std::string validKey;
    bool invalidChar = false, invalidCaseLetter = false, space = false, newLine = false;
    for(char let : key){
        if(let < 'a' or let > 'z'){
            if(let >= 'A' and let <= 'Z'){
                if(!invalidCaseLetter){
                    invalidCaseLetter = true;
                    validKey.push_back((char)tolower(let));
                }
            } else if (let == ' ') {
                if(!space){
                    space = true;
                    std::cout<<"WARNING: Key should not contain spaces!!!\nContinuing without them\n";
                }
            } else if (let == '\n'){
                if(!newLine){
                    newLine = true;
                    std::cout<<"WARNING: Key should not contain new line chars!!!\nContinuing without them\n";
                }
            } else {
                if(!invalidChar){
                    invalidChar = true;
                    std::cout<<"WARNING: Key should not contain anything except chars from 'a' - 'z'\nContinuing without them\n";
                }
                std::cout<<"WARNING: Invalid character found: "<<let<<std::endl;
            }
        }
    }
    if(!key.empty()){
        if(invalidChar || invalidCaseLetter || space || newLine){
            std::cout<<"Key after corrections looks like: '"<<key<<"'\n";
        }
        return key;
    }
    throw std::runtime_error("ERROR: Wrong key!!!");
}

char Utilities::moveLetter(char &letter, char &key) {
    if (letter >= 'a' && letter <= 'z') {
        if (letter + key - 'a' > 'z') {
            return char(letter + key - 'z' - 1);
        } else {
            return char(letter + key - 'a');
        }
    } else if (letter >= 'A' && letter <= 'Z') {
        if (letter + key - 'a' > 'Z') {
            return char(letter + key - 'z' - 1);
        } else {
            return char(letter + key - 'a');
        }
    } else {
        return letter;
    }
}

char Utilities::undoLetter(char &letter, char &key) {
    if (letter >= 'a' && letter <= 'z') {
        if (letter - key + 'a' < 'a') {
            return char(letter - key + 'z' + 1);
        } else {
            return char(letter - key + 'a');
        }
    } else if (letter >= 'A' && letter <= 'Z') {
        if (letter - key + 'a' < 'A') {
            return char(letter - key + 'z' + 1);
        } else {
            return char(letter - key + 'a');
        }
    } else {
        return letter;
    }
}

bool Utilities::validateInput(UserInput &userInput) {
    if(userInput.showHelpMessage && userInput.pickedMode != flags::error){
        return true;
    }
    switch (userInput.pickedMode) {
        case flags::breakingKeyLength:
            return !userInput.filePaths.inputFile.empty() && !userInput.filePaths.keyFile.empty();
        case flags::breakingKey:
            if (userInput.isKeyLenSpecified and userInput.keyLength <= 0){
                std::cout<<"ERROR: Provided wrong key length: "<<userInput.keyLength<<std::endl;
                return false;
            }
            return !userInput.filePaths.inputFile.empty() && !userInput.filePaths.outputFile.empty();
        case flags::encrypt:
        case flags::decrypt:{
            return !userInput.filePaths.inputFile.empty() && !userInput.filePaths.outputFile.empty() && !userInput.filePaths.keyFile.empty();
        }
        default:// it should never happen
        case flags::error: { // in case of unexpected argument
            return false;
        }
    }
}

UserInput Utilities::parseUserInput(int argv, char *argc[]) {
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
        } else if (currentArg == Constants::helpFlag) {
            userInput.showHelpMessage = true;
        } else if (currentArg == Constants::inputFileSwitch && argsEvaluated + 1 < argv) {
            userInput.filePaths.inputFile = argc[argsEvaluated + 1];
            argsEvaluated++;
        } else if (currentArg == Constants::outputFileSwitch && argsEvaluated + 1 < argv) {
            userInput.filePaths.outputFile = argc[argsEvaluated + 1];
            argsEvaluated++;
        } else if (currentArg == Constants::keyFileSwitch && argsEvaluated + 1 < argv) {
            userInput.filePaths.keyFile = argc[argsEvaluated + 1];
            argsEvaluated++;
        } else if (currentArg == Constants::maxLengthToAnalyseSwitch && argsEvaluated + 1 < argv) {
            userInput.maxTextLengthToAnalyse = std::stoi(argc[argsEvaluated + 1]);
            argsEvaluated++;
        }  else if (currentArg == Constants::specifyKeyLengthSwitch && argsEvaluated + 1 < argv) {
            userInput.isKeyLenSpecified = true;
            userInput.keyLength = std::stoi(argc[argsEvaluated + 1]);
            argsEvaluated++;
        } else {
            std::cout<<"ERROR: Unexpected argument: "<<argc[argsEvaluated]<<std::endl;
            userInput.pickedMode = flags::error;
            return userInput;
        }
        argsEvaluated++;
    }
    return userInput;
}

std::string Utilities::cleanText(std::string &cypherText, const int &textLengthToAnalyse) {
    std::string cleanText = {};

    for (char let: cypherText.substr(0, (textLengthToAnalyse < cypherText.length() && textLengthToAnalyse != 0 ? textLengthToAnalyse : cypherText.length()))) {
        if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z')) {
            cleanText += (char) tolower(let);
        }
    }
    return cleanText;
}

void Utilities::saveKeyLengthScores(std::string &path, std::vector<std::pair<int, int>> &keyScores) {
    std::ofstream fileStream{path};
    if(fileStream){
        for(int i = 0; i < (KEY_SCORES_SHOWN < keyScores.size() ? KEY_SCORES_SHOWN : keyScores.size()); i++){
            fileStream << keyScores[i].first << ": " << keyScores[i].second*100/keyScores[0].second << " pts\n";
        }
        fileStream.close();
    }
}

void Utilities::runSubprograms(UserInput &userInput) {
    if(userInput.showHelpMessage){
        showHelpMessages(userInput);
        return;
    }
    switch (userInput.pickedMode) {
        case flags::encrypt: {
            Encrypt::runSubprogram(userInput);
            break;
        }
        case flags::decrypt: {
            Decrypt::runSubprogram(userInput);
            break;
        }
        case flags::breakingKey: {
            BreakEncryption::runSubprogram(userInput);
            break;
        }
        case flags::breakingKeyLength:{
            BreakEncryption::runKeyLengthBreakingSubprogram(userInput);
            break;
        }
        default: {
            std::cout << "Error!!!" << std::endl;
            return;
        }
    }
}

void Utilities::showHelpMessages(UserInput &userInput) {
    switch(userInput.pickedMode){
        case flags::encrypt:
            std::cout<<Constants::encryptHelpMessage;
            break;
        case flags::decrypt:
            std::cout<<Constants::decryptHelpMessage;
            break;
        case flags::breakingKey:
            std::cout<<Constants::breakEncryptionHelpMessage;
            break;
        case flags::breakingKeyLength:
            std::cout<<Constants::breakKeyLengthHelpMessage;
            break;
        default:
            std::cout<<Constants::helpMessage;
            break;
    }
}
