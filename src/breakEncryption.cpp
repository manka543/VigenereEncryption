//
// Created by manka543 on 10/11/2023.
//

#include "../inc/breakEncryption.h"
#include "../inc/englishLetterFrequency.h"
#include <unordered_map>
#include <vector>
#include <limits>
#include <iostream>


std::string BreakEncryption::findKey(std::string &cypherText, int &textLengthToAnalyse) {
    std::string key{}, cleanText = {};

    for (char let: cypherText.substr(0, (textLengthToAnalyse < cypherText.length() && textLengthToAnalyse != 0 ? textLengthToAnalyse : cypherText.length()))) {
        if (isalpha(let)) {
            cleanText += (char) tolower(let);
        }
    }

    int keyLength = kasiskiExamination(cleanText);
    for (int shift = 0; shift < keyLength; shift++) {
        key += findCaesarShift(cleanText, keyLength, shift);
    }
    return key;
}

int BreakEncryption::kasiskiExamination(std::string &cleanCypherText) {
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

    int len{};
    std::vector<std::pair<int, int>> sorted(factors.begin(), factors.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto &a, const auto &b){return a.second>b.second;});
    for (int i=0; i<10; i++){
        if(sorted[i].second > sorted[0].second*0.7){
            len = sorted[i].first;
        }
        std::cout<<sorted[i].first<<": "<<(int)sorted[i].second*100/sorted[0].second<<" pkt\n";
    }
    return len;
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
            score += std::abs(frequency - englishLetterFrequency[chr]);
        }
        if (score < bestScore) {
            bestScore = score;
            bestScoreShift = (char) ('a' + i);
        }
    }

    return bestScoreShift;
}