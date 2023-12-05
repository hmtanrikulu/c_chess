#include "Piece.h"
#ifndef GAME
#define GAME

class Game {
	// Turn
	bool isWhite;
	vector<vector<Piece>> board;
	LinkedList<string> history;
	bool move(); // a2 -> to 2,4
	// bool castleAvailable();
	Game();
	//~Game();
};
#endif