#ifndef JOCTANC_H
#define JOCTANC_H
#include "engine.h"
class zid :public unit
{
private:
	static unsigned char nume;

protected:
	void action();
	void behaviour(int);

public:
	zid(int, int);
	void* gettipe();

};

class bomba :public unit
{
private:
	static unsigned char nume;
	int dirx, diry;

protected:
	void action();
	void behaviour(int);

public:
	bomba(int, int, int, int);
	void*gettipe();

};

class tanc :public unit
{
public :
	static char cc;
	tanc(char, char, char, char, char, char, int, int);
	void *gettipe();

private:
	unsigned char nume;
	char stg, dr, sus, jos, foc , pc;

protected:
	void action();
	void behaviour(int);
};
#endif