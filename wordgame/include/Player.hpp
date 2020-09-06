#include <iostream>

/*
*   Player class to keep correct word count and error count
*/
class Player{
    private:
        int playerScore;
        int playerError;
    public:
        Player();
        void setScore(int i);
        int getScore();
        void setError(int i);
        int getError();

};