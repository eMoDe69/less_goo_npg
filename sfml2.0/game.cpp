#include "game.h"
#include <iostream>
#include <stdlib.h>

//private functions
void Game::init_variables()
{
	this->window = nullptr;

	//game logic
	this->points = 0;
	this->enemy_spawn_timer_max = 40.f;
	this->enemy_spawn_timer = this->enemy_spawn_timer_max;
	this->max_enemies = 10;
	this->mouse_held = false;
	this->health = 10;
	this->end_game = false;
	this->move_time_max = 1000.f;
	this->move_time = this->move_time_max;
	this->speed1 = 0;
	this->speed2 = 3;
}

void Game::init_window()
{
	this->video_mode.height = 1080;
	this->video_mode.width = 1920;
	this->window = new sf::RenderWindow(this->video_mode, "title", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	this->window->setFramerateLimit(75);
}

void Game::init_enemies()
{
	this->enemy.setPosition(960.f, 540.f);
	this->enemy.setSize(sf::Vector2f(100.f, 100.f));
	this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
}

void Game::init_fonts()
{

}

void Game::init_texts()
{
	this->text.setFont(this->font);
	this->text.setCharacterSize(12);
	this->text.setFillColor(sf::Color::White);
	this->text.setString("NONE");
}