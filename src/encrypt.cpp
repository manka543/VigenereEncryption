//
// Created by manka on 10/11/2023.
//

#include "../inc/encrypt.h"
#include "../inc/utilities.h"

std::string Encrypt::encrypt(std::string &text, std::string &key) {
    int keyCounter {0};
    std::string cypherText = {};
    for (char &let: text) {
        cypherText += Utilities::moveLetter(let, key[keyCounter]);
        if ((let >= 'a' && let <= 'z') || (let >= 'A' && let <='Z')) {
            if (keyCounter >= key.length() - 1) {
                keyCounter = 0;
            } else {
                keyCounter++;
            }
        }
    }
    return cypherText;
}



