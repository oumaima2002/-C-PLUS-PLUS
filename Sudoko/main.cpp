#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Screen_1.h"
#include <ctime>
#include "ResourceHolder.h"




int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	ResourceHolder* rh = new ResourceHolder();
	sf::RenderWindow window(sf::VideoMode(1600, 1200), "Sudoku");
	window.setIcon(rh->icon.getSize().x, rh->icon.getSize().y, rh->icon.getPixelsPtr());

	std::vector<cScreen*> container;
	int screen = 0;

	cScreen* s0 = new Screen_1(rh, window);
	container.push_back(s0);
	while (screen <= 0)
	{
		screen = container[screen]->Run(window);
		if (screen == 0) break;
		if (screen == 2)
		{
			delete container[0];
			cScreen* s0 = new Screen_1(rh, window);
			container.push_back(s0);
			screen = 0;
		}
	}
	return 0;
}