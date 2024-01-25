
/**
 * @file userInput.h
 * @brief Header file for user input data structures.
 */

#ifndef VIGENEREENCRYPTION_USERINPUT_H
#define VIGENEREENCRYPTION_USERINPUT_H

#include <string>
#include "flags.h"

/**
 * @brief Structure representing file paths for input, output, and key files.
 */
struct FilePaths {
    std::string inputFile;
    std::string outputFile;
    std::string keyFile;
};


/**
 * @brief Structure representing user input data.
 */
struct UserInput {
    FilePaths filePaths{};
    flags pickedMode{};
    int maxTextLengthToAnalyse{};
    bool isKeyLenSpecified{};
    int keyLength{};
};

#endif //VIGENEREENCRYPTION_USERINPUT_H
