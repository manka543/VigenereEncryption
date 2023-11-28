#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/decrypt.h"
#include "inc/flags.h"
#include "inc/filePathStruct.h"


constexpr std::string encryptFlag = "--en";
constexpr std::string decryptFlag = "--de";
constexpr std::string breakingKeyFlag = "--br";
constexpr std::string inputFileSwitch = "-i";
constexpr std::string outputFileSwitch = "-o";
constexpr std::string keyFileSwitch = "-k";

int main(int argv, char *argc[] ) {
    flags pickedMode {flags::error};
    FilePaths filePaths = {};
    int argsEvaluated {1}; // we ignore first arg because is path to executable file
    while(argsEvaluated < argv){
        std::string currentArg = argc[argsEvaluated];
        if (currentArg==encryptFlag){
            pickedMode = flags::encrypt;
        } else if (currentArg == decryptFlag) {
            pickedMode = flags::decrypt;
        } else if (currentArg == breakingKeyFlag) {
            pickedMode = flags::breakingKey;
        } else if(currentArg == inputFileSwitch && argsEvaluated + 1 < argv){
            filePaths.inputFile = argc[argsEvaluated + 1];
        } else if(currentArg == outputFileSwitch && argsEvaluated + 1 < argv){
            filePaths.outputFile = argc[argsEvaluated + 1];
        } else if(currentArg == keyFileSwitch && argsEvaluated + 1 < argv){
            filePaths.keyFile = argc[argsEvaluated + 1];
        } else {
            // do nothing
        }
        argsEvaluated++;
    }
    if(!Utilities::validateInput(pickedMode, filePaths)){
        std::cout<<"Your input is wrong"<<std::endl;
    }

    std::cout<<"Selected mode: "<<static_cast<int>(pickedMode) << std::endl;
    std::cout<<"Provided files: input - \""<<filePaths.inputFile<<"\" output - \""<<filePaths.outputFile<<"\" key - \""<<filePaths.keyFile<<"\"\n";
    std::string text {"testowy tekst bo trzeba sprawdzic czy dziala bo to nie jest pewne a testowanie jest bardzo wazne\na tu sprawdzamy czy druga linijka tez bedzie dobrze dzialac"}, key {"alamakota"};
    text = Encrypt::encrypt(text, key);
    std::cout<<"encrypted: "<<text<<std::endl;
    std::cout<<"decrypted: "<<Decrypt::decrypt(text, key);
    return 0;
}
