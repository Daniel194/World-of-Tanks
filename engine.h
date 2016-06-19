#ifndef ENGINE_H
#define ENGINE_H
#define MAXNC 1000
#define MAXNL 1000
#define MAXNU 1000
#define MAXNM 1000
class engine
{
	friend class unit;

private:
	unit* unittab[MAXNC][MAXNL];
	unit* unitvect[MAXNU];
	int nc, nl, nu;

public:
	void init(int, int);
	int getnl();
	int getnc();
	int getnu();
	int validxy(int, int);
	int validpoz(int);
	unit*getunitxy(int, int);
	unit*getunitpoz(int);
	void next();
};

class unit
{
	friend class engine;

public:
	static engine motor;
	int getx();
	int gety();
	virtual void* gettipe() = 0;

private:
	int alive,x, y, poz, message[MAXNM],nm;
	void react();

protected:
	unit(int, int);
	virtual ~unit();
	void die();
	void move(int, int);
	void sendmes(int, unit&);
	virtual void action()=0;
	virtual void behaviour(int)=0;
};
#endif