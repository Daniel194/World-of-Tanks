#ifndef OUTPUT_H
#define OUTPU_H
#include "engine.h"

class output
{
private :
	engine&motor;

public:
	output(engine&);
	void init();
	void close();
	void afisare();
};
#endif