
/**
 * @file breakEncryption.cpp
 * @brief Implementation of functions for breaking the Vigenere Encryption key.
 */

#include "../inc/breakEncryption.h"
#include "../inc/englishLetterFrequency.h"
#include "../inc/utilities.h"
#include "decrypt.h"
#include <unordered_map>
#include <vector>
#include <limits>
#include <algorithm>


std::string BreakEncryption::findKey(std::string &cypherText, int &textLengthToAnalyse) {
    std::string key{}, cleanText = Utilities::cleanText(cypherText, textLengthToAnalyse);
    int keyLength{};
    if(cleanText.empty()){
        return key;
    }

    std::vector<std::pair<int, int>> keyLengthPoints = kasiskiExamination(cleanText);

    for (int i = 0; i < keyLengthPoints.size(); i++) {
        if (keyLengthPoints[i].second > keyLengthPoints[0].second * KEY_LENGTH_SCORE_THRESHOLD_VALUE) {
            keyLength = keyLengthPoints[i].first;
        }
    }

    return findKeyWithKnownKeyLength(cleanText, keyLength);
}

std::vector<std::pair<int, int>> BreakEncryption::kasiskiExamination(std::string &cleanCypherText) {
    std::unordered_map<int, int> factors{};
    for (int i = SMALLEST_REPETITION_EVALUATED; i < HIGHEST_REPETITION_EVALUATED; i++) {
        for (int j = 0; j < cleanCypherText.length() - i; j++) {
            std::string text = cleanCypherText.substr(j, i);
            size_t nextPosition = cleanCypherText.find(text, j + i);
            if (nextPosition != std::string::npos) {
                int difference = (int) nextPosition - j;
                for (int k = MIN_KEY_LENGTH; k < difference; k++) {
                    if (difference % k == 0) {
                        factors[k]++;
                    }
                }
            }
        }
    }

    std::vector<std::pair<int, int>> sorted(factors.begin(), factors.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto &a, const auto &b) { return a.second > b.second; });
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

    for (int i = 0; i < englishLetterFrequency.size(); i++) {
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
    for (int letNumber = 0; letNumber < keyLength; letNumber++) {
        key.push_back(findCaesarShift(cleanCypherText, keyLength, letNumber));
    }
    return key;
}

void BreakEncryption::runSubprogram(UserInput &userInput) {
    std::string cypherText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
    std::string key{};
    if (userInput.isKeyLenSpecified) {
        std::string cleanCypherText = Utilities::cleanText(cypherText, userInput.maxTextLengthToAnalyse);
        if(cleanCypherText.empty()) {
            std::cout<<"ERROR: Empty input file!!!\n";
            return;
        }
        key = findKeyWithKnownKeyLength(cleanCypherText, userInput.keyLength);
    } else {
        key = findKey(cypherText, userInput.maxTextLengthToAnalyse);
    }
    if(!key.empty()){
        if(!userInput.filePaths.keyFile.empty()){
            Utilities::saveTextToFile(userInput.filePaths.keyFile, key);
        }
        std::string plainText = Decrypt::decrypt(cypherText, key);
        Utilities::saveTextToFile(userInput.filePaths.outputFile, plainText);
    } else {
        std::cout<<"ERROR: Key can't be evaluated!!!"<<std::endl;
    }
}

void BreakEncryption::runKeyLengthBreakingSubprogram(UserInput &userInput) {
    std::string cypherText = Utilities::loadTextFromFile(userInput.filePaths.inputFile);
    std::string cleanText = Utilities::cleanText(cypherText, userInput.maxTextLengthToAnalyse);
    if(!cleanText.empty()){
        std::vector<std::pair<int, int>> keyLengthPoints = kasiskiExamination(cleanText);
        Utilities::saveKeyLengthScores(userInput.filePaths.keyFile, keyLengthPoints);
    } else {
        std::cout<<"ERROR: Empty input file!!!\n";
    }
}
