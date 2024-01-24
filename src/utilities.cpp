
#include "../inc/utilities.h"

void Utilities::saveTextToFile(std::string &path, std::string &text) {
    std::ofstream fileStream(path);
    fileStream << text;
    fileStream.close();
}

std::string Utilities::loadTextFromFile(std::string &path) {
    std::ifstream fileStream(path);
    std::string text{}, tmpText{};
    while (std::getline(fileStream, tmpText)) {
        text += tmpText + '\n';
    }

    fileStream.close();
    return text;
}

char Utilities::moveLetter(char &letter, char &key) {
    if (letter >= 'a' && letter <= 'z') {
        if (letter + key - 'a' > 'z') {
            return char(letter + key - 'z' - 1);
        } else {
            return char(letter + key - 'a');
        }
    } else if (letter >= 'A' && letter <= 'Z') {
        if (letter + key - 'a' > 'Z') {
            return char(letter + key - 'z' - 1);
        } else {
            return char(letter + key - 'a');
        }
    } else {
        return letter;
    }
}

char Utilities::undoLetter(char &letter, char &key) {
    if (letter >= 'a' && letter <= 'z') {
        if (letter - key + 'a' < 'a') {
            return char(letter - key + 'z' + 1);
        } else {
            return char(letter - key + 'a');
        }
    } else if (letter >= 'A' && letter <= 'Z') {
        if (letter - key + 'a' < 'A') {
            return char(letter - key + 'z' + 1);
        } else {
            return char(letter - key + 'a');
        }
    } else {
        return letter;
    }
}

bool Utilities::validateInput(flags &pickedMode, FilePaths &filePaths) {
    switch (pickedMode) {
        case flags::encrypt:
        case flags::decrypt:
        case flags::breakingKeyLength:
        case flags::breakingKey: {
            return !filePaths.inputFile.empty() && !filePaths.outputFile.empty() && !filePaths.keyFile.empty();
        }
        default:// it should never happen
        case flags::error: {
            return false;
        }
    }
}

std::string Utilities::cleanText(std::string &cypherText, int &textLengthToAnalyse) {
    std::string cleanText = {};

    for (char let: cypherText.substr(0, (textLengthToAnalyse < cypherText.length() && textLengthToAnalyse != 0 ? textLengthToAnalyse : cypherText.length()))) {
        if (isalpha(let)) {
            cleanText += (char) tolower(let);
        }
    }
    return cleanText;
}

void Utilities::saveKeyLengthScores(std::string &path, std::vector<std::pair<int, int>> &keyScores) {
    std::ofstream fileStream{path};
    if(fileStream){
        for(int i = 0; i < (10 < keyScores.size() ? 10 : keyScores.size()); i++){
            fileStream << keyScores[i].first << ": " << keyScores[i].second*100/keyScores[0].second << " pkt\n";
        }
        fileStream.close();
    }
}
