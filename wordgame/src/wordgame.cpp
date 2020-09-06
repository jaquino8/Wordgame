#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "WordList.hpp"
#include "TextDisplay.hpp"
#include "Player.hpp"
#include "random.hpp"
using Random = effolkronium::random_static;

//Restricts Y position of word to a particlar range, but still adds a bit of randomness
float getRandHeight(int row){
    switch(row){
        case 0: return 50.0f;
                break;
        case 1: return 70.0f;
                break;
        case 2: return 90.0f;
                break;
        case 3: return 110.0f;
                break;
        case 4: return 130.0f;
                break;
        case 5: return 150.0f;
                break;
        case 6: return 170.0f;
                break;
        case 7: return 190.0f;
                break;
        case 8: return 210.0f;
                break;
        case 9: return 230.0f;
                break;
        case 10: return 250.0f;
                break;
        case 11: return 270.0f;
                break;
        case 12: return 290.0f;
                break;
        case 13: return 310.0f;
                break;
        case 14: return 330.0f;
                break;
        case 15: return 350.0f;
                break;
        case 16: return 370.0f;
                break;
        case 17: return 380.0f;
                break;
        case 18: return 390.0f;
                break;
        case 19: return 410.0f;
                break;
        case 20: return 430.0f;
                break;
        case 21: return 450.0f;
                break;
        case 22: return 470.0f;
                break;
        case 23: return 490.0f;
                break;
        case 24: return 510.0f;
                break;
        default: return 510.0f;
                break;
    }
}

/** findWord() function to find word in word list
 *      takes user input string and searches list of words that were generated
 *      if the word is found in the list, then the function finds the location of that word in list vector
 *      the same location should be within the words vector
 * 
 *      after the index is found it changes makes the word blank, thus causing it to dissapear from screen
 * */
void findWord(std::vector<sf::Text> &words, WordList &list, TextDisplay &userInput, sf::Sound &correct, sf::Sound &wrong, Player &player){
	//iterate through list vector - list of words generated to become sf::Text and stored in words vector
        std::vector<std::string>::iterator it;
	std::vector<std::string> searchList = list.getWordList();
	std::string word = userInput.GetTextDisplayText();
        it = std::find (searchList.begin(), searchList.end(), word); 
        
        //if user input IS found
        if (it != searchList.end()){ 
		//calculates distance between beginning of array to location of found word in list
		int index = std::distance(searchList.begin(), it);
			
		//if word is found out of screen
		if ((int)words[index].getPosition().x > 1100 || (int)words[index].getPosition().x < 0){
			//add 1 to error count
			player.setError(1);
			//play error sound
			wrong.play();
		}
				
		else{
			//add 1 to player score
			player.setScore(1);
			//play correct sound
			correct.play();
			//removes word from screen by setting it to blank
			words[index].setString("");
			//erases word from index
			list.deleteWord(index);
		}
	} 
			
        //if user input IS NOT found
        else{       
		//add 1 to player error count
		player.setError(1);
		//play sound that user word was not found - incorrect
		wrong.play();
	}
}
	
int main(){
	//set window size to const so it cant be changed
	const int gameWidth = 1100;
	const int gameHeight = 600;
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "EE 205 Final Project", 
	sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	//window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
		
	//intialize player to keep track of correct words and errors
	Player player;
		
	//title page graphic creation
	sf::Texture titleGraphic;
	if(!titleGraphic.loadFromFile("resources/gamebegin.png"))
		return EXIT_FAILURE;
	sf::Sprite titlePage;
	titlePage.setTexture(titleGraphic);
		
	//load font for end screen/title screen (current only for end screen)
	sf::Font font;
	if (!font.loadFromFile("resources/keyboard.ttf"))
		return EXIT_FAILURE;
		
	//Load sound effects for input
	sf::SoundBuffer buffCorrect;
	if (!buffCorrect.loadFromFile("./resources/correct.wav"))
		return EXIT_FAILURE;

	sf::Sound correct;
	correct.setBuffer(buffCorrect);

	sf::SoundBuffer buffWrong;
		if (!buffWrong.loadFromFile("./resources/wrong.wav"))
			return EXIT_FAILURE;

	sf::Sound wrong;
	wrong.setBuffer(buffWrong);

	//Create sf::Text for user input
		std::string input;
		sf::String string;
		TextDisplay userInput;
		sf::FloatRect inputRect = userInput.GetTextDisplayLocal();
		userInput.SetTextDisplayOrigin(inputRect.left + inputRect.width/2.0f, inputRect.top + inputRect.height/2.0f);
		userInput.SetTextDisplaySize(20);
		userInput.SetTextDisplayPosition(gameWidth/2,550);
		
	//Display for game to show where users input is being displayed
		TextDisplay userInterfaceInput(inputRect.left + inputRect.width/2.0f, inputRect.top + inputRect.height/2.0f);
		userInterfaceInput.SetTextDisplaySize(20);
		userInterfaceInput.SetTextDisplayPosition(userInput.GetTextDisplayPositionx()-75, userInput.GetTextDisplayPositiony());
		userInterfaceInput.SetTextDisplayText("Input: ");
		
	//Display for current correct word count
		std::string correctWords;
		correctWords = "Correct: " + std::to_string(player.getScore());
		TextDisplay userScoreCorrect(inputRect.left + inputRect.width/2.0f, inputRect.top + inputRect.height/2.0f);
		userScoreCorrect.SetTextDisplaySize(20);
		userScoreCorrect.SetTextDisplayPosition(userInput.GetTextDisplayPositionx()-300, userInput.GetTextDisplayPositiony());
		userScoreCorrect.SetTextDisplayText(correctWords);
		
	//Display for current error count
		std::string errors;
		errors = "Error: " + std::to_string(player.getError());
		TextDisplay userScoreErr(inputRect.left + inputRect.width/2.0f, inputRect.top + inputRect.height/2.0f);
		userScoreErr.SetTextDisplaySize(20);
		userScoreErr.SetTextDisplayPosition(userInput.GetTextDisplayPositionx()-500, userInput.GetTextDisplayPositiony());
		userScoreErr.SetTextDisplayText(errors);
		
	//Generate random word list vector
		WordList list;
	
	//output to terminal how much words currently within list - can be changed in WordList.cpp
		//std::cout << list.getSize() << std::endl;
		
	//Vector of text to display in window
		std::vector<sf::Text> words;
		
	//Creating font for sf::Text words
		sf::Font typeThis;
		if (!typeThis.loadFromFile("resources/typewriter.ttf"))
        		return EXIT_FAILURE;
		
	//Generate sf::Text words to be pushed into words vector
		for(int w = 0; w < (int)list.getSize(); w++){
			sf::Text word;
			//set string of the sf::text to word from WordList list
			word.setString(list.getWord(w));
			word.setFont(typeThis);
			word.setCharacterSize(20);
			sf::FloatRect wordRect = word.getLocalBounds();
			word.setOrigin(wordRect.left, wordRect.top + wordRect.height/2.0f);
			word.setFillColor(sf::Color::White);
			words.push_back(word);
		}
			
	//Generate clock to limit gametime to 60 seconds
		sf::Clock clock;
		sf::Time time = clock.getElapsedTime();
		
	//Display for timer on bottom right of screen to show time elapsing
		TextDisplay timer(inputRect.left + inputRect.width/2.0f, inputRect.top + inputRect.height/2.0f);
		timer.SetTextDisplaySize(20);
		timer.SetTextDisplayPosition(userInput.GetTextDisplayPositionx()+200, userInput.GetTextDisplayPositiony());
		timer.SetTextDisplayText("Time: ");
		
	//Display for actual time lapsing
		TextDisplay timerSec(inputRect.left + inputRect.width/2.0f, inputRect.top + inputRect.height/2.0f);
		timerSec.SetTextDisplaySize(20);
		timerSec.SetTextDisplayPosition(userInput.GetTextDisplayPositionx()+280, userInput.GetTextDisplayPositiony());
		timerSec.SetTextDisplayText(std::to_string(time.asSeconds()));
		
	//Display for end of game screen - displays total correct words and errors (needs improvement)
		std::string finalScore;
		finalScore = "Game Over! \nCorrect Words: " + std::to_string(player.getScore()) + "\nErrors: " +
		       	std::to_string(player.getError());
		TextDisplay endGame;
		endGame.SetTextDisplayText(finalScore);
		sf::FloatRect textRect = endGame.GetTextDisplayLocal();
		endGame.SetTextDisplayOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
		endGame.SetTextDisplaySize(30);
		endGame.SetTextDisplayPosition(gameWidth/2.0f,gameHeight/2.0f);
		
		
	//Boolean to set if playing/not playing
		bool isPlaying = false;
		
	//set initial(random) positions for the words
		for(int j = 0;j < (int)words.size();j++){
			//x position starts negative so off screen
				float xPos = (float)Random::get((int)-50000,0);
			
			//calls switch statement to get set values for y but still random
				float yPos = getRandHeight(Random::get((int)0,24));
				words[j].setPosition(xPos,yPos);
				
			//additional step to try to decrease overlapping words
				if(j>0){
					if (words[j].getLocalBounds().intersects(words[j-1].getLocalBounds())){
						yPos = getRandHeight(Random::get((int)0,24));
						words[j].setPosition(sf::Vector2f(xPos,yPos));
					}
				}
		}
			
		while (window.isOpen()){
			if((int)time.asSeconds() >= 60){
				isPlaying = false;
                	}
        		
		// check all the window's events that were triggered since the last iteration of the loop
			sf::Event event;
			while (window.pollEvent(event)){
                		// "close requested" event: we close the window
                			if (event.type == sf::Event::Closed){
                        			window.close();  
                				}
						
                		//Press spacebar to start game
                			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
					{
						if ((float)time.asSeconds() >= 60.0f){
							isPlaying = false;
						}
						else if (!isPlaying)
						{
							isPlaying = true;
							clock.restart();
						}
                        			if(string.getSize() == 0)
						{
							string = "";
							userInput.SetTextDisplayText(string);
                        			}
                			}
                			
						//Pause the game and return to title screen
						if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
						{
							if((int)time.asSeconds() > 60)
							{
								break;
							}

							isPlaying = false;
						}							
				
                		//Get User Input for word
                			if ((event.type == sf::Event::TextEntered) && (event.text.unicode != 8) &&
							(event.text.unicode != '\b') && (event.text.unicode != '\n') && (event.text.unicode != ' ')
							&& (event.text.unicode != '\r')){
							string += static_cast<char>(event.text.unicode);
								userInput.SetTextDisplayText(string);
                        		correctWords = "Correct: " + std::to_string(player.getScore());
								userScoreCorrect.SetTextDisplayText(correctWords);
                        		errors = "Error: " + std::to_string(player.getError());
								userScoreErr.SetTextDisplayText(errors);
								userInput.SetTextDisplayColor();
                			}
						
                		//Allow backspace to edit character
                			if ((event.type == sf::Event::TextEntered) && (event.text.unicode == '\b')){
                        			if(string.getSize() == 0){
                                			break;
                        				}
                        			else{
                        				string.erase(string.getSize()-1,1);
										userInput.SetTextDisplayText(string);
                        				correctWords = "Correct: " + std::to_string(player.getScore());
										userScoreCorrect.SetTextDisplayText(correctWords);
                        				errors = "Error: " + std::to_string(player.getError());
										userScoreErr.SetTextDisplayText(errors);
                        				}
                				}
						
                		//User press enter to compare word to words shown
                        		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return)){
                                		//find word in word list when press Enter
                                			if(string.getSize() == 0){
                                				std::cout << "This happened.\n";
                                				break;
                                				}
                                			findWord(words, list, userInput, correct, wrong, player);
                                			string.clear();
											userInput.SetTextDisplayText("");
                               				correctWords = "Correct: " + std::to_string(player.getScore());
											userScoreCorrect.SetTextDisplayText(correctWords);
                                			errors = "Error: " + std::to_string(player.getError());
											userScoreErr.SetTextDisplayText(errors);
                        				} 
				}
				
	window.clear(sf::Color::Black);
    	
	//game begin
		if(isPlaying){
			//initiate clock and generate string that displays time elapsed
        			time = clock.getElapsedTime();
				timerSec.SetTextDisplayText(std::to_string(time.asSeconds()));
        			
        		//draw the words to the screen adjust speed to how fast words move across screen
        			const float speed = 2.3;
        			for(int d = 0; d < (int)words.size(); d++){
					window.draw(words[d]);
					//std::cout<<"word drawn to screen"<<std::endl;
					words[d].move(speed,0.0f);
					if(words[d].getPosition().x > 300 && words[d].getPosition().x < 740){
						words[d].setFillColor(sf::Color::Yellow);}
					else if (words[d].getPosition().x < 740){
						words[d].setFillColor(sf::Color::White);}
					else{
						words[d].setFillColor(sf::Color::Red);}
				}
					
        		//draws all items to the window; redraws every change					
				window.draw(userInput.text);
        			window.draw(userInterfaceInput.text);
        			window.draw(userScoreCorrect.text);
        			window.draw(userScoreErr.text);
        			window.draw(timer.text);
				window.draw(timerSec.text);
				}
		else{
        		//game ends at 60 seconds
        			if((int)time.asSeconds() >= 60){
                			finalScore = "Game Over! \nCorrect Words: " + std::to_string(player.getScore()) + "\nErrors: " +
					std::to_string(player.getError());
							endGame.SetTextDisplayText(finalScore);
							window.draw(endGame.text);
					}
					
        			else{
					window.draw(titlePage);
					}
			}
		
	window.display();
	}
	
return 0;
}
