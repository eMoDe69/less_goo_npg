#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

// class that acts as game engine (wrapper class)

class Game
{
private:
	//variables
	//window
	sf::RenderWindow* window;
	sf::VideoMode video_mode;
	sf::Event event;

	//mouse positions
	sf::Vector2i mouse_pos_window;
	sf::Vector2f mouse_pos_view;

	//resources
	sf::Font font;

	//text
	sf::Text text;
};    
#endif