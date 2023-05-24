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
	this->max_enemies = 20;
	this->mouse_held = false;
	this->health = 5;
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

void Game::update_mouse_pos()
{
	this->mouse_pos_window = sf::Mouse::getPosition(*this->window);
	this->mouse_pos_view = this->window->mapPixelToCoords(this->mouse_pos_window);
}
void Game::update_enemies()
{
	//timer
	if (this->enemies.size() < this->max_enemies)
	{
		if (this->enemy_spawn_timer >= this->enemy_spawn_timer_max)
		{
			//spawner
			this->spawn_enemy();
			this->enemy_spawn_timer = 0.f;
		}
		else
		{
			this->enemy_spawn_timer += 1.f;
		}
	}
	//moving enemies
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;
		this->enemies[i].move(speed1, 2.f);

		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health--;
			std::cout << "zycie: " << this->health << std::endl;
			this->speed2 = -speed2;
		}
		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->speed2 = -speed2;
		}
		if (this->enemies[i].getPosition().x > this->window->getSize().x)
		{
			this->speed1 = -speed1;
		}
		if (this->enemies[i].getPosition().x > this->window->getSize().x)
		{
			this->speed1 = -speed1;
		}
		if (this->move_time >= this->move_time_max)
		{
			this->speed1 = -5 + rand() % (11);
			this->speed2 = -5 + rand() % (11);
			this->move_time = 0.f;
		}
		else
		{
			this->move_time += 1.f;
		}
	}
	//sprawdzenie czy przeciwnik trafiony
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->mouse_held == false)
		{
			bool deleted = false;
			this->mouse_held = true;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mouse_pos_view))
				{
					//usuniecie przeciwnika
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

					//przyznanie punktow graczowi
					this->points += 1;
					std::cout << "points: " << this->points << std::endl;
				}
			}
		}
	}
	else
	{
		this->mouse_held = false;
	}
}

//funkcje publiczne
void Game::update()
{
	this->poll_events();
	if (this->end_game == false)
	{
		this->update_mouse_pos();
		this->update_text();
		this->update_enemies();
	}
	if (this->health < 1)
	{
		this->end_game = true;
	}
}
  
  void Game::update_text()
{
	//std::stringstream ss;
	//ss << "Points: " << this->points;
	//this->text.setString(ss.str());
}

void Game::render_enemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}

void Game::render()
{
	this->window->clear();
	this->render_enemies();
	this->render_text(*this->window);
	this->window->display();
}

void Game::render_text(sf::RenderTarget& target)
{
	target.draw(this->text);
}