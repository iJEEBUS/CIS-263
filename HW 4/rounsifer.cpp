#include <iostream>
#include <fstream>
#include <map>
#include <regex>

int main() {
    std::map <std::string, int> word_map; // empty map container
    std::regex r("^[^a-zA-Z]+$"); // a string has to consist of letters
    std::regex a("(a)");
    std::regex d("(the)");
    std::smatch m; // regex matches

    std::ifstream inFile;
    std::ofstream outFile;
    std::string word;
    std::string last_char;
    inFile.open("input.txt");
    outFile.open("output.txt");
    while (inFile >> word)
    {
        // convert to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
	// last character of "word" - used to check for periods
	last_char = word.substr(word.size() - 1, word.size()-1);
        
	// Checks for period in strings
	// If detected, check for an existing string of the same word minus the period.
	// If not detected, check for the string.
        if (last_char.compare(".") == 0 && word_map.find(word.substr(0,word.size()-1)) == word_map.end()) {
            word_map.insert(std::map<std::string, int>::value_type(word.substr(0,word.size()-1), 1));
        }
        else if (last_char.compare(".") && word_map.find(word.substr(0,word.size()-1)) != word_map.end()) {
            word_map.find(word)->second++;
        }
        else if (word_map.find(word) != word_map.end()){
            word_map.find(word)->second++;
        }
        else if (word_map.find(word) == word_map.end()) {
            word_map.insert(std::map<std::string, int>::value_type(word, 1));
        }
    }

    // Sets value to 0 if not a word
    for(auto it = word_map.begin(); it != word_map.end(); it++)
    {
	// FIX THIS
	// Figure out how to combine all three regex values into one
        if (regex_match(it->first, m, r) | regex_match(it->first, m, a) | regex_match(it->first, m, d))
            word_map[it->first] = 0;

        if (it->second > 0)
		outFile << it->first << ' ' << it->second << "\n";
    }
    inFile.close();
    outFile.close();

    return 0;
}