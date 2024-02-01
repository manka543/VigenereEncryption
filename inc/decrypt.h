
/**
 * @file decrypt.h
 * @brief Header file for Vigenere Decryption.
 */

#ifndef VIGENEREENCRYPTION_DECRYPT_H
#define VIGENEREENCRYPTION_DECRYPT_H

#include <string>
#include "userInput.h"

namespace Decrypt {

    /**
     * @brief Decrypts the provided ciphertext using Vigenere cipher.
     *
     * @param cypherText The ciphertext to be decrypted.
     * @param key The decryption key.
     * @return The decrypted plaintext.
     */
    std::string decrypt(std::string cypherText, std::string encryptionKey);

    /**
     * @brief Runs the decryption subprogram based on the user input.
     *
     * @param userInput The user input specifying the decryption parameters.
     */
    void runSubprogram(UserInput &userInput);
}

#endif //VIGENEREENCRYPTION_DECRYPT_H
