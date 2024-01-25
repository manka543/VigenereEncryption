
/**
 * @file flags.h
 * @brief Header file for enumeration of program modes.
 */

#ifndef VIGENEREENCRYPTION_FLAGS_H
#define VIGENEREENCRYPTION_FLAGS_H


/**
 * @brief Enumeration representing different program modes.
 */
enum class flags : int {
    encrypt = 0,
    decrypt,
    breakingKey,
    breakingKeyLength,
    error
};

#endif //VIGENEREENCRYPTION_FLAGS_H
