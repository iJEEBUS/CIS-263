#include <iostream>
#include <fstream>
#include <map>
#include <regex>

int main() {
    const char *last_char; // used for punctuation testing
    std::map<std::string, int> word_map; // empty map container
    std::regex r("(^[^a-zA-Z]+$|(a)|(the))"); // regex = non-letters | a | the
    std::smatch m; // regex matches
    std::ifstream inFile;
    std::ofstream outFile;
    std::string word;
    inFile.open("input.txt");
    outFile.open("output.txt");

    while (inFile >> word) {
        last_char = word.substr(word.size() - 1, word.size() - 1).c_str();

        // convert word to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // Checks for punctuation at the end of words to make sure we do
        // not have duplicates (Ex...files - files. || tests - tests?)
        if (ispunct((int) *last_char) != 0) {
            if (word_map.find(word.substr(0, word.size() - 1)) == word_map.end())
                word_map.insert(std::map<std::string, int>::value_type(word.substr(0, word.size() - 1), 1));
            if (word_map.find(word.substr(0, word.size() - 1)) != word_map.end())
                word_map.find(word)->second++;
        } else if (word_map.find(word) != word_map.end()) {
            word_map.find(word)->second++;
        } else if (word_map.find(word) == word_map.end()) {
            word_map.insert(std::map<std::string, int>::value_type(word, 1));
        }
    }

    // Sets value to 0 if not a word and writes counted words to file
    for (auto it = word_map.begin(); it != word_map.end(); it++) {
        if (regex_match(it->first, m, r))
            word_map[it->first] = 0;

        if (it->second > 0)
            outFile << it->first << ' ' << it->second << "\n";
    }
    inFile.close();
    outFile.close();

    return 0;
}