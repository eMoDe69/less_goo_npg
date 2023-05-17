if (this->enemies[i].getGlobalBounds().contains(this->mouse_pos_view))
				{
					//delete the enemy
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);

					//gain points
					this->points += 1;
					std::cout << "points: " << this->points << std::endl;
				}