
/**
 * @file encrypt.cpp
 * @brief Implementation file for Vigenere encryption functions.
 */

#include "../inc/encrypt.h"
#include "../inc/utilities.h"


std::string Encrypt::encrypt(std::string &text, std::string &key) {
    int keyCounter{0};
    std::string cypherText = {};
    for (char &let: text) {
        cypherText += Utilities::moveLetter(let, key[keyCounter]);
        if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z')) {
            if (keyCounter >= key.length() - 1) {
                keyCounter = 0;
            } else {
                keyCounter++;
            }
        }
    }
    return cypherText;
}

void Encrypt::runSubprogram(UserInput &userInput) {
    std::string plainText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
    std::string key = Utilities::loadTextFromFile(userInput.filePaths.keyFile);
    key = Utilities::cleanText(key, Utilities::cleanFullTextLenValue);

    try{
        Utilities::validateKey(key);
    } catch (std::runtime_error& e){
        std::cout<<e.what()<<std::endl;
    }

    std::string cypherText = encrypt(plainText, key);
    Utilities::saveTextToFile(userInput.filePaths.outputFile, cypherText);
}



