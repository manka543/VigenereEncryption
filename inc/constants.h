#ifndef VIGENEREENCRYPTION_CONSTANTS_H
#define VIGENEREENCRYPTION_CONSTANTS_H

namespace Constants {
    constexpr std::string_view encryptFlag = "--en";
    constexpr std::string_view decryptFlag = "--de";
    constexpr std::string_view breakingKeyFlag = "--br";
    constexpr std::string_view inputFileSwitch = "-i";
    constexpr std::string_view keyFileSwitch = "-k";
    constexpr std::string_view outputFileSwitch = "-o";
    constexpr std::string_view maxLengthToAnalyse = "-m";
    constexpr std::string_view helpMessage = "Usage: ./main [flag] [options]\n"
                                    "\n"
                                    "Flags:\n"
                                    "--en               Encrypt text file using Vigenère cipher\n"
                                    "--de               Decrypt text file using Vigenère cipher\n"
                                    "--br               Break ciphertext encrypted with an unknown key\n"
                                    "\n"
                                    "Options:\n"
                                    "-i         Input text file\n"
                                    "-o         Output text file\n"
                                    "-k         Text file containing the encryption/decryption key\n"
                                    "-m         Max length of text to analyse, default: unlimited\n"
                                    "Run with --help <option> for more info about specific option or flag\n";
}

#endif //VIGENEREENCRYPTION_CONSTANTS_H
