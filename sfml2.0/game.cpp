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
}