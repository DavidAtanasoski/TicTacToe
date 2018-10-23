//
// TicTacToe.cpp
// Basic TicTacToe game
//
// Created by: David Atanasoski on 22 / 10 / 2018
//


#include <iostream>
#include <vector>

using namespace std;

void printTable(vector<vector<char>> brd)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
			{
				cout << " | ";
			}
			cout << brd[i][j] << " | ";
		}
		cout << endl;
	}
}

bool checkWin(vector<vector<char>> brd)
{
	// horizontal 
	if ((brd[0][0] == 'X') && (brd[0][1] == 'X') && (brd[0][2] == 'X'))
		return true;
	else if ((brd[1][0] == 'X') && (brd[1][1] == 'X') && (brd[1][2] == 'X'))
		return true;
	else if ((brd[2][0] == 'X') && (brd[2][1] == 'X') && (brd[2][2] == 'X'))
		return true;

	else if ((brd[0][0] == 'O') && (brd[0][1] == 'O') && (brd[0][2] == 'O'))
		return true;
	else if ((brd[1][0] == 'O') && (brd[1][1] == 'O') && (brd[1][2] == 'O'))
		return true;
	else if ((brd[2][0] == 'O') && (brd[2][1] == 'O') && (brd[2][2] == 'O'))
		return true;

	// vertical
	else if ((brd[0][0] == 'X') && (brd[1][0] == 'X') && (brd[2][0] == 'X'))
		return true;
	else if ((brd[0][1] == 'X') && (brd[1][1] == 'X') && (brd[2][1] == 'X'))
		return true;
	else if ((brd[0][2] == 'X') && (brd[1][2] == 'X') && (brd[2][2] == 'X'))
		return true;

	else if ((brd[0][0] == 'O') && (brd[1][0] == 'O') && (brd[2][0] == 'O'))
		return true;
	else if ((brd[0][1] == 'O') && (brd[1][1] == 'O') && (brd[2][1] == 'O'))
		return true;
	else if ((brd[0][2] == 'O') && (brd[1][2] == 'O') && (brd[2][2] == 'O'))
		return true;

	// diagonal
	else if ((brd[0][0] == 'X') && (brd[1][1] == 'X') && (brd[2][2] == 'X'))
		return true;
	else if ((brd[0][2] == 'X') && (brd[1][1] == 'X') && (brd[2][0] == 'X'))
		return true;

	else if ((brd[0][0] == 'O') && (brd[1][1] == 'O') && (brd[2][2] == 'O'))
		return true;
	else if ((brd[0][2] == 'O') && (brd[1][1] == 'O') && (brd[2][0] == 'O'))
		return true;

	return 0;
}

int main()
{
	int Row;
	int Col;

	bool gameplay = true;
	char player = 'X';

	vector<vector<char>> brd;
	vector<char> row;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			row.push_back('-');
		}
		brd.push_back(row);
	}

	while (gameplay)
	{
		system("cls");

		cout << endl;
		cout << " ---------------------------------------------- " << endl;
		cout << endl;

		printTable(brd);

		cout << endl;

		cout << "Enter row position: "; cin >> Row;
		cout << "Enter column position: "; cin >> Col;

		cout << endl;

		brd[Row][Col] = player;

		if (checkWin(brd))
		{
			system("cls");

			cout << endl;
			cout << " ---------------------------------------------- " << endl;
			cout << endl;

			printTable(brd);

			cout << "----------------------" << endl;
			cout << "That's it!" << endl;
			cout << "Player " << player << " is the winner!" << endl;
			cout << "----------------------" << endl;

			gameplay = false;
		}

		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}

	system("pause");
	return 0;
}
