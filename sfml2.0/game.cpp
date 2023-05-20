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
