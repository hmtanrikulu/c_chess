#include "LinkedList.h"
#include <vector>
#ifndef PIECE
#define PIECE

class Piece {
public:
	struct Move {
		int upDown, rightLeft;
		bool operator == (int x[2]) {
			return (this->upDown == x[0] && this->rightLeft == x[1]);
		}
		Move(int x, int y) {
			this->upDown = x;
			this->rightLeft = y;
		}
	};
	string name;
	int row, col;
	bool isWhite;
	LinkedList<Move>moveSet;

	// Move check includes (isInMoveSet, isInBoard, isInterrupted) inside it.
	virtual bool moveCheck(int, int, LinkedList<LinkedList<Piece*>>) = 0;
	bool isInMoveSet(int, int);	
	bool isInBoard(int, int);
	virtual bool isInterrupted(int, int, LinkedList<LinkedList<Piece*>>);
	Piece(int, int, bool, string);
	Piece();
	//~Piece();
};

// dumbMove not complete;
class King :public Piece {
	bool isMoved;
public:
	King(int, int, bool);
	bool isCastle(int, int);
	bool moveCheck(int, int, LinkedList<LinkedList<Piece*>>) override;
	//bool dumbMove(int, int, LinkedList<LinkedList<Piece*>>);
	bool isRookMoved(int, int, LinkedList<LinkedList<Piece*>>);
};

class Queen :public Piece {
public:
	Queen(int, int, bool);
	bool moveCheck(int, int, LinkedList<LinkedList<Piece*>>) override;
}; 

class Rook :public Piece {
public:
	bool isMoved;
	Rook(int, int, bool);
	bool moveCheck(int, int, LinkedList<LinkedList<Piece*>>) override;
};

class Knight :public Piece {
public:
	Knight(int, int, bool);
	bool moveCheck(int, int, LinkedList<LinkedList<Piece*>>) override;
};

class Bishop :public Piece {
public:
	Bishop(int, int, bool);
	bool moveCheck(int, int, LinkedList<LinkedList<Piece*>>) override;
};

class Pawn :public Piece {
	bool isMoved;
public:
	Pawn(int, int, bool);
	void convert(int, int, string, LinkedList<LinkedList<Piece*>>);
	bool isInterrupted(int, int, LinkedList<LinkedList<Piece*>>);
	bool moveCheck(int, int, LinkedList<LinkedList<Piece*>>) override;
	bool crossMove(int, int, LinkedList<LinkedList<Piece*>>);
	bool enPassant(int, int, LinkedList<LinkedList<Piece*>>);
};

#endif