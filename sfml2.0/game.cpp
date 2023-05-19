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
