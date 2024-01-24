
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

bool Utilities::validateInput(flags &pickedMode, FilePaths &filePaths) {
    switch (pickedMode) {
        case flags::encrypt:
        case flags::decrypt:
        case flags::breakingKeyLength:
        case flags::breakingKey: {
            return !filePaths.inputFile.empty() && !filePaths.outputFile.empty() && !filePaths.keyFile.empty();
        }
        default:// it should never happen
        case flags::error: {
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
    return userInput;
}

std::string Utilities::cleanText(std::string &cypherText, int &textLengthToAnalyse) {
    std::string cleanText = {};

    for (char let: cypherText.substr(0, (textLengthToAnalyse < cypherText.length() && textLengthToAnalyse != 0 ? textLengthToAnalyse : cypherText.length()))) {
        if (isalpha(let)) {
            cleanText += (char) tolower(let);
        }
    }
    return cleanText;
}

void Utilities::saveKeyLengthScores(std::string &path, std::vector<std::pair<int, int>> &keyScores) {
    std::ofstream fileStream{path};
    if(fileStream){
        for(int i = 0; i < (10 < keyScores.size() ? 10 : keyScores.size()); i++){
            fileStream << keyScores[i].first << ": " << keyScores[i].second*100/keyScores[0].second << " pkt\n";
        }
        fileStream.close();
    }
}

void Utilities::runSubprogram(UserInput &userInput) {
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
            return;
        }
    }
}
