#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/decrypt.h"
#include "inc/flags.h"

constexpr std::string encryptFlag = "--en";
constexpr char decryptFlag[] = "--de";
constexpr char breakingKeyFlag[] = "--br";
constexpr char inputFileSwitch[] = "-i";
constexpr char outputFileSwitch[] = "-o";
constexpr char keyFileSwitch[] = "-k";

int main(int argv, char *argc[] ) {
    flags pickedMode {flags::error};
    for(int i = 1; i < argv; i++){
        if(argc[i][0] == '-'){
            if(argc[i][1] == '-'){

            }
        }
    }

    std::string text {"testowy tekst bo trzeba sprawdzic czy dziala bo to nie jest pewne a testowanie jest bardzo wazne\na tu sprawdzamy czy druga linijka tez bedzie dobrze dzialac"}, key {"alamakota"};
    text = Encrypt::encrypt(text, key);
    std::cout<<"encrypted: "<<text<<std::endl;
    std::cout<<"decrypted: "<<Decrypt::decrypt(text, key);
    return 0;
}
