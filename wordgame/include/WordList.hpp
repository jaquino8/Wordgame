#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "random.hpp"
using Random = effolkronium::random_static;

/*
*   WordList class creates a vector called wordList that stores the text from a text file into a random order
*/



class WordList{
    private:
        std::vector<std::string> wordList;
    public:
        //Constructor
        /*
        *   Takes text file and pushes words into a random order to the wordList vector of strings
        */
        WordList();

        std::vector<std::string> getWordList();

        int getSize();

        std::string getWord(int i);

        /*
        *   takes the vector of words inputted from text file
        *   and randomizes the order of them
        *   resets the original wordlist into a randomized version of it
        *   so words arent the same order every time
        */
        void randomize(std::vector<std::string> wordList);
        void deleteWord(int index);
        
};