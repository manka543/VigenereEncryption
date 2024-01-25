
/**
 * @file breakEncryption.cpp
 * @brief Implementation of functions for breaking the Vigenere Encryption key.
 */

#include "../inc/breakEncryption.h"
#include "../inc/englishLetterFrequency.h"
#include "../inc/utilities.h"
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>


std::string BreakEncryption::findKey(std::string &cypherText, int &textLengthToAnalyse) {
    std::string key{}, cleanText = Utilities::cleanText(cypherText, textLengthToAnalyse);
    int keyLength{};

    std::vector<std::pair<int, int>> keyLengthPoints = kasiskiExamination(cleanText);

    for (int i=0; i<10; i++){
        if(keyLengthPoints[i].second > keyLengthPoints[0].second*0.7){
            keyLength = keyLengthPoints[i].first;
        }
    }

    return findKeyWithKnownKeyLength(cleanText, keyLength);
}

std::vector<std::pair<int, int>> BreakEncryption::kasiskiExamination(std::string &cleanCypherText) {
    std::unordered_map<int, int> factors{};
    for (int i = 3; i < 10; i++) {
        for (int j = 0; j < cleanCypherText.length() - i; j++) {
            std::string text = cleanCypherText.substr(j, i);
            size_t nextPosition = cleanCypherText.find(text, j + i);
            if (nextPosition != std::string::npos) {
                int difference = (int) nextPosition - j;
                for (int k = 2; k < difference; k++) {
                    if (difference % k == 0) {
                        factors[k]++;
                    }
                }
            }
        }
    }

    std::vector<std::pair<int, int>> sorted(factors.begin(), factors.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto &a, const auto &b){return a.second>b.second;});
    return sorted;
}


char BreakEncryption::findCaesarShift(std::string &cleanCypherText, int keyLength, int shift) {
    std::unordered_map<char, int> count{};
    for (char chr = 'a'; chr <= 'z'; chr++) {
        count[chr] = 0;
    }
    int len = 0;
    for (int i = shift; i < cleanCypherText.length(); i += keyLength) {
        if (isalpha(cleanCypherText[i])) {
            count[(char) tolower(cleanCypherText[i])]++;
            len++;
        }
    }

    double bestScore{std::numeric_limits<double>::max()};
    char bestScoreShift;

    for (int i = 0; i < 26; i++) {
        double score = 0;
        for (char chr = 'a'; chr <= 'z'; chr++) {
            double frequency =
                    (double) count[(char) (chr + i <= 'z' ? chr + i : chr + i - 'z' + 'a' - 1)] / (double) len;
            score += std::abs(frequency - englishLetterFrequency.at(chr));
        }
        if (score < bestScore) {
            bestScore = score;
            bestScoreShift = (char) ('a' + i);
        }
    }

    return bestScoreShift;
}

std::string BreakEncryption::findKeyWithKnownKeyLength(std::string &cleanCypherText, int &keyLength) {
    std::string key{};
    for(int letNumber = 0; letNumber<keyLength; letNumber++){
        key.push_back(findCaesarShift(cleanCypherText, keyLength, letNumber));
    }
    return key;
}
