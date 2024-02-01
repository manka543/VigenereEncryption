
/**
 * @file breakEncryption.h
 * @brief Header file containing functions related to breaking Vigenere encryption.
 */

#ifndef VIGENEREENCRYPTION_BREAKENCRYPTION_H
#define VIGENEREENCRYPTION_BREAKENCRYPTION_H

#include <string>
#include <vector>
#include "userInput.h"

namespace BreakEncryption {
    /**
     * @brief Threshold value for key length score during evaluation.
     */
    constexpr double KEY_LENGTH_SCORE_THRESHOLD_VALUE = 0.7;

    /**
     * @brief Minimum repetition length considered during Kasiski Examination.
     */
    constexpr int SMALLEST_REPETITION_EVALUATED = 3;

    /**
     * @brief Maximum repetition length considered during Kasiski Examination.
     */
    constexpr int HIGHEST_REPETITION_EVALUATED = 10;

    /**
     * @brief Minimum allowed key length.
     */
    constexpr int MIN_KEY_LENGTH = 2;

    /**
     * @brief Finds the encryption key for a given cipher text.
     * @param cypherText The cipher text to analyze.
     * @param textLengthToAnalyse The maximum length of text to analyze.
     * @return The found encryption key.
     */
    std::string findKey(std::string &cypherText, int &textLengthToAnalyse);

    /**
     * @brief Performs Kasiski Examination to find possible key lengths.
     * @param cleanCypherText The cleaned cipher text.
     * @return A vector of pairs representing possible key lengths and their scores.
     */
    std::vector<std::pair<int, int>> kasiskiExamination(std::string &cleanCypherText);

    /**
     * @brief Finds the encryption key with a known key length.
     * @param cleanCypherText The cleaned cipher text.
     * @param keyLength The known key length.
     * @return The found encryption key.
     */
    std::string findKeyWithKnownKeyLength(std::string &cleanCypherText, int &keyLength);

    /**
     * @brief Finds the Caesar shift for a given clean cipher text.
     * @param cleanCypherText The cleaned cipher text.
     * @param keyLength The key length used for encryption.
     * @param shift The shift to analyze.
     * @return The found Caesar shift character.
     */
    char findCaesarShift(std::string &cleanCypherText, int keyLength, int shift);

    /**
     * @brief Runs the main breaking encryption subprogram.
     * @param userInput User input data.
     */
    void runSubprogram(UserInput& userInput);

    /**
     * @brief Runs the subprogram for breaking key lengths.
     * @param userInput User input data.
     */
    void runKeyLengthBreakingSubprogram(UserInput& userInput);
}

#endif //VIGENEREENCRYPTION_BREAKENCRYPTION_H
