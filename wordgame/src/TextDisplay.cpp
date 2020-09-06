#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "TextDisplay.hpp"

//Default constructor
	TextDisplay::TextDisplay(){
		this->font.loadFromFile("resources/typewriter.ttf");
		this->text.setFont(font);
		this->text.setFillColor(sf::Color::White);
		//std::cout<<"textdisplay class created"<<std::endl;
		}

//Overloaded constructor
	TextDisplay::TextDisplay(float x, float y){
		this->font.loadFromFile("resources/typewriter.ttf");
		this->text.setFont(font);
		this->text.setOrigin(x, y);
		this->text.setFillColor(sf::Color::White);
		//std::cout<<"overloaded textdisplay class created"<<std::endl;
		}
		
//Set origin
	void TextDisplay::SetTextDisplayOrigin(float x, float y){
		this->text.setOrigin(x, y);
		//std::cout<<"text display origin set"<<std::endl;
		}
		
//Get local origin
	sf::FloatRect TextDisplay::GetTextDisplayLocal(){
		return this->text.getLocalBounds();
		//std::cout<<"textdisplay local bounds requested"<<std::endl;
		}
		
//Set size
	void TextDisplay::SetTextDisplaySize(int x){
		this->text.setCharacterSize(x);
		//std::cout<<"textdisplay size set"<<std::endl;
		}
		
//Set position
	void TextDisplay::SetTextDisplayPosition(float x, float y){
		this->text.setPosition(x, y);
		//std::cout<<"textdisplay position set"<<std::endl;
		}
		
//Get position x
	float TextDisplay::GetTextDisplayPositionx(){
		return this->text.getPosition().x;
		//std::cout<<"textdisplay x position requested"<<std::endl;
		}
		
//Get postion y
	float TextDisplay::GetTextDisplayPositiony(){
		return this->text.getPosition().y;
				//std::cout<<"textdisplay y position requested"<<std::endl;
		}
		
//Set text
	void TextDisplay::SetTextDisplayText(std::string string){
		this->text.setString(string);
		//std::cout<<"textdisplay text set"<<std::endl;
		}
		
//Get text
	std::string TextDisplay::GetTextDisplayText(){
		return this->text.getString();
		//std::cout<<"textdisplay text requested"<<std::endl;
		}
		
//Set string color
	void TextDisplay::SetTextDisplayColor(){
		this->text.setFillColor(sf::Color::White);
		}	