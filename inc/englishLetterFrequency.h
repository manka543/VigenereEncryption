
/**
 * @file englishLetterFrequency.h
 * @brief Header file for English letter frequency values.
 */

#ifndef VIGENEREENCRYPTION_ENGLISHLETTERFREQUENCY_H
#define VIGENEREENCRYPTION_ENGLISHLETTERFREQUENCY_H

#include <unordered_map>

/**
 * @brief Map of English letter frequencies for use in frequency analysis.
 */
const std::unordered_map<char, double> englishLetterFrequency{
        {'e', 0.111607},
        {'m', 0.030129},
        {'a', 0.084966},
        {'h', 0.030034},
        {'r', 0.075809},
        {'g', 0.024705},
        {'i', 0.075448},
        {'b', 0.020720},
        {'o', 0.071635},
        {'f', 0.018121},
        {'t', 0.069509},
        {'y', 0.017779},
        {'n', 0.066544},
        {'w', 0.012899},
        {'s', 0.057351},
        {'k', 0.011016},
        {'l', 0.054893},
        {'v', 0.010074},
        {'c', 0.045388},
        {'x', 0.002902},
        {'u', 0.036308},
        {'z', 0.002722},
        {'d', 0.033844},
        {'j', 0.001965},
        {'p', 0.031671},
        {'q', 0.001962},
};

#endif //VIGENEREENCRYPTION_ENGLISHLETTERFREQUENCY_H
