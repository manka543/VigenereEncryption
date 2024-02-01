
/**
 * @file encrypt.h
 * @brief Header file containing functions for Vigenere encryption.
 */

#ifndef VIGENEREENCRYPTION_ENCRYPT_H
#define VIGENEREENCRYPTION_ENCRYPT_H

#include <string>
#include "userInput.h"

namespace Encrypt {

    /**
     * @brief Encrypts the provided plaintext using Vigenere cipher.
     * @param plainText The plaintext to be encrypted.
     * @param key The encryption key.
     * @return The encrypted ciphertext.
     */
    std::string encrypt(std::string &text, std::string &key);

    /**
     * @brief Runs the main subprogram for Vigenere encryption.
     * @param userInput The user input.
     */
    void runSubprogram(UserInput &userInput);
}


#endif //VIGENEREENCRYPTION_ENCRYPT_H
