#include "stdafx.h"
#include "engine.h"

#pragma region Clasa engine

void engine::init(int numarLinii, int numarColona)
{
	nc = numarLinii;
	nl = numarColona;
	nu = 0;

	for (int i = 0; i < nl; i++)
		for (int j = 0; j < nc;j++)
	unittab[i][j] = NULL;
}

int engine::getnl()
{
	return nl;
}

int engine::getnc()
{
	return nc;
}

int engine::getnu()
{
	return nu;
}

int engine::validxy(int x, int y)
{
	if (x >= 0 && x < nl && y >= 0 && y < nc) return 1;
	else return 0;
}
int engine::validpoz(int n)
{
	if (n >= 0 && n < nu) return 1;
	else return 0;
}

unit* engine::getunitxy(int x , int y)
{
	return unittab[x][y];
}

unit* engine::getunitpoz(int n)
{
	return unitvect[n];
}

void engine::next()
{
	for (int i = 0; i < nu; i++)
	unitvect[i]->action();
	
		for (int i = 0; i < nu; i++)
		{
			unitvect[i]->react();
			if (unitvect[i]->alive==0)
			{
				unittab[unitvect[i]->x][unitvect[i]->y] = NULL;

				delete unitvect[i];

				unitvect[i] = unitvect[nu - 1];

				nu--;

			}
	}
}

#pragma endregion

#pragma region  Clasa unit

engine unit::motor ;

void unit::react()
{

	for (int i = 0; i < nm; i++)
	{
		behaviour(message[i]);
		if (alive == 0) break;
	}
	nm = 0;
}

unit::unit(int x, int y)
{
	if ( motor.nu < MAXNU )
	{   
		this->x = x;
		this->y = y;
		motor.unittab[x][y] = this;
		motor.unitvect[motor.nu] = this;
		motor.nu++;
		nm = 0;
		alive = 1;
	}
}

unit::~unit()
{
	
}

void unit::die()
{
	alive = 0;
}

void unit::move(int dx, int dy)
{ 
	
		motor.unittab[x + dx][y + dy] = motor.unittab[x][y];
		motor.unittab[x][y] = NULL;
		x += dx;
		y += dy;
	
}

void unit::sendmes(int pm, unit& pu)
{
	if (pu.nm < MAXNM)
	{
		pu.message[pu.nm] = pm;
		pu.nm++;
	}
	
}

int unit::getx()
{
	return  x;
}
int unit::gety()
{
	return y;
}

#pragma endregion