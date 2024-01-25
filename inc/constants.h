
/**
 * @file constants.h
 * @brief Header file for program constants and help messages.
 */

#ifndef VIGENEREENCRYPTION_CONSTANTS_H
#define VIGENEREENCRYPTION_CONSTANTS_H

namespace Constants {

    /**
     * @brief Command line flags and options for the Vigenere Encryption program.
     */

    constexpr std::string_view encryptFlag = "--en";
    constexpr std::string_view decryptFlag = "--de";
    constexpr std::string_view breakingKeyFlag = "--br";
    constexpr std::string_view onlyFindKeyLengthFlag = "--br-key-len";
    constexpr std::string_view specifyKeyLengthSwitch = "-k-len";
    constexpr std::string_view inputFileSwitch = "-i";
    constexpr std::string_view keyFileSwitch = "-k";
    constexpr std::string_view outputFileSwitch = "-o";
    constexpr std::string_view maxLengthToAnalyseSwitch = "-m";
    constexpr std::string_view helpMessage = "Usage: ./main [flag] [options]\n"
                                             "\n"
                                             "Flags:\n"
                                             "--en               Encrypt text file using Vigenère cipher\n"
                                             "--de               Decrypt text file using Vigenère cipher\n"
                                             "--br               Break ciphertext encrypted with an unknown key\n"
                                             "--br-key-len       Find the key length of a ciphertext with an unknown key\n"
                                             "\n"
                                             "Options:\n"
                                             "-i                 Input text file\n"
                                             "-o                 Output text file\n"
                                             "-k                 Text file containing the encryption/decryption key\n"
                                             "-m                 Max length of text to analyze, default: unlimited\n"
                                             "-k-len             Specify the key length when breaking the cipher (--br)\n"
                                             "\n"
                                             "Additional Features:\n"
                                             "  --br-key-len     Find the key length of a ciphertext with an unknown key\n"
                                             "  -k-len           Specify the key length when breaking the cipher (--br)\n"
                                             "\n"
                                             "Run with --help <option> for more info about a specific option or flag\n";
}

#endif //VIGENEREENCRYPTION_CONSTANTS_H
