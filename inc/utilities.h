
/**
 * @file utilities.h
 * @brief Header file containing utility functions for Vigenere Encryption program.
 */

#ifndef VIGENEREENCRYPTION_UTILITIES_H
#define VIGENEREENCRYPTION_UTILITIES_H

#include <iostream>
#include <fstream>
#include "userInput.h"
#include "flags.h"
#include <vector>

namespace Utilities {

    /**
     * @brief Parses user input and returns a UserInput object.
     * @param argc The number of command-line arguments.
     * @param argv An array containing the command-line arguments.
     * @return A UserInput object containing parsed user input.
     */
    UserInput parseUserInput(int argv, char *argc[]);

    /**
     * @brief Validates the user input for correctness.
     * @param userInput The UserInput object to validate.
     * @return True if the input is valid, false otherwise.
     */
    bool validateInput(UserInput &userInput);

    /**
     * @brief Number of key scores to be shown when breaking the encryption key.
     */
    constexpr int KEY_SCORES_SHOWN = 10;

    /**
     * @brief Saves the provided text to the specified file path.
     *
     * @param path The file path to save the text.
     * @param text The text to be saved.
     */
    void saveTextToFile(std::string &path, std::string &text);

    /**
     * @brief Save key length scores to a file.
     * @param path The file path.
     * @param keyScores Vector of key length scores.
     */
    void saveKeyLengthScores(std::string &path, std::vector<std::pair<int, int>> &keyScores);

    /**
     * @brief Validates the provided encryption or decryption key.
     *
     * This function checks if the provided key is valid for Vigenère cipher encryption or decryption.
     * The key is considered valid if it consists only of alphabetical characters (A-Z or a-z).
     *
     * @param key The key to be validated.
     * @return True if the key is valid, false otherwise.
     */
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




    constexpr int cleanFullTextLenValue = 0;
    /**
     * @brief Clean the input ciphertext to contain only alphabetic characters.
     * @param cypherText The input ciphertext.
     * @param textLengthToAnalyse The maximum length of text to analyze.
     * @return The cleaned ciphertext.
     */
    std::string cleanText(std::string &cypherText, const int &textLengthToAnalyse);


    /**
     * @brief Executes the selected subprogram based on user input.
     * @param userInput The UserInput object containing user choices.
     */
    void runSubprograms(UserInput& userInput);

    /**
     * @brief Show help messages for selected program mode.
     * @param userInput The UserInput object containing selected mode.
     */
    void showHelpMessages(UserInput& userInput);
}

#endif //VIGENEREENCRYPTION_UTILITIES_H
