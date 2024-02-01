
/**
 * @file constants.h
 * @brief Header file containing constant values for Vigenere Encryption program.
 */

#ifndef VIGENEREENCRYPTION_CONSTANTS_H
#define VIGENEREENCRYPTION_CONSTANTS_H

namespace Constants {


    constexpr std::string_view encryptFlag = "--en";
    constexpr std::string_view decryptFlag = "--de";
    constexpr std::string_view breakingKeyFlag = "--br";
    constexpr std::string_view onlyFindKeyLengthFlag = "--br-key-len";
    constexpr std::string_view specifyKeyLengthSwitch = "-k-len";
    constexpr std::string_view inputFileSwitch = "-i";
    constexpr std::string_view keyFileSwitch = "-k";
    constexpr std::string_view outputFileSwitch = "-o";
    constexpr std::string_view maxLengthToAnalyseSwitch = "-m";
    /**
     * @brief Help message providing information about program usage.
     */
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
                                             "Run with --help <Flag> for more info about a specific option or flag\n";
    constexpr std::string_view helpFlag = "--help";
    constexpr std::string_view encryptHelpMessage = "Usage: ./main --en -i <file with text to encrypt> -o <file to save encrypted text> -k <file with encryption key>\n"
                                                    "\n"
                                                    "Input file: The entire text that will be encrypted using the Vigenère cipher. Remember that only characters from the range 'A'-'Z' and 'a'-'z' are encrypted. In the case of other characters, the program will continue by ignoring them.\n"
                                                    "Output file: Destination file for the cipher text.\n"
                                                    "Key file: File with the encryption key. Remember that the key should contain only characters from 'a'-'z'. Capital letters are transformed to lowercase ones. End lines, spaces, and any other characters are ignored. If, after validation, the key is empty, the program will stop.";
    constexpr std::string_view decryptHelpMessage = "Usage: ./main --de -i <file with cipher text> -o <file to save decrypted text> -k <file with decryption key>\n"
                                                    "\n"
                                                    "Input file: The entire text that will be decrypted using the Vigenère cipher. Remember that only characters from the range 'A'-'Z' and 'a'-'z' are decrypted. In the case of other characters, the program will continue by ignoring them.\n"
                                                    "Output file: Destination file for plain text.\n"
                                                    "Key file: File with the decryption key. Remember that the key should contain only characters from 'a'-'z'. Capital letters are transformed to lowercase ones. End lines, spaces, and any other characters are ignored. If, after validation, the key is empty, the program will stop.";
    constexpr std::string_view breakEncryptionHelpMessage = "Usage: ./main --br -i <file with cipher text> -o <file to save decrypted text>\n"
                                                            "\n"
                                                            "Input file: Text to analyze for guessing the key. Remember that only characters from the range 'A'-'Z' and 'a'-'z' are analyzed. In the case of other characters, the program will continue by ignoring them.\n"
                                                            "Output file: Destination file for plain text.\n"
                                                            "OPTIONAL - Key file ( -k <key file> ): File to save the key established on the given text.\n"
                                                            "OPTIONAL - Key length ( -k-len <int> ): You can manually specify the key length. In this case, the program will skip finding the key length and go straight to searching for the shift for each letter in the key using frequency analysis.\n"
                                                            "OPTIONAL - Length of analyzed text ( -m <int>): You can limit the analyzed text. It is useful in the case of very long input text. Sometimes it is not required to use the whole text to find the key, and in such a case, you can use this switch.\n"
                                                            "\n"
                                                            "How it works:\n"
                                                            "First, the program tries to establish the length of the key used to encrypt the message. The method used for that is Kasiski Examination, which is based on analyzing gaps between repetitions in cipher text. The minimum length of such repetition is 3. When the program finds such a repetition, it adds all factors (minimum is 2) of the distance from them. So, if the distance is 32, the program increments the score for 2, 4, 8, 16, 32. Such a scoring system generates some problems. If the real key length is e.g. 16, in the perfect situation, the score for 16 would be the same as for 8, 4, and 2, because of incrementing the score for every divisor except 1. It is impossible to choose the number with the highest score because, in most cases, it would be 2 or 3, depending on the real key length. This is a result of the fact that not every repetition is caused by encrypting the same text with the same key fragment. Some of them are random. In a real example, the most probable score for the key should be near 90 points, and the score for two times bigger should be around half of that. The program, by default, chooses the highest key length with at least 70 points. It works for most cases.\n"
                                                            "When the key length is evaluated, the program uses frequency analysis for each letter of the key. It is done the same as for a normal Caesar Cipher. REMEMBER that each language has a different frequency of letters, and in this version of the program, only the English language is supported.\n"
                                                            "\n"
                                                            "How to deal with incorrect output?\n"
                                                            "Most errors are because of the wrong evaluation of the key length. In such a case, you can try running it with the --br-key-len flag and choose the key length manually. Then run with -k-len and specify the most probable key length in your opinion.";
    const std::string_view breakKeyLengthHelpMessage = "Usage: ./main --br-key-len -i <file with cipher text> -k <file to save scores for key lengths>\n"
                                                       "\n"
                                                       "Input file: Text to analyze for guessing the key. Remember that only characters from the range 'A'-'Z' and 'a'-'z' are analyzed. In the case of other characters, the program will continue by ignoring them. Run './main --br-key-len --help' for more info.\n"
                                                       "Key file: Destination file for different key length scores.\n"
                                                       "\n"
                                                       "How to use it?\n"
                                                       "Message format:\n"
                                                       "3: 100 pts\n"
                                                       "9: 96 pts // <- Key length. It has around 100 pts\n"
                                                       "2: 66 pts\n"
                                                       "6: 58 pts\n"
                                                       "18: 56 pts // <- Key length times two usually have half of key length points\n"
                                                       "4: 34 pts\n"
                                                       "12: 30 pts\n"
                                                       "36: 28 pts\n"
                                                       "7: 26 pts\n"
                                                       "27: 26 pts\n"
                                                       "When you find the key length, run the program with the specified key length. Run './main --br --help' for more info.\n";
}

#endif //VIGENEREENCRYPTION_CONSTANTS_H
