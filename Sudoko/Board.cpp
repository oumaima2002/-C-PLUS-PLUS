#include "Board.hpp"
#include "Screen_1.h"

Board::Board(){}

Board::Board(ResourceHolder* _rh, sf::RenderWindow& window): 
	rh(_rh), grid(_rh->grid_size, std::vector<int>(_rh->grid_size)), 
	squares(_rh->grid_size, std::vector<Square>(_rh->grid_size))
{
	reset_and_draw_load(window);
}

Board::~Board()
{
}
//Method  for rendering values in the the squares of the board with the load animation using Sprite
void Board::reset_and_draw_load(sf::RenderWindow& window)
{
	std::atomic<bool> done(false);
	std::thread load(&Board::reset, this, &done);

	while (!done)
	{
		rh->load_sprite.setTextureRect(sf::IntRect((rh->load_texture.getSize().x*current_tex) / rh->num_of_anims, 0, rh->load_texture.getSize().x / rh->num_of_anims, rh->load_texture.getSize().y));

		window.clear(rh->background_color);
		draw(window);
		for (auto b : rh->buttons) window.draw(b);
		for (auto t : rh->texts) window.draw(t);

		window.draw(rh->load_sprite);
		window.display();

		current_tex++;
		current_tex %= rh->num_of_anims;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	load.join();
}

//Reset board , using after ,if we click on regenerate button to have new  automatic inputs
void Board::reset(std::atomic<bool>* done)
{
	init_board();
	generate();
	update_squares();
	print_string();
	if(done != nullptr) *done = true;
}

//Draws board image, sets the boardsprite and sets it position using pixels
//for 300x300 pixels  we use it for each blok in the square for representing their borders
//For horizontal or vertical part of the grid 100x100 we  use the grey color (borders)
//For other it represent the main area of the block it's for white part
void Board::init_board()
{
	board_img.create(rh->board_size, rh->board_size);
	for (int i = 0; i < rh->board_size; i++)
	{
		for (int j = 0; j < rh->board_size; j++)
		{
			if (i < 0 + rh->big_border_width || i > rh->board_size - rh->big_border_width
			 || j < 0 + rh->big_border_width || j > rh->board_size - rh->big_border_width
			 || (i > 300 - rh->big_border_width/2 && i < 300 + rh->big_border_width/2)
			 || (i > 600 - rh->big_border_width / 2 && i < 600 + rh->big_border_width / 2)
			 || (j > 300 - rh->big_border_width / 2 && j < 300 + rh->big_border_width / 2)
			 || (j > 600 - rh->big_border_width / 2 && j < 600 + rh->big_border_width / 2))
				board_img.setPixel(i, j, sf::Color(0x000000ff));
			else if (i % 100 == 0 || j % 100 == 0)
			{
				board_img.setPixel(i, j, sf::Color(0xC2C5CCFF));
			}
			else board_img.setPixel(i, j, sf::Color(0xFFFFFFFF));
		}
	}

	board_texture.loadFromImage(board_img);

	//Position of the sprite of load in the board
	board_sprite.setTexture(board_texture);
	board_sprite.setPosition(rh->board_offset_x, rh->board_offset_y);
}

//Generates new sudoku values
void Board::generate()
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			grid[i][j] = 0;
		}
	}

	if (manual_mode)
	{
		create_squares();
		for(auto& vec : squares)
			for (auto& s : vec)
			{
				s.locked = false;
			}
		return;
	}
	fill_grid();
	create_squares();
	remove_numbers();
}

//Fill the grid with valid numbers
void Board::fill_grid()
{
	std::vector<std::vector<int>> temp_grid;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			while (grid[i][j] == 0)
			{
				grid[i][j] = get_valid_number(i, j);
				temp_grid = grid;
				if (!upward_sol(&temp_grid)) grid[i][j] = 0;
				

			}
		}
	}
}

//Gives fill_grid valid numbers
int Board::get_valid_number(int ligne, int col)
{
	std::vector<int> nums{ 1,2,3,4,5,6,7,8,9 };
	for (int i = nums.size()-1; i >= 0; i--)
	{
		if (!check_valid_number(nums[i], ligne, col, &grid)) 
		nums.erase(nums.begin() + i);
	}
	if (nums.size() == 0) return 0;
	return nums[intRand(0, nums.size()-1)];
}

//Check if the number about to be inserted is allowed (Helper when filling board while generating)
bool Board::check_valid_number(int num, int ligne, int col, std::vector<std::vector<int>>* vect)
{
	//if (num == 0) return true;

	//Check ligne and col
	for (int i = 0; i < rh->grid_size; i++)
	{
		if (((*vect)[ligne][i] == num) || ((*vect)[i][col] == num)) return false;
	}
	//Check box for each one we have 3x3

	int r = ligne - ligne % 3;
	int c = col - col % 3;
	for (int i = r; i < r + 3; i++)
	{
		for (int j = c; j < c + 3; j++)
		{
			if ((*vect)[i][j] == num && i != ligne && j != col) return false;
		}
	}
	return true;
}

//The same as above, but used when solving manual entrys
//Should really just use the function above, but after an hour of troubleshooting stack overflows, i cant be bothered to fix it
bool Board::check_valid_number(int num, int ligne, int col, std::vector<std::vector<int>> vect)
{
	if (num == 0) return true;

	//Check ligne and col
	for (int i = 0; i < rh->grid_size; i++)
	{
		if ((vect[ligne][i] == num && i != col) || (vect[i][col] == num && i != ligne)) return false;
	}
	//Check box
	int r = ligne - ligne % 3;
	int c = col - col % 3;
	for (int i = r; i < r + 3; i++)
	{
		for (int j = c; j < c + 3; j++)
		{
			if (vect[i][j] == num && i != ligne && j != col) return false;
		}
	}
	return true;
}

//Checking for solution, brute force counting upward
bool Board::upward_sol(std::vector<std::vector<int>>* vect)
{
	if (!has_empty(vect)) return true;

	for (int i = 0; i < vect->size(); i++)
	{
		for (int j = 0; j < (*vect)[i].size(); j++)
		{
			if ((*vect)[i][j] == 0)
			{
				for (int n = 1; n <= 9; n++)
				{
					if (check_valid_number(n, i, j, vect))
					{
						(*vect)[i][j] = n;
						if (upward_sol(vect)) return true;
						else
						{
							(*vect)[i][j] = 0;
						}
					}

				}
				return false;
			}
		}
	}
	return false;
}

//Checking for solution, brute force counting downward
bool Board::downward_sol(std::vector<std::vector<int>>* vect)
{
	if (!has_empty(vect)) return true;
	for (int i = 0; i < vect->size(); i++)
	{
		for (int j = 0; j < vect->size(); j++)
		{
			if ((*vect)[i][j] == 0)
			{
				for (int n = 9; n >= 0; n--)
				{
					if (check_valid_number(n, i, j, vect))
					{
						(*vect)[i][j] = n;
						if (downward_sol(vect)) return true;
						else
						{
							(*vect)[i][j] = 0;
						}
					}

				}
				return false;
			}
		}
	}
	return true;
}

//Checking if grid has empty square
bool Board::has_empty(std::vector<std::vector<int>>* vect)
{
	for (int i = 0; i < vect->size(); i++)
	{
		for (int j = 0; j < vect->at(i).size(); j++)
		{
			if ((*vect)[i][j] == 0) return true;
		}
	}
	return false;
}

//Checks if to grids are equal
bool Board::equal_sol(std::vector<std::vector<int>>* v1, std::vector<std::vector<int>>* v2)
{
	for (int i = 0; i < v1->size(); i++)
	{
		for (int j = 0; j < v1->size(); j++)
		{
			if ((*v1)[i][j] != (*v2)[i][j]) return false;
		}
	}
	return true;
}

//Remove numbers one at a time at random and check if solution has more than one solution.
void Board::remove_numbers()
{
	auto q = get_cord_queue();
	while (q.size() > 0)
	{
		auto p = q.front();
		q.pop();
		int temp = grid[p.first][p.second];
		grid[p.first][p.second] = 0;

		std::vector<std::vector<int>> v1 = grid;
		std::vector<std::vector<int>> v2 = grid;

		std::thread t1(&Board::upward_sol, this, &v1);
		downward_sol(&v2);

		t1.join();

		if (!equal_sol(&v1, &v2))
		{
			grid[p.first][p.second] = temp;
			//std::cout << "returned TRUE, inserting temp back in!" << std::endl;
		}
		else
		{
			squares[p.first][p.second].locked = false;

		}
		
		//std::cout << "queue: " << q.size() << std::endl;
	}
}

//Returns a queue of coordinates for removing numbers from full sudoku
std::queue<std::pair<int, int>> Board::get_cord_queue()
{
	//Fyller alle koordinater i k�en.
	std::deque<std::pair<int, int>> queue;
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			std::pair <int, int> cord(i, j);
			queue.push_back(cord);
		}
	}
	//Shuffles the deque, constructs a normal queue, and returns it.
	std::random_shuffle(queue.begin(), queue.end());
	std::queue<std::pair<int, int>> q(queue);
	return q;
}

void Board::create_squares()
{
	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[i].size(); j++)
		{
			Square s(sf::Vector2f(rh->board_offset_x * (i + 1), rh->board_offset_y * (j + 1)), grid[i][j], rh);
			squares[i][j] = s;
		}
	}
}

//Gets values from grid and assigns it to Square objects
void Board::update_squares()
{
	for (int i = 0; i < grid.size(); i++)
	{
		for(int j = 0; j < grid[i].size(); j++)
		{
			squares[i][j].entered_number = grid[i][j];
			squares[i][j].update(manual_mode);
		}
	}
}
//Draws board and numbers
void Board::draw(sf::RenderWindow& window)
{
	window.draw(board_sprite);
	for (auto i : squares)
	{
		for (auto j : i) j.draw(window);
	}
}



bool Board::handle_click(sf::RenderWindow& window, sf::Vector2i pos)
{
	if (clicked_square != nullptr)
	{
		clicked_square->setFillColor(rh->clear_color);
		clicked_square = nullptr;
	}
	for(int i = 0; i < squares.size(); i++)
		for(int j = 0; j < squares[i].size(); j++)
		{
			if (squares[i][j].getGlobalBounds().contains(pos.x, pos.y))
			{
				clicked_square = &squares[i][j];
				clicked_square->setFillColor(rh->chosen_square_color);


				return true;
			}
		}
	for (int i = 0; i < rh->buttons.size(); i++)
	{
		if (rh->buttons[i].getGlobalBounds().contains(pos.x, pos.y))
		{
			switch (i)
			{
			case 0:
			{
				manual_mode = false;
				reset_and_draw_load(window);
				return true;
				break;
			}
			case 1:
			{
				return solve();
			}
			case 2:
			{
				manual_mode = true;
				std::cout<<"Fin De Jeux";
				exit(1);
			}
			}
		}
	}

	return false;
}

//Handles solve button click, called from handle_click
bool Board::solve()
{
		if(!manual_mode)
		{
		for(int i = 0; i < squares.size(); i++)
		{
			for (int j = 0; j < squares[i].size(); j++)
			{
				squares[i][j].entered_number = squares[i][j].correct_number;
				grid[i][j] = squares[i][j].correct_number;
			}
		}
		update_squares();
		return true;
	     }
	return false;
}

//Prints a sudoku string that can be used in other software
void Board::print_string()
{
	for (int i = 0; i < squares.size(); i++)
	{
		for (int j = 0; j < squares[i].size(); j++)
		{
			std::cout << ((squares[j][i].entered_number == 0) ? "." : std::to_string(squares[j][i].entered_number));
		}
	}
	std::cout << std::endl;
}

//Checking that manually entered sudoku is valid before brute-forcing solution
// bool Board::check_valid_inputs()
// {
// 	for (int i = 0; i < grid.size(); i++)
// 	{
// 		for (int j = 0; j < grid[i].size(); j++)
// 		{
// 			if (!check_valid_number(grid[i][j], i, j, grid))
// 			{
// 				return false;
// 			}
				
// 		}
// 	}
// 	return true;
// }

//Random generator
int Board::intRand(const int & min, const int & max) {
	static thread_local std::mt19937* generator = nullptr;
	if (!generator) generator = new std::mt19937(clock());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(*generator);
}