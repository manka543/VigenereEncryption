#include <iostream>
#include "inc/utilities.h"
#include "inc/encrypt.h"
#include "inc/decrypt.h"


int main(int argv, char *argc[] ) {
    std::string text {"testowy tekst bo trzeba sprawdzic czy dziala bo to nie jest pewne a testowanie jest bardzo wazne\na tu sprawdzamy czy druga linijka tez bedzie dobrze dzialac"}, key {"alamakota"};
    text = Encrypt::encrypt(text, key);
    std::cout<<"encrypted: "<<text<<std::endl;
    std::cout<<"decrypted: "<<Decrypt::decrypt(text, key);
    return 0;
}
