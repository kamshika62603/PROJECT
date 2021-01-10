/**
*
* Solution to course project # 10
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Kalin Tsvetkov
* @idnumber 62603
* @compiler VC
*
* Main cpp file
*
*/


#include <iostream>
#include<windows.h>
using namespace std;

char numbers[10][11][11] = {
	{
		{" 00000000 "},
		{"00      00"},
		{"0        0"},
		{"0        0"},
		{"0        0"},
		{"0        0"},
		{"0        0"},
		{"0        0"},
		{"0        0"},
		{"00      00"},
		{" 00000000 "}
	},
	{
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"},
		{"         1"}
	},
	{
		{"2222222222"},
		{"         2"},
		{"         2"},
		{"         2"},
		{"         2"},
		{"2222222222"},
		{"2         "},
		{"2         "},
		{"2         "},
		{"2         "},
		{"2222222222"}
	},
	{
		{"3333333333"},
		{"         3"},
		{"         3"},
		{"         3"},
		{"         3"},
		{"3333333333"},
		{"         3"},
		{"         3"},
		{"         3"},
		{"         3"},
		{"3333333333"}
	},
	{
		{"4        4"},
		{"4        4"},
		{"4        4"},
		{"4        4"},
		{"4        4"},
		{"4444444444"},
		{"         4"},
		{"         4"},
		{"         4"},
		{"         4"},
		{"         4"}
	},
	{
		{"5555555555"},
		{"5         "},
		{"5         "},
		{"5         "},
		{"5         "},
		{"5555555555"},
		{"         5"},
		{"         5"},
		{"         5"},
		{"         5"},
		{"5555555555"}
	},
	{
		{" 666666666"},
		{"66        "},
		{"6         "},
		{"6         "},
		{"6         "},
		{"666666666 "},
		{"6        6"},
		{"6        6"},
		{"6        6"},
		{"6        6"},
		{" 66666666 "}
	},
	{
		{"7777777777"},
		{"         7"},
		{"         7"},
		{"         7"},
		{"         7"},
		{"         7"},
		{"         7"},
		{"         7"},
		{"         7"},
		{"         7"},
		{"         7"}
	},
	{
		{" 88888888 "},
		{"88      88"},
		{"8        8"},
		{"8        8"},
		{"8        8"},
		{" 88888888 "},
		{"8        8"},
		{"8        8"},
		{"8        8"},
		{"88      88"},
		{" 88888888 "}
	},
	{
		{"9999999999"},
		{"9        9"},
		{"9        9"},
		{"9        9"},
		{"9        9"},
		{"9999999999"},
		{"         9"},
		{"         9"},
		{"         9"},
		{"         9"},
		{"9999999999"}
	}
		
};

int main()
{
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	int newWidth = width / 2 - 300;
	int newHeight = height / 2 - 300;

	int winWidth = 640;
	int winHeight = 400;

	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, newWidth, newHeight, winWidth, winHeight, TRUE);
	
	
	int num[5] = { 1, 2, 4,6, 0 };
	char symbol = 178;
	int sekundi;
	cin >> sekundi;
	if (sekundi > 9999 or sekundi < 1) {
		cout << "-1";
		return 0;
	}
	system("CLS");

	for (int k = sekundi; k > 0; k--) {
		int minuti=k/60;
		if (minuti < 100)
			num[0] = 10;
		else
			num[0] = minuti / 100;
		if (minuti < 10)
			num[1] = 0;
		else
			num[1] = (minuti / 10) % 10;
		if (minuti < 1)
			num[2] = 0;
		else
			num[2] = minuti % 10;

		num[3] = (k % 60) / 10;
		num[4] = k % 10;

		cout << "\n" << "\n" << "\n" << "\n" << "\n";
		for (int i = 0; i < 11; i++)
		{
			int j = 0;
			if (num[0] != 1)
				j = 1;
			if(j==1)
				cout << "              ";
			if (j == 0)
				cout << "    ";
			for ( ; j < 5; j++)
			{
				if (j == 3 && i == 3 or j == 3 and i == 6)
					cout << "  " << symbol << "  ";
				if (j == 2 && i == 3 or j == 2 and i == 6)
					cout << numbers[num[j]][i];
				else 
					cout << numbers[num[j]][i] << "     ";
			}

			cout << endl;
		}
		
		Sleep(1000);

		system("CLS");
	}

	Beep(523, 500);
}