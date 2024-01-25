
/**
 * @file encrypt.h
 * @brief Header file for Vigenere Encryption.
 */

#ifndef VIGENEREENCRYPTION_ENCRYPT_H
#define VIGENEREENCRYPTION_ENCRYPT_H

#include <string>

namespace Encrypt {
    /**
     * @brief Encrypt the input text using the Vigenere cipher.
     * @param text The input text to be encrypted.
     * @param key The encryption key.
     * @return The encrypted ciphertext.
     */
    std::string encrypt(std::string &text, std::string &key);
}


#endif //VIGENEREENCRYPTION_ENCRYPT_H
