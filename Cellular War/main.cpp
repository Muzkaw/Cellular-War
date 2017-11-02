/*********************************************************************

This file is part of Cellular War (GNU GPL) - https://www.youtube.com/user/Muzkaw.

Cellular War is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Cellular War is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Cellular War. If not, see <http://www.gnu.org/licenses/>.

Cellular War codded by Muzkaw : https://www.youtube.com/user/Muzkaw
You need to link SFML 2.0 or above to run the program

********************************************************************/

#include <SFML/Graphics.hpp>
#include "Board.h"

using namespace std;
using namespace sf;

Warrior operator/(Warrior &w, double const &c)
{
	return Warrior(w.team, w.life/c, w.force / c, w.defence / c);
}
int main()
{
	RenderWindow window(VideoMode(600, 600, 32), "Window");
	srand(time(NULL));
	Board board;

	while (window.isOpen())
	{
		board.update();

		window.clear();
		board.draw(window);
		window.display();
	}
}