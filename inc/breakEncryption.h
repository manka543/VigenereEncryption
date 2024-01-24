//
// Created by manka on 10/11/2023.
//

#ifndef VIGENEREENCRYPTION_BREAKENCRYPTION_H
#define VIGENEREENCRYPTION_BREAKENCRYPTION_H

#include <string>
#include <vector>


namespace BreakEncryption {
    std::string findKey(std::string &cypherText, int &textLengthToAnalyse);

    std::vector<std::pair<int, int>> kasiskiExamination(std::string &cleanCypherText);

    char findCaesarShift(std::string &cleanCypherText, int keyLength, int shift);
}

#endif //VIGENEREENCRYPTION_BREAKENCRYPTION_H
