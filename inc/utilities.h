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

    UserInput parseUserInput(int argv, char *argc[]);

    void runSubprogram(UserInput& userInput);
}

#endif //VIGENEREENCRYPTION_UTILITIES_H
