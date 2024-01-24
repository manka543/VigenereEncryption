//
// Created by manka543 on 28/11/2023.
//

#ifndef VIGENEREENCRYPTION_USERINPUT_H
#define VIGENEREENCRYPTION_USERINPUT_H

#include <string>
#include "flags.h"

struct FilePaths {
    std::string inputFile;
    std::string outputFile;
    std::string keyFile;
};

struct UserInput {
    FilePaths filePaths{};
    flags pickedMode{};
    int maxTextLengthToAnalyse{};
    bool isKeyLenSpecified{};
    int keyLength{};
};

#endif //VIGENEREENCRYPTION_USERINPUT_H
