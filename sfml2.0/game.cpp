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