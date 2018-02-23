//
// Created by Ron on 2/23/18.
//

#include <iostream>
#include <fstream>
#include <map>
#include <regex>
#include "rounsifer.h"

using namespace std;

int main() {
    // testing map data structure
    map <string, int> word_map; // empty map container
    regex r("[^A-Za-z]+");
    smatch m;

    ifstream inFile;
    ofstream outFile;
    string word;
    inFile.open("input.txt");
    outFile.open("output.txt");
    while (inFile >> word)
    {
        outFile << word << "\n";
        // convert to lowercase
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        // checks if the word is in the map
        // if not it adds it to it
        if (word_map.find(word) == word_map.end()){
            word_map.insert(map<string, int>::value_type(word, 1));
        }
        else if (word_map.find(word) != word_map.end()) {
            word_map.find(word)->second++;
        }
    }


    // checks if the key is not an actual word
    // if true, it then deletes the key
    for(auto it = word_map.begin(); it != word_map.end();it++)
    {
        if(regex_search(it->first, m, r))
            word_map.erase(it);

    }


    // Prints for debugging
    for(auto it = word_map.begin(); it != word_map.end();it++)
    {
        cout << it->first << ':' << it->second << endl;
    }


    inFile.close();
    outFile.close();

    // for each word that is read in, add it to the map
    // if the word is already stored in the map, increment count by 1
    // if the word is not included in the map, add and set counter to 1


    return 0;
}
