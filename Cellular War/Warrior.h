//This file is part of Cellular War(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <vector>

using namespace std;

class Warrior
{
public:
	Warrior():team(0),life(0),force(0),defence(0) {}
	Warrior(int const& _team, double const& _life, double const &_force, double const &_defence):team(_team),life(_life),force(_force),defence(_defence) {}

	int team;

	double life;
	double force;
	double defence;
};

Warrior operator/(Warrior &w, double const &c);