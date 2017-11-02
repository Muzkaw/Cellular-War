//This file is part of Cellular War(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#include "Matrix.h"

Matrix::Matrix()
{
	col = 0;
	row = 0;
	coeff.clear();
	scale = 1;
}
Matrix::Matrix(int const& _col, int const& _row, int const &_scale)
{
	col = _col;
	row = _row;
	resize(col, row);
	scale = _scale;
}
Warrior Matrix::get(int const& i, int const& j) const
{
	return coeff[i + j*col];
}
void Matrix::set(int const& i, int const& j, Warrior const& _coeff)
{
	coeff[i + j*col] = _coeff;
}
void Matrix::setLife(int const& i, int const& j, double const& _coeff)
{
	coeff[i + j*col].life = _coeff;
}
void Matrix::setForce(int const& i, int const& j, double const& _coeff)
{
	coeff[i + j*col].force = _coeff;
}
void Matrix::setDefence(int const& i, int const& j, double const& _coeff)
{
	coeff[i + j*col].defence = _coeff;
}
void Matrix::resize(int const& _col, int const& _row)
{
	col = _col;
	row = _row;
	coeff.resize(col*row, Warrior());
}
int Matrix::getRow() const
{
	return row;
}
int Matrix::getCol() const
{
	return col;
}
void Matrix::setScale(int const& _scale)
{
	scale = _scale;
}
int Matrix::getScale() const
{
	return scale;
}

