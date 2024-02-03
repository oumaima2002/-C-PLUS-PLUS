#include "Screen_1.h"



Screen_1::Screen_1(ResourceHolder* _rh, sf::RenderWindow& window) : rh(_rh), board(_rh, window)
{
}


Screen_1::~Screen_1()
{
}

//m_pos represent the point when the mouse exist
void Screen_1::handle_mouseclick(sf::RenderWindow& window , sf::Vector2i m_pos)
{
	if (board.handle_click(window, m_pos)) return;
}

int Screen_1::Run(sf::RenderWindow& window)
{
	while (true)
	{
		sf::Vector2i m_pos = sf::Mouse::getPosition(window);
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return 0;
			}
			if(event.type == sf::Event::MouseButtonPressed)
				if (event.key.code == sf::Mouse::Left)
				{
					handle_mouseclick(window, m_pos);
				}
		     
		}
		board.update_squares();

		window.clear(rh->background_color);
		board.draw(window);
		for (auto b : rh->buttons) window.draw(b);
		for (auto t : rh->texts) window.draw(t);
		window.display();
	}

	return 1;
}