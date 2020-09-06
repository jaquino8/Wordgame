#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "random.hpp"
#include "WordList.hpp"
using Random = effolkronium::random_static;

/*
*   WordList class creates a vector called wordList that stores the text from a text file into a random order
*/

//Constructor
/*
* Takes text file and pushes words into a random order to the wordList vector of strings
*/
std::string str;
WordList::WordList(){
    std::ifstream in("./resources/1-1000.txt");
    int listSize = 1000;
    while(getline(in,str) && listSize > 0)
    {
        if(str.size()>0)
		    this->wordList.push_back(str);
            
        listSize-=1;
    }

    randomize(wordList);
}

//Returns the created string vector
std::vector<std::string> WordList::getWordList(){
    return this->wordList;
}

int WordList::getSize(){
    return this->wordList.size();
}

std::string WordList::getWord(int i){
    return this->wordList[i];
}

/*
*   takes the vector of words inputted from text file
*   and randomizes the order of them
*   resets the original wordlist into a randomized version of it
*   so words arent the same order every time
*/
void WordList::randomize(std::vector<std::string> wordList){
    std::vector<std::string> randWords(wordList.size());

    for(int i = 0; i < (int)wordList.size(); i++){
        randWords.at(Random::get(0,(int)wordList.size()-1)) = wordList[i];
    }

    this->wordList = randWords;

}

void WordList::deleteWord(int index){
    this->wordList[index] = "";
}
