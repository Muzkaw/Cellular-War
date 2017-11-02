#include "Matrix.h"

Matrix::Matrix() 
{
	col = 0 ;
	row = 0 ;
	coeff.clear() ;
	scale = 1 ;
}
Matrix::Matrix(int const& _col, int const& _row, int const &_scale) 
{
	col = _col ;
	row = _row ;
	resize(col, row) ;
	scale = _scale ;
}
Warrior Matrix::get(int const& i, int const& j) const
{
	if(i>0 && i <row && j>0 && j<row)
		return coeff[i+(j-1)*col] ;
	else return 0 ;
}
void Matrix::set(int const& i, int const& j, Warrior const& _coeff)
{
	if(i>0 && i <row && j>0 && j<row)
		coeff[i+max(j-1,0)*col] = _coeff ;
}
void Matrix::resize(int const& _col, int const& _row)
{
	col=_col ;
	row=_row ;
	coeff.resize(col*row,0) ;
}
int Matrix::getRow() const
{
	return row ;
}
int Matrix::getCol() const
{
	return col ;
}
void Matrix::setScale(int const& _scale)
{
	scale = _scale ;
}
int Matrix::getScale() const
{
	return scale ;
}

