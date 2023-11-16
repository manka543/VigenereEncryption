
#include "../inc/utilities.h"

void Utilities::saveTextToFile(std::string &path, std::string &text) {
    std::ofstream fileStream(path);
    fileStream<<text;
    fileStream.close();
}

std::string Utilities::loadTextFromFile(std::string &path) {
    std::ifstream fileStream(path);
    std::string text {}, tmpText {};
    while(std::getline(fileStream, tmpText))
    {
        text += tmpText+ '\n';
    }

    fileStream.close();
    return text;
}

char Utilities::moveLetter(char &letter, char &key){
    if(letter >= 'a' && letter <= 'z'){
        if (letter + key - 'a' > 'z'){
            return  char(letter + key - 'z' - 1);
        }
        else {
            return char(letter + key - 'a');
        }
    } else if (letter >= 'A' && letter <= 'Z') {
        if (letter + key - 'a' > 'Z'){
            return char(letter + key - 'z' - 1);
        }
        else {
            return char(letter + key - 'a');
        }
    } else {
        return letter;
    }
}

char Utilities::undoLetter(char &letter, char &key) {
    if(letter >= 'a' && letter <= 'z'){
        if (letter - key + 'a' < 'a'){
            return char(letter - key + 'z' + 1);
        } else {
            return char(letter - key + 'a');
        }
    } else if (letter >= 'A' && letter <= 'Z'){
        if(letter - key + 'a' > 'Z'){
            return char(letter - key + 'z');
        } else {
            return char(letter - key + 'a');
        }
    } else {
        return letter;
    }
}