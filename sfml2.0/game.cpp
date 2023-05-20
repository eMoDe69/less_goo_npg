//check if enemy is clicked
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
					//delete the enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

					//gain points
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
