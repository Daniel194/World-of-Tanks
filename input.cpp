#include "stdafx.h"
#include "input.h"
#include <conio.h>

#pragma region Class input

void input::init()
{
	
}

void input::close()
{
	
}

char input::getc()
{
	char key = 0;

		if (_kbhit())
			key = _getch();
				
	return key;
}

#pragma endregion