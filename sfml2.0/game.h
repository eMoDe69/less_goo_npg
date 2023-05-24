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

	//game objects
	std::vector<sf::RectangleShape> enemies;
	sf::RectangleShape enemy;

	//game logic
	bool end_game;
	unsigned points;
	int health;
	float enemy_spawn_timer;
	float enemy_spawn_timer_max;
	int max_enemies;
	bool mouse_held;
	float move_time;
	float move_time_max;
	float speed1;
	float speed2;

	//private functions
	void init_variables();
	void init_window();
	void init_enemies();
	void init_fonts();
	void init_texts();
public:

	//const/dest
	Game();
	~Game();

	//accessors
	const bool running() const;
	const bool get_end_game() const;

	//public functions
	void spawn_enemy();
	void poll_events();
	void update_mouse_pos();

	void update_enemies();
	void update();
	void update_text();

	void render_enemies();
	void render();
	void render_text(sf::RenderTarget& target);
};    
#endif