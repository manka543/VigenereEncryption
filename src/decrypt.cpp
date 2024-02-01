
/**
 * @file decrypt.cpp
 * @brief Implementation of Vigenere Decryption.
 */

#include "../inc/decrypt.h"
#include "../inc/utilities.h"

std::string Decrypt::decrypt(std::string cypherText, std::string encryptionKey) {
    int keyCounter{0};
    std::string text = {};
    for (char &let: cypherText) {
        text += Utilities::undoLetter(let, encryptionKey[keyCounter]);
        if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <= 'Z')) {
            if (keyCounter >= encryptionKey.length() - 1) {
                keyCounter = 0;
            } else {
                keyCounter++;
            }
        }
    }
    return text;
}

void Decrypt::runSubprogram(UserInput &userInput) {
    std::string cypherText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
    std::string key = Utilities::loadTextFromFile(userInput.filePaths.keyFile);
    key = Utilities::cleanText(key, Utilities::cleanFullTextLenValue);

    try{
        Utilities::validateKey(key);
    } catch (std::runtime_error& e){
        std::cout<<e.what()<<std::endl;
    }

    std::string plainText = decrypt(cypherText, key);
    Utilities::saveTextToFile(userInput.filePaths.outputFile, plainText);
}
