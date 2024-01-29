#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

bool isEnglishWord(const std::string& word) {
    for (char c : word) {
        if (!isalpha(c))
            return false;
    }
    return true;
}

void addSpacesBetweenWords(std::string& line) {
    std::istringstream iss(line);
    std::ostringstream oss;
    std::string word;

    while (iss >> word) {
        if (isEnglishWord(word))
            oss << word << " ";
        else
            oss << word;
    }

    line = oss.str();
}

int main() {
    std::ifstream inputFile("myfile.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    std::string line;

    while (std::getline(inputFile, line)) {
        addSpacesBetweenWords(line);
        outputFile << line << '\n';
    }

    std::cout << "Spaces added between English words. Check output.txt." << std::endl;

    return 0;
}