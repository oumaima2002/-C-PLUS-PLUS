#pragma once
#include "cScreen.h"
#include "Board.hpp"


//The main that we are using for the soduko board also the 3 buttons options
class Screen_1 : public cScreen
{
public:
	Screen_1(ResourceHolder* _rh, sf::RenderWindow& window); //The ressources and the main window container rendering
	~Screen_1(); //destructor

	Board board;
	ResourceHolder* rh;

	int Run(sf::RenderWindow& window);//The implemented  run method for the screen

	void handle_mouseclick(sf::RenderWindow& window, sf::Vector2i m_pos);//handling events


private:

	


};

