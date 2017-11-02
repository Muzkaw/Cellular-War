//This file is part of Cellular War(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <vector>
#include <algorithm>
#include "Warrior.h"

using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int const& _col, int const& _row, int const &_scale);
	Warrior get(int const& i, int const& j) const;
	void set(int const& i, int const& j, Warrior const& _coeff);
	void setLife(int const& i, int const& j, double const& _coeff);
	void setForce(int const& i, int const& j, double const& _coeff);
	void setDefence(int const& i, int const& j, double const& _coeff);
	void resize(int const& _col, int const& _row);
	int getRow() const;
	int getCol() const;
	void setScale(int const& _scale);
	int getScale() const;

private:
	vector<Warrior> coeff;
	int col;
	int row;
	int scale;
};