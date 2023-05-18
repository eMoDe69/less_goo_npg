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