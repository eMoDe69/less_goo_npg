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

//const/dest
Game::Game()
{
	this->init_variables();
	this->init_window();
	this->init_fonts();
	this->init_texts();
	this->init_enemies();
}
Game::~Game()
{
	delete this->window;
}

//accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::get_end_game() const
{
	return this->end_game;
}

//functions
void Game::spawn_enemy()
{
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		-10.f
	);
	int a = rand() % (256);
	int b = rand() % (256);
	int c = rand() % (256);
	this->enemy.setFillColor(sf::Color(a, b, c, 255));
	this->enemies.push_back(this->enemy);
}

void Game::poll_events()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}
