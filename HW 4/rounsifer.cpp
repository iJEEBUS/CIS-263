//
// Created by Ron on 2/23/18.
//

#include <iostream>
#include <fstream>
#include <map>
#include <regex>

using namespace std;

int main() {
    // testing map data structure
    map <string, int> word_map; // empty map container
    map <string, int> temp_map; // temp map container
    regex r("^[^a-zA-Z]+$"); // a string has to consist of letters
    regex a("(a)");
    regex d("(the)");
    smatch m; // regex matches

    ifstream inFile;
    ofstream outFile;
    string word;
    string last_char;
    inFile.open("input.txt");
    outFile.open("output.txt");
    while (inFile >> word)
    {
        // convert to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        last_char = word.substr(word.size() - 1, word.size()-1);
        last_char = word.substr(word.size() - 1, word.size()-1);
        // checks if the word is in the map
        // if not it adds it to it

        if (last_char.compare(".") == 0 && word_map.find(word.substr(0,word.size()-1)) == word_map.end()) {
            word_map.insert(map<string, int>::value_type(word.substr(0,word.size()-1), 1));
        }
        else if (last_char.compare(".") && word_map.find(word.substr(0,word.size()-1)) != word_map.end()) {
            word_map.find(word)->second++;
        }
        else if (word_map.find(word) != word_map.end()){
            word_map.find(word)->second++;
        }
        else if (word_map.find(word) == word_map.end()) {
            word_map.insert(map<string, int>::value_type(word, 1));
        }
    }

    // Checks each item in the original map
    // if it is a not word, set its value to 0
    for(auto it = word_map.begin(); it != word_map.end(); it++)
    {
        // Second condition checks for the end of a sentence
        // E.g. ending in a period/question mark/etc...
        if (regex_match(it->first, m, r) |
                regex_match(it->first, m, a) |
                regex_match(it->first, m, d))
        {
            word_map[it->first] = 0;
        }

        if (it->second > 0)
        {
            outFile << it->first << ' ' << it->second << "\n";
            cout << it->first << ' ' << it->second << endl;
        }

    }

    inFile.close();
    outFile.close();

    // for each word that is read in, add it to the map
    // if the word is already stored in the map, increment count by 1
    // if the word is not included in the map, add and set counter to 1


    return 0;
}
