#include "Player.hpp"

/*
*Player class to keep correct word count and error count
*/

Player::Player(){
    this->playerScore = 0;
    this->playerError = 0;
}


void Player::setScore(int i){
    this->playerScore += i;
}

int Player::getScore(){
    return this->playerScore;
}

void Player::setError(int i){
    this->playerError += i;
}

int Player::getError(){
    return this->playerError;
}