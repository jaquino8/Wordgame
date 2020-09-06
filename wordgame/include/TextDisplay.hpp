#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

/*
*   Display class to draw to the display
*/
class TextDisplay{
    private:

		
    public:
		//To create a specific font type
		sf::Font font;
		sf::Text text;
		
		//Default constructor
		TextDisplay();
		
		//Overloaded constructor
		TextDisplay(float x, float y);
		
		//Set origin
		void SetTextDisplayOrigin(float x, float y);
		
		//Get local origin
		sf::FloatRect GetTextDisplayLocal();
			
		//Set size
		void SetTextDisplaySize(int x);
		
		//Set position
		void SetTextDisplayPosition(float x, float y);

		//Get position x
		float GetTextDisplayPositionx();
		
		//Get position y
		float GetTextDisplayPositiony();
		
		//Set text
		void SetTextDisplayText(std::string string);
		
		//Get Text
		std::string GetTextDisplayText();
		
		//Set string color
		void SetTextDisplayColor();
};