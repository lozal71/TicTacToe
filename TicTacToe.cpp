//ver 0.1 не работает проверка на выигрыш/ничью
#include "pch.h"
#include <iostream>
using namespace std;

const int N = 3; // размерность массива


int tic_tac_toe[N][N]; //массив 3*3
int a, b; //переменные для ввода координат
int flag_space;
int win1, win2;

void InputCoordinates(int num);
void OutputArray();
void OutputCheck();

int main()
{
	setlocale(LC_ALL, "rus");

	for (int i = 0; i < N; i++) //заполняем все ячейки массивов (-1)
	{
		for (int j = 0; j < N; j++)
		{
			tic_tac_toe[i][j] = -1;
		}
	}
	do
	{
		int Gamer1 = 1;
		InputCoordinates(Gamer1);

		OutputArray();
		OutputCheck();

		int Gamer2 = 0;
		InputCoordinates(Gamer2);

		OutputArray();
		OutputCheck();


	} while (flag_space != 0 || win1 != 0 || win2 != 0);

	if (win1 == 0)
	{
		cout << "Выиграл Игрок №1" << endl;
	}
	else if (win2 == 0)
	{
		cout << "Выиграл Игрок №2" << endl;
	}
	else if (flag_space == 0)
	{
		cout << "Игра окончена! Ничья" << endl;
	}

}

void InputCoordinates(int num)
{
	switch (num)
	{
	case 1:
		cout << "Игрок 1 " << endl;
		do
		{
			do
			{
				cout << "Введите координаты (от 0 до 2) крестика (строка, столбец): " << endl;
				cin >> a; cin >> b;
			} while (a < 0 || a > 2 || b < 0 || b > 2);
		} while (tic_tac_toe[a][b] != -1);
		tic_tac_toe[a][b] = 1; // ставим крестик
		break;
	case 0:
		cout << "Игрок 2 " << endl;
		do
		{
			do
			{
				cout << "Введите координаты (от 0 до 2) нолика (строка, столбец): " << endl;
				cin >> a; cin >> b;
			} while (a < 0 || a > 2 || b < 0 || b > 2);
		} while (tic_tac_toe[a][b] != -1);
		tic_tac_toe[a][b] = 0; // ставим нолик
		break;
	}
}

void OutputArray()
{
	//вывод массива
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tic_tac_toe[i][j] == -1)
			{
				cout << " " << " | ";
			}
			else if (tic_tac_toe[i][j] == 1)
			{
				cout << "X" << " | ";
			}
			else if (tic_tac_toe[i][j] == 0)
			{
				cout << "0" << " | ";
			}
		}
		cout << endl;
	}
}
void OutputCheck()
{
	flag_space = 0;
	for (int i = 0; i < N; i++) // проверка на отсутствие ячеек со значением -1 (пустых ячеек)
	{
		for (int j = 0; j < N; j++)
		{
			if (tic_tac_toe[i][j] == -1)
			{
				flag_space++;
			}
		}
	}
	win2 = win1 = 1;
	if (tic_tac_toe[0][0] == 0 && tic_tac_toe[1][1] == 0 && tic_tac_toe[2][2] == 0)
	{
		win2 = 0;
	}
	else if (tic_tac_toe[2][0] == 0 && tic_tac_toe[1][1] == 0 && tic_tac_toe[0][2] == 0)
	{
		win2 = 0;
	}
	else if (tic_tac_toe[0][0] == 0 && tic_tac_toe[1][0] == 0 && tic_tac_toe[2][0] == 0)
	{
		win2 = 0;
	}
	else if (tic_tac_toe[0][1] == 0 && tic_tac_toe[1][1] == 0 && tic_tac_toe[2][1] == 0)
	{
		win2 = 0;
	}
	else if (tic_tac_toe[0][2] == 0 && tic_tac_toe[1][2] == 0 && tic_tac_toe[2][2] == 0)
	{
		win2 = 0;
	}
	else if (tic_tac_toe[0][0] == 0 && tic_tac_toe[0][1] == 0 && tic_tac_toe[0][2] == 0)
	{
		win2 = 0;
	}
	else if (tic_tac_toe[1][0] == 0 && tic_tac_toe[1][1] == 0 && tic_tac_toe[1][2] == 0)
	{
		win2 = 0;
	}
	else if (tic_tac_toe[2][0] == 0 && tic_tac_toe[2][1] == 0 && tic_tac_toe[2][2] == 0)
	{
		win2 = 0;
	}
	//----------------------------------------------------------------------------
	if (tic_tac_toe[0][0] == 1 && tic_tac_toe[1][1] == 1 && tic_tac_toe[2][2] == 1)
	{
		win1 = 0;
	}
	else if (tic_tac_toe[2][0] == 1 && tic_tac_toe[1][1] == 1 && tic_tac_toe[0][2] == 1)
	{
		win1 = 0;
	}
	else if (tic_tac_toe[0][0] == 1 && tic_tac_toe[1][0] == 1 && tic_tac_toe[2][0] == 1)
	{
		win1 = 0;
	}
	else if (tic_tac_toe[0][1] == 1 && tic_tac_toe[1][1] == 1 && tic_tac_toe[2][1] == 1)
	{
		win1 = 0;
	}
	else if (tic_tac_toe[0][2] == 1 && tic_tac_toe[1][2] == 1 && tic_tac_toe[2][2] == 1)
	{
		win1 = 0;
	}
	else if (tic_tac_toe[0][0] == 1 && tic_tac_toe[0][1] == 1 && tic_tac_toe[0][2] == 1)
	{
		win1 = 0;
	}
	else if (tic_tac_toe[1][0] == 1 && tic_tac_toe[1][1] == 1 && tic_tac_toe[1][2] == 1)
	{
		win1 = 0;
	}
	else if (tic_tac_toe[2][0] == 1 && tic_tac_toe[2][1] == 1 && tic_tac_toe[2][2] == 1)
	{
		win1 = 0;
	}
}