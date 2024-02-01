
/**
 * @file utilities.h
 * @brief Header file for utility functions used in the program.
 */

#ifndef VIGENEREENCRYPTION_UTILITIES_H
#define VIGENEREENCRYPTION_UTILITIES_H

#include <iostream>
#include <fstream>
#include "userInput.h"
#include "flags.h"
#include <vector>

namespace Utilities {
    constexpr int KEY_SCORES_SHOWN = 10;

    /**
     * @brief Save text to a file.
     * @param path The file path.
     * @param text The text to save.
     */
    void saveTextToFile(std::string &path, std::string &text);

    /**
     * @brief Save key length scores to a file.
     * @param path The file path.
     * @param keyScores Vector of key length scores.
     */
    void saveKeyLengthScores(std::string &path, std::vector<std::pair<int, int>> &keyScores);

    std::string validateKey(const std::string &key);

    /**
     * @brief Load text from a file.
     * @param path The file path.
     * @return The loaded text.
     */
    std::string loadTextFromFile(std::string &path);

    /**
     * @brief Move a letter using the Vigenere cipher.
     * @param letter The letter to move.
     * @param key The key to use for moving.
     * @return The moved letter.
     */
    char moveLetter(char &letter, char &key);

    /**
     * @brief Undo the movement of a letter using the Vigenere cipher.
     * @param letter The letter to undo.
     * @param key The key to use for undoing.
     * @return The undone letter.
     */
    char undoLetter(char &letter, char &key);

    /**
     * @brief Validate user input based on the selected program mode.
     * @param userInput The user input to validate.
     * @return True if the input is valid, false otherwise.
     */
    bool validateInput(UserInput &userInput);


    constexpr int cleanFullTextLenValue = 0;
    /**
     * @brief Clean the input ciphertext to contain only alphabetic characters.
     * @param cypherText The input ciphertext.
     * @param textLengthToAnalyse The maximum length of text to analyze.
     * @return The cleaned ciphertext.
     */
    std::string cleanText(std::string &cypherText, const int &textLengthToAnalyse);

    /**
     * @brief Parse user input arguments and create a UserInput struct.
     * @param argv The number of command line arguments.
     * @param argc An array of command line argument strings.
     * @return The parsed UserInput struct.
     */
    UserInput parseUserInput(int argv, char *argc[]);

    /**
     * @brief Run the selected subprogram based on user input.
     * @param userInput The user input specifying the subprogram.
     */
    void runSubprograms(UserInput& userInput);

    void showHelpMessages(UserInput& userInput);
}

#endif //VIGENEREENCRYPTION_UTILITIES_H
