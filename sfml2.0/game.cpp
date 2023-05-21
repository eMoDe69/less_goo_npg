void Game::update_text()
{
	std::stringstream ss;
	ss << "Points: " << this->points;
	this->text.setString(ss.str());
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
	//clear old frame renders the game objects and display the window
	this->window->clear();

	//draw game objects
	this->render_enemies();
	this->render_text(*this->window);
	this->window->display();
}

void Game::render_text(sf::RenderTarget& target)
{
	target.draw(this->text);
}