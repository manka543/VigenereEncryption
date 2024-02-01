
/**
 * @file breakEncryption.h
 * @brief Header file for breaking the Vigenere Encryption key.
 */

#ifndef VIGENEREENCRYPTION_BREAKENCRYPTION_H
#define VIGENEREENCRYPTION_BREAKENCRYPTION_H

#include <string>
#include <vector>
#include "userInput.h"

namespace BreakEncryption {
    constexpr double KEY_LENGTH_SCORE_THRESHOLD_VALUE = 0.7;
    constexpr int SMALLEST_REPETITION_EVALUATED = 3;
    constexpr int HIGHEST_REPETITION_EVALUATED = 10;
    constexpr int MIN_KEY_LENGTH = 2;
    /**
     * @brief Find the Vigenere Encryption key given a ciphertext and maximum text length to analyze.
     * @param cypherText The input ciphertext.
     * @param textLengthToAnalyse The maximum length of text to analyze.
     * @return The discovered Vigenere Encryption key.
     */
    std::string findKey(std::string &cypherText, int &textLengthToAnalyse);

    /**
     * @brief Perform Kasiski Examination to analyze the ciphertext and identify potential key lengths.
     * @param cleanCypherText The cleaned version of the input ciphertext.
     * @return A vector of pairs representing potential key lengths and their occurrences.
     */
    std::vector<std::pair<int, int>> kasiskiExamination(std::string &cleanCypherText);

    /**
     * @brief Find the Vigenere Encryption key with a known key length.
     * @param cleanCypherText The cleaned version of the input ciphertext.
     * @param keyLength The known key length.
     * @return The discovered Vigenere Encryption key.
     */
    std::string findKeyWithKnownKeyLength(std::string &cleanCypherText, int &keyLength);

    /**
     * @brief Find the Caesar shift for a specific position in the cleaned ciphertext.
     * @param cleanCypherText The cleaned version of the input ciphertext.
     * @param keyLength The known key length.
     * @param shift The specific position to analyze.
     * @return The discovered Caesar shift for the specified position.
     */
    char findCaesarShift(std::string &cleanCypherText, int keyLength, int shift);

    void runSubprogram(UserInput& userInput);

    void runKeyLengthBreakingSubprogram(UserInput& userInput);
}

#endif //VIGENEREENCRYPTION_BREAKENCRYPTION_H
