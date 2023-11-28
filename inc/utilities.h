//
// Created by manka on 10/11/2023.
//

#ifndef VIGENEREENCRYPTION_UTILITIES_H
#define VIGENEREENCRYPTION_UTILITIES_H

#include <iostream>
#include <fstream>
#include "filePathStruct.h"
#include "flags.h"

namespace Utilities {
    void saveTextToFile(std::string &path, std::string &text);

    std::string loadTextFromFile(std::string &path);

    char moveLetter(char &letter, char &key);

    char undoLetter(char &letter, char &key);

    bool validateInput(flags &pickedMode, FilePaths &filePaths);
}

#endif //VIGENEREENCRYPTION_UTILITIES_H
