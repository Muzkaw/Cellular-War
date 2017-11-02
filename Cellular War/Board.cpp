//This file is part of Cellular War(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "Board.h"

Board::Board()
{
	width = 300;
	height = 300;

	m = Matrix(width, height, 2);

	image.create(width, height);
	texture.create(width, height);
	sprite.setScale(m.getScale(), m.getScale());

	for (int x(0); x < width; x++)
		for (int y(0); y < height; y++)
			m.set(x, y, Warrior(0, 0, 0, 0));
	
	for (int x(10); x < 20; x++)
		for (int y(10); y < 20; y++)
			m.set(x, y, Warrior(1, 100, 10+rand()%40, 10 + rand() % 10));

	for (int x(180); x < 190; x++)
		for (int y(10); y < 20; y++)
			m.set(x, y, Warrior(2, 100, 10 + rand() % 40, 10 + rand() % 10));

	for (int x(10); x < 20; x++)
		for (int y(180); y < 190; y++)
			m.set(x, y, Warrior(3, 100, 10 + rand() % 40, 10 + rand() % 10));
	
	for (int x(180); x < 190; x++)
		for (int y(180); y < 190; y++)
			m.set(x, y, Warrior(4, 100, 10 + rand() % 40, 10 + rand() % 10));

	mbuf = m;
}
void Board::update()
{
	for (int t(0); t < 1; t++)
	{
		int dx, dy;
		Warrior w;
		int r;
		
		for (int x(1); x < width -1; x++)
		{
			for (int y(1); y < height-1; y++)
			{
				if (m.get(x,y).team != 0)
				{
					dx = rand() % 3 - 1;
					dy = rand() % 3 - 1;

					if (dx == 0 && dy == 0)
					{
						mbuf.setForce(x, y, m.get(x, y).force * 0.999);
						mbuf.setDefence(x, y, m.get(x, y).defence * 1.005);
					}
					else
					{
						if (m.get(x + dx, y + dy).team == 0)
						{
							mbuf.set(x + dx, y + dy, m.get(x, y));
						}

						else
						{
							if (m.get(x + dx, y + dy).team == m.get(x, y).team)
							{
								mbuf.setLife(x + dx, y + dy, m.get(x + dx, y + dy).life + max((m.get(x, y).life - m.get(x + dx, y + dy).life)*0.2, 0.0));
							}
							else
							{
								mbuf.setLife(x, y, m.get(x, y).life - max(m.get(x + dx, y + dy).force - m.get(x, y).defence, 0.0));
								if (mbuf.get(x, y).life <= 20)
								{
									mbuf.set(x, y, Warrior(0, 0, 0, 0));
									mbuf.setForce(x + dx, y + dy, m.get(x + dx, y + dy).force + 0.4);
								}
								else mbuf.setDefence(x, y, m.get(x, y).defence + 0.0001);

								mbuf.setLife(x + dx, y + dy, m.get(x + dx, y + dy).life - max(m.get(x, y).force - m.get(x + dx, y + dy).defence, 0.0));
								if (mbuf.get(x + dx, y + dy).life <= 20)
								{
									mbuf.set(x + dx, y + dy, Warrior(0, 0, 0, 0));
									mbuf.setForce(x, y, m.get(x, y).force + 0.4);
								}
								else mbuf.setDefence(x + dx, y + dy, m.get(x + dx, y + dy).defence + 0.0001);
							}
						}
					}

				}
				
			}
		}
		m = mbuf;
	}
}
void Board::draw(RenderWindow &window)
{
	for (int x(0); x < width; x++)
		for (int y(0); y < height; y++)
			image.setPixel(x, y, HSVColor(m.get(x,y).team * 89, min(m.get(x, y).force*0.8,100.0), m.get(x, y).life * 1).RGB());

	texture.update(image);
	sprite.setTexture(texture);
	window.draw(sprite);
}

