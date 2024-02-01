
/**
 * @file userInput.h
 * @brief Header file containing the UserInput struct for Vigenere Encryption program.
 */

#ifndef VIGENEREENCRYPTION_USERINPUT_H
#define VIGENEREENCRYPTION_USERINPUT_H

#include <string>
#include "flags.h"

/**
 * @brief Structure representing file paths used in the program.
 */
struct FilePaths {
    std::string inputFile;
    std::string outputFile;
    std::string keyFile;
};

/**
 * @struct UserInput
 * @brief Represents user input choices for Vigenere Encryption program.
 */
struct UserInput {
    FilePaths filePaths{};
    flags pickedMode{};
    bool showHelpMessage{};
    int maxTextLengthToAnalyse{};
    bool isKeyLenSpecified{};
    int keyLength{};
};

#endif //VIGENEREENCRYPTION_USERINPUT_H
