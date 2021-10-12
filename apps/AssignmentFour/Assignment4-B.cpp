#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

list<string> wordlist;

void readWords() {
    ifstream in("test.txt");
    string word;
    if (!in)   return;
    while (in >> word)
        wordlist.push_back(word);
}


multimap<string, string> dictionary;

void getKeyTexts() {
    // NB. Need to change comparator to caseless!!

    string first, second, key, fourth, fifth;

    first = second = key = fourth = fifth = "";
    for (list<string>::iterator ai = wordlist.begin(); ai != wordlist.end(); ++ai) {
        if (first != "") {
            string text = first + " " + second + " " + key + " " + fourth + " " + fifth;
            dictionary.insert(pair<string, string>(key, text));
        }
        first = second; second = key; key = fourth; fourth = fourth; fourth = *ai;
    }
}

int main() {
    // input --> list of words
    readWords();
    for (list<string>::iterator ai = wordlist.begin(); ai != wordlist.end(); ++ai)
        cout << *ai << " ";
    cout << endl << endl;

    // keys --> texts
    getKeyTexts();

    // texts --> output
    multimap<string, string>::iterator it = dictionary.begin();
    while (it != dictionary.end()) {
        cout << it->second << endl;
        it++;
    }

    return 0;
}