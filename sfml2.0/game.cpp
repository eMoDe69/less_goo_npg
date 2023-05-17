void Game::update_text()
{

	std::stringstream ss;
	ss << "Points: " << this->points;
	this->text.setString(ss.str());
}