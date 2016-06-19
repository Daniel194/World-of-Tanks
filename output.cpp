#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include "output.h"
#include <windows.h>
#include <conio.h>

#define MAXNU 1000

using namespace std;

#pragma region Clasa output

void gotoXY(int x, int y, char text);

void SetWindow(int Width, int Height);

void cursor(bool visible);

static int pictvect[MAXNU][2], npict;

output::output(engine& pm) :motor(pm)
{
	
}

void output::init()
{
	SetWindow(51, 51);
	cursor(FALSE);
	system("cls"); 

	for (int i = 0 ; i <= motor.getnl(); i++)
		gotoXY(i, motor.getnc(), 219);
	

	for (int i = 0 ; i <= motor.getnc(); i++)
		gotoXY(motor.getnl(), i , 219);

	
	for (int i = 0; i < motor.getnu(); i++)
	{
		unsigned char b = 177;
		unsigned char *a =(unsigned char *) motor.getunitpoz(i)->gettipe();

		if (*a == b)
		{
			gotoXY(motor.getunitpoz(i)->getx(), motor.getunitpoz(i)->gety(), b);
		}

	}
	npict = 0;
}

void output::close()
{
	SetWindow(80, 25);
	cursor(TRUE);
	system("cls"); 
}

void output::afisare()
{
	for (int i = 0; i < npict; i++)
		gotoXY(pictvect[i][0], pictvect[i][1], ' ');

	npict = 0;

	for (int i = 0; i < motor.getnu(); i++)
	{

		unsigned char b = 177;
		unsigned char *a = (unsigned char *)motor.getunitpoz(i)->gettipe();

		if (*a != b)
		{
			gotoXY(motor.getunitpoz(i)->getx(), motor.getunitpoz(i)->gety(), *a);

			pictvect[npict][0] = motor.getunitpoz(i)->getx();
			pictvect[npict][1] = motor.getunitpoz(i)->gety();
			npict++;
		}
			
	}
}

void gotoXY(int line , int column , char text)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	cout << text;
}

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleScreenBufferSize(Handle, coord);            
	SetConsoleWindowInfo(Handle, TRUE, &Rect);           
}

void cursor(bool visible) 
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 10;
	SetConsoleCursorInfo(console, &lpCursor);
}

#pragma endregion