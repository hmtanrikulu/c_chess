#include "Game.h"

// Use new Piece.pieceMaker()
Piece* Game::pieceMaker(int row, int col, string name, bool isWhite) {
	if (name == "Queen") {
		return new Queen(row, col, isWhite);
	}
	else if (name == "King") {
		return new King(row, col, isWhite);
	}
	else if (name == "Rook") {
		return new Rook(row, col, isWhite);
	}
	else if (name == "Knight") {
		return new Knight(row, col, isWhite);
	}
	else if (name == "Pawn") {
		return new Pawn(row, col, isWhite);
	}
	else if (name == "Bishop") {
		return new Bishop(row, col, isWhite);
	}
}

Game::Game() {
	this->isWhite = true;
	this->history = {};
	//Black Pieces
		// New Vers.
	
	this->board[0][0] = pieceMaker(0,0,"Rook", 0);
	this->board[0][1] = pieceMaker(0, 0, "Knight", 0);
	this->board[0][2] = pieceMaker(0, 0, "Bishop", 0);
	this->board[0][3] = pieceMaker(0, 0, "Queen", 0);
	this->board[0][4] = pieceMaker(0, 0, "King", 0);
	this->board[0][5] = pieceMaker(0, 0, "Bishop", 0);
	this->board[0][6] = pieceMaker(0, 0, "Knight", 0);
	this->board[0][7] = pieceMaker(0, 0, "Rook", 0);
	this->board[1][0] = pieceMaker(0, 0, "Pawn", 0);
	this->board[1][1] = pieceMaker(0, 0, "Pawn", 0);
	this->board[1][2] = pieceMaker(0, 0, "Pawn", 0);
	this->board[1][3] = pieceMaker(0, 0, "Pawn", 0);
	this->board[1][4] = pieceMaker(0, 0, "Pawn", 0);
	this->board[1][5] = pieceMaker(0, 0, "Pawn", 0);
	this->board[1][6] = pieceMaker(0, 0, "Pawn", 0);
	this->board[1][7] = pieceMaker(0, 0, "Pawn", 0);
	//White Pieces
	this->board[7][0] = pieceMaker(0,0,"Rook", 0);
	this->board[7][1] = pieceMaker(0, 0, "Knight", 0);
	this->board[7][2] = pieceMaker(0, 0, "Bishop", 0);
	this->board[7][3] = pieceMaker(0, 0, "Queen", 0);
	this->board[7][4] = pieceMaker(0, 0, "King", 0);
	this->board[7][5] = pieceMaker(0, 0, "Bishop", 0);
	this->board[7][6] = pieceMaker(0, 0, "Knight", 0);
	this->board[7][7] = pieceMaker(0, 0, "Rook", 0);
	this->board[6][0] = pieceMaker(0, 0, "Pawn", 0);
	this->board[6][1] = pieceMaker(0, 0, "Pawn", 0);
	this->board[6][2] = pieceMaker(0, 0, "Pawn", 0);
	this->board[6][3] = pieceMaker(0, 0, "Pawn", 0);
	this->board[6][4] = pieceMaker(0, 0, "Pawn", 0);
	this->board[6][5] = pieceMaker(0, 0, "Pawn", 0);
	this->board[6][6] = pieceMaker(0, 0, "Pawn", 0);
	this->board[6][7] = pieceMaker(0, 0, "Pawn", 0);
}

bool Game::move() {
	string prompt;
	int r1, c1, r2, c2;
	cout << "Enter your move (e.g., 'a2 to a4'): ";
	cin >> prompt; // 'a2 to a4'
	for (int i = 0; i < prompt.length(); i++) {
		tolower(prompt[i]);
	}
	r1 = 'a' - stoi((prompt.substr(0, 1)));
	c2 = stoi((prompt.substr(1, 1)));
	r2 = 'a' - stoi((prompt.substr(6, 1)));
	c2 = stoi((prompt.substr(7, 1)));
	while (this->board[r1][c1] == nullptr) move();
	if (this->board[r1][c1] != nullptr) {
		this->board[r1][c1] // burda move nasýl yapýlacak amk !!!!!
	}


	this->history.insert(prompt);
}

