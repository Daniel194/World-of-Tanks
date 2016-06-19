#include "stdafx.h"
#include "joctanc.h"
#define KILL 1

#pragma region Clasa Zid

unsigned char zid::nume=177;

void zid::action()
{
	
}
void zid::behaviour(int x)
{
	
}
zid::zid(int x, int y) :unit(x,y)
{
	
}
void* zid::gettipe()
{
	return &nume;
}
#pragma endregion

#pragma region Clasa Bomba

unsigned char bomba::nume='.';

void bomba::action()
{
	int xn = getx() + dirx;
	int yn = gety() + diry;

	if (motor.validxy(xn,yn)==0)
		die();
	else 
	if (motor.getunitxy(xn,yn) == NULL) move(dirx, diry);
	else { 
		sendmes(KILL, *motor.getunitxy(xn,yn)); 
		die();
	}
}
void bomba::behaviour(int x)
{
	if (x == KILL)die();
}

bomba::bomba(int x, int y, int dx, int dy) :unit(x,y)
{
	dirx = dx;
	diry = dy;
}
void*bomba::gettipe()
{
	return &nume;
}
#pragma endregion

#pragma region Clasa Tanc

char tanc::cc=0;

void tanc::action()
{
	if (cc == stg)
	{
		if (motor.validxy(getx(), gety() - 1) == 1 && motor.getunitxy(getx(), gety() - 1) == NULL){
			move(0, -1); 
			pc = cc;
		}
	}
	else if (cc == dr) {
		if (motor.validxy(getx(), gety() + 1) == 1 && motor.getunitxy(getx(), gety() + 1) == NULL) {
			move(0, 1);
			pc = cc;
		}
	}
	else if (cc == jos)
	{
		if (motor.validxy(getx()+1, gety()) == 1 && motor.getunitxy(getx() + 1, gety()) == NULL){
			move(1, 0);
			pc = cc;
		}
	}
	else if (cc == sus)
	{
		if (motor.validxy(getx()-1, gety()) == 1 && motor.getunitxy(getx() - 1, gety()) == NULL)
		{
			move(-1, 0);
			pc = cc;
		}
	}
	else if (cc == foc)
	{
		if (pc == sus)
		{
			if (motor.validxy(getx() - 1, gety()) == 1)
			{
				if (motor.getunitxy(getx() - 1, gety()) == NULL) new bomba(getx() - 1, gety(), -1, 0);
				else sendmes(KILL, *motor.getunitxy(getx() - 1, gety()));
			}
		}
		else if (pc==jos)
		{
			if (motor.validxy(getx() + 1, gety()) == 1)
			{
				if (motor.getunitxy(getx() + 1, gety()) == NULL) new bomba(getx() + 1, gety(), 1, 0);
				else sendmes(KILL, *motor.getunitxy(getx() + 1, gety()));
			}
		}
		else if (pc==dr)
		{
			if (motor.validxy(getx(), gety() + 1) == 1)
			{
				if (motor.getunitxy(getx(), gety() + 1) == NULL) new bomba(getx(), gety() + 1, 0, 1);
				else sendmes(KILL, *motor.getunitxy(getx(), gety() + 1));
			}
		}
		else if (pc==stg)
		{
			if (motor.validxy(getx(), gety() - 1) == 1)
			{
				if (motor.getunitxy(getx(), gety() - 1) == NULL) new bomba(getx(), gety() - 1, 0, -1);
				else sendmes(KILL, *motor.getunitxy(getx(), gety() - 1));
			}
		}
	}
}

void tanc::behaviour(int x)
{
	if (x == KILL)die();
}

tanc::tanc(char nume , char stanga, char dreapta, char sus , char jos, char foc, int x, int y) :unit(x,y)
{
	this->nume = nume;
	stg = stanga;
	dr = dreapta;
	this->sus = sus;
	this->jos = jos;
	this->foc = foc;

}

void*tanc::gettipe()
{
	return &nume;
}
#pragma endregion