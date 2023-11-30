#include "Piece.h"
#ifndef GAME
#define GAME

struct Piece {};
class Game {
	// Turn
	bool isWhite;
	// Actual Board
	LinkedList<LinkedList<Piece*>> board;
	LinkedList<string> history;
	// Returns a pointer which will be used on board list
	Piece* pieceMaker(int, int, string, bool);
public:
	bool move(); // a2 -> to 2,4
	// bool castleAvailable();
	Game();
	~Game();
};
#endif