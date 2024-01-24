#ifndef VIGENEREENCRYPTION_FLAGS_H
#define VIGENEREENCRYPTION_FLAGS_H

enum class flags : int {
    encrypt = 0,
    decrypt,
    breakingKey,
    breakingKeyLength,
    error
};

#endif //VIGENEREENCRYPTION_FLAGS_H
