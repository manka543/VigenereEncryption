
/**
 * @file decrypt.h
 * @brief Header file for Vigenere Decryption.
 */

#ifndef VIGENEREENCRYPTION_DECRYPT_H
#define VIGENEREENCRYPTION_DECRYPT_H

#include <string>

namespace Decrypt {
    /**
     * @brief Decrypt the input ciphertext using the Vigenere cipher.
     * @param cypherText The input ciphertext to be decrypted.
     * @param encryptionKey The decryption key.
     * @return The decrypted plaintext.
     */
    std::string decrypt(std::string cypherText, std::string encryptionKey);
}

#endif //VIGENEREENCRYPTION_DECRYPT_H
