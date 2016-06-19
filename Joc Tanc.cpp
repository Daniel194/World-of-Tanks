#include "stdafx.h"
#include "input.h"
#include "output.h"
#include "joctanc.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

using namespace std;
input intrare;
output iesire(tanc::motor);

char read()
{
	char kb=0;

	while (kb==0)
	if (_kbhit())
	{
		kb = _getch();

		if (kb == -32)kb = _getch();

		if (kb == UP) cout << "UP  \n ";
		else if (kb == DOWN) cout << "DOWN  \n ";
		else if (kb == LEFT) cout << "LEFT  \n ";
		else if (kb == RIGHT) cout << "RIGHT  \n ";
		else  cout << kb << "  \n ";
	}

	return kb;
}

int main()
{
	char nume, stanga, dreapta, jos, sus, foc;

	tanc::motor.init(50, 50);

	cout << "Numele tancului 1 : ";
	nume = read();
	cout << "Comanda de sus : ";
	sus = read();
	cout << "Comanda de jos : ";
	jos = read();
	cout << "Comanda de stanga : ";
	stanga = read();
	cout << "Comanda de dreapta : ";
	dreapta = read();
	cout << "Comadna de foc : ";
	foc = read();
	new tanc(nume, stanga, dreapta, sus, jos, foc, 0, 0);

	cout << "Numele tancului 2 : ";
	nume = read();
	cout << "Comanda de sus : ";
	sus = read();
	cout << "Comanda de jos : ";
	jos = read();
	cout << "Comanda de stanga : ";
	stanga = read();
	cout << "Comanda de dreapta : ";
	dreapta = read();
	cout << "Comadna de foc : ";
	foc = read();
	new tanc(nume, stanga, dreapta, sus, jos, foc, 49, 49);

	for (int i = 0; i <= 10; i++)new zid(6, i);
	for (int i = 6; i <= 10; i++)new zid(i, 10);
	for (int i = 0; i <= 7; i++)new zid(i, 15);
	for (int i = 11; i <= 15; i++)new zid(i, 13);
	for (int i = 3; i <= 16; i++)new zid(19, i);
	for (int i = 19; i <= 29; i++)new zid(i, 3);
	for (int i = 8; i <= 19; i++)new zid(25, i);
	for (int i = 15; i <= 22; i++)new zid(i, 22);
	for (int i = 28; i <= 32; i++)new zid(i, 22);
	for (int i = 23; i <= 32; i++)new zid(30, i);
	for (int i = 32; i <= 41; i++)new zid(i, 13);
	for (int i = 2; i <= 12; i++)new zid(41, i);
	for (int i = 42; i <= 46; i++)new zid(i, 4);
	for (int i = 35; i <= 49; i++)new zid(i, 18);
	for (int i = 39; i <= 48; i++)new zid(i, 45);
	for (int i = 44; i <= 49; i++)new zid(i, 41);
	for (int i = 31; i <= 43; i++)new zid(i, 28);
	for (int i = 21; i <= 25; i++)new zid(41, i);
	for (int i = 32; i <= 41; i++)new zid(37, i);
	for (int i = 26; i <= 36; i++)new zid(i, 36);
	for (int i = 36; i <= 49; i++)new zid(22, i);
	for (int i = 19; i <= 25; i++)new zid(i, 31);
	for (int i = 19; i <= 28; i++)new zid(10, i);
	for (int i = 0; i <= 4; i++)new zid(i, 23);
	for (int i = 12; i <= 18; i++)new zid(i, 45);
	for (int i = 32; i <= 44; i++)new zid(6, i);
	for (int i = 7; i <= 16; i++)new zid(i, 39);
	for (int i = 29; i <= 38; i++)new zid(14, i);
	for (int i = 40; i <= 44; i++)new zid(30, i);
	for (int i = 31; i <= 37; i++)new zid(47, i);

	intrare.init(); 
	iesire.init();
	
	do{
		tanc::cc = intrare.getc();
		tanc::motor.next();
		iesire.afisare();
		Sleep(50);
	} while (tanc::cc != 27);

	intrare.close();  
	iesire.close();

	return 0;
}

