void Game::update_mouse_pos()
{
	//mouse position relative to window
	this->mouse_pos_window = sf::Mouse::getPosition(*this->window);
	this->mouse_pos_view = this->window->mapPixelToCoords(this->mouse_pos_window);
}
void Game::update_enemies()
{
	//updating the timer for enemy spawning
	if (this->enemies.size() < this->max_enemies)
	{
		if (this->enemy_spawn_timer >= this->enemy_spawn_timer_max)
		{
			//spawning enemies and reset the timer
			this->spawn_enemy();
			this->enemy_spawn_timer = 0.f;
		}
		else
		{
			this->enemy_spawn_timer += 1.f;
		}
	}
	//moving and updating enemies
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