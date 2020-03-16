#include <iostream>
#include <conio.h>
using namespace std;
const int ROWS = 3;
const int COLS = 3;
void MatrixPrint(char arr[ROWS][COLS], const int ROWS, const int COLS);
void Matrix(char arr[ROWS][COLS], const int ROWS, const int COLS);
char Turn(int turn);
void MatrixFill(char arr[ROWS][COLS], const int ROWS, const int COLS, int turn);
char WinCondition(char arr[ROWS][COLS], const int ROWS, const int COLS);
void main()
{
	char arr[ROWS][COLS];
	int turn = 1;
	Matrix(arr, COLS, ROWS);
	do
	{
		system("cls");
		MatrixPrint(arr, COLS, ROWS);
		Turn(turn);
		turn++;
		MatrixFill(arr, COLS, ROWS, turn);
		if (turn > 7)
		{
			system("cls");
			MatrixPrint(arr, COLS, ROWS);
			cout << WinCondition(arr, COLS, ROWS) << " Wins!";
			break;
		}

	} while (turn < 11);
}
void Matrix(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void MatrixPrint(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j];
			if (j == 0 || j == 1)
				cout << " | ";
		}
		if (i == 2) 
		{ 
			cout << endl; break; 
		}
		cout << endl << "--+---+--" << endl;
	}
}
char Turn(int turn)
{
	if (turn % 2 == 1)
	{
		return 'X';
	}
	else
	{
		return'O';
	}
}
void MatrixFill(char arr[ROWS][COLS], const int ROWS, const int COLS, int turn)
{
	char symbol = _getch();
	switch (symbol)
	{
	case '1':arr[2][0] = Turn(turn); break;
	case '2':arr[2][1] = Turn(turn); break;
	case '3':arr[2][2] = Turn(turn); break;
	case '4':arr[1][0] = Turn(turn); break;
	case '5':arr[1][1] = Turn(turn); break;
	case '6':arr[1][2] = Turn(turn); break;
	case '7':arr[0][0] = Turn(turn); break;
	case '8':arr[0][1] = Turn(turn); break;
	case '9':arr[0][2] = Turn(turn); break;
	}
}
char WinCondition(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]))
		{
			return arr[i][i];
		}
	}
	for (int i = 0; i < ROWS; i++)
	{
		if ((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]))
		{
			return arr[i][i];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
	{
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
	{
		return arr[1][1];
	}
}

