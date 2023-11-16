//
// Created by manka on 10/11/2023.
//
#include <iostream>
#include <fstream>

#ifndef VIGENEREENCRYPTION_UTILITIES_H
#define VIGENEREENCRYPTION_UTILITIES_H

namespace Utilities {
    void saveTextToFile(std::string &path, std::string &text);

    std::string loadTextFromFile(std::string &path);

    char moveLetter(char &letter, char &key);

    char undoLetter(char &letter, char &key);
}

#endif //VIGENEREENCRYPTION_UTILITIES_H
