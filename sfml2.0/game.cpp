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