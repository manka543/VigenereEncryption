//
// Created by manka on 10/11/2023.
//

#ifndef VIGENEREENCRYPTION_UTILITIES_H
#define VIGENEREENCRYPTION_UTILITIES_H

#include <iostream>
#include <fstream>
#include "userInput.h"
#include "flags.h"
#include <vector>

namespace Utilities {
    void saveTextToFile(std::string &path, std::string &text);

    void saveKeyLengthScores(std::string &path, std::vector<std::pair<int, int>> &keyScores);

    std::string loadTextFromFile(std::string &path);

    char moveLetter(char &letter, char &key);

    char undoLetter(char &letter, char &key);

    bool validateInput(flags &pickedMode, FilePaths &filePaths);

    std::string cleanText(std::string &cypherText, int &textLengthToAnalyse);
}

#endif //VIGENEREENCRYPTION_UTILITIES_H
