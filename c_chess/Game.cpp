#include "Game.h"

Game::Game() {
	this->isWhite = true;
	this->history = {};
	board[0][0] = King(0, 0, 0);
}


bool Game::move() {
	string prompt;
	int r1, c1, r2, c2;
	cout << "Enter your move (e.g., 'a2 to a4'): ";
	cin >> prompt;
	for (int i = 0; i < prompt.length(); i++) {
		tolower(prompt[i]);
	}
	r1 = 'a' - stoi((prompt.substr(0, 1)));
	c2 = stoi((prompt.substr(1, 1)));
	r2 = 'a' - stoi((prompt.substr(6, 1)));
	c2 = stoi((prompt.substr(7, 1)));
	int t1 = 1;
	int t2 = 2;
	board[0][0].someMethod();
	return 0;
}

