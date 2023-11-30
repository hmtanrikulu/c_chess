#include "Piece.h"

Piece::Piece(int x, int y, bool z, string n) {
	this->name = n;
	this->row = x;
	this->col = y;
	this->isWhite = z;
}
Piece::Piece() {
	this->name =nullptr;
	this->row = NULL;
	this->col = NULL;
	this->moveSet = {};
	this->isWhite = NULL;
}

bool Piece::isInMoveSet(int r2, int c2) {
	int r1 = this->row, c1 = this->col;
	for (int i = 0; i < this->moveSet.size(); i++) {
		int move[2] = { (r2 - r1),(c2 - c1) };
		if (this->moveSet[i] == move) {																										 //		[].getData				t& linkedlist.cpp 71
			return true;
		}
	}
	return false;
}

bool Piece::isInBoard(int r2, int c2) {
	int r1 = this->row, c1 = this->col;
	if (r1 + r2 > 8 || r1 + r2 < 0) return false;
	if (c1 + c2 > 8 || c1 + c2 < 0) return false;
	return true;
}

bool Piece::isInterrupted(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
	int r1 = this->row, c1 = this->col;
	string move = "capraz";
	if (r1 == r2) move = "yatay";
	if (c1 == c2) move = "dikey";
	if ((board[r2][c2] != nullptr) && (board[r2][c2]->isWhite == this->isWhite)) return false;
	if (move == "capraz") {
		bool signR = r2 - r1 > 0 ? true : false;
		bool signC = c2 - c1 > 0 ? true : false;
		int tmpR = r1, tmpC = c1;
		if (signR && signC) {
			for (int i = 0; i < abs(r2 - r1) - 1; i++) {
				tmpR++;
				for (int j = 0; j < abs(c2 - c1) - 1; j++) {
					tmpC++;
					if (board[tmpR][tmpC] != nullptr) return false;
				}
			}
		}
		else if (!signR && signC) {
			for (int i = 0; i < abs(r2 - r1) - 1; i++) {
				tmpR--;
				for (int j = 0; j < abs(c2 - c1 - 1); j++) {
					tmpC++;
					if (board[tmpR][tmpC] != nullptr) return false;
				}
			}
		}
		else if (signR && !signC) {
			for (int i = 0; i < abs(r2 - r1) - 1; i++) {
				tmpR++;
				for (int j = 0; j < abs(c2 - c1) - 1; j++) {
					tmpC--;
					if (board[tmpR][tmpC] != nullptr) return false;
				}
			}
		}
		else if (!signR && !signC) {
			for (int i = 0; i < abs(r2 - r1) - 1; i++) {
				tmpR--;
				for (int j = 0; j < abs(c2 - c1) - 1; j++) {
					tmpC--;
					if (board[tmpR][tmpC] != nullptr) return false;
				}
			}
		}
		else if (move == "yatay") {
			bool sign = c2 - c1 > 0 ? true : false;
			int tmp = c1;
			if (sign) {
				for (int i = 0; i < abs(c2 - c1) - 1; i++) {
					tmp++;
					if (board[r1][tmp] != nullptr) return false;
				}
			}
			else {
				for (int i = 0; i < abs(c2 - c1) - 1; i++) {
					tmp--;
					if (board[r1][tmp] != nullptr) return false;
				}
			}
		}
		else if (move == "dikey") {
			int tmp = r1;
			bool sign = r2 - r1 > 0 ? true : false;
			if (sign) {
				for (int i = 0; i < abs(r2 - r1) - 1; i++) {
					tmp++;
					if (board[tmp][c1] != nullptr) return false;
				}
			}
			else {
				for (int i = 0; i < abs(r2 - r1) - 1; i++) {
					tmp--;
					if (board[tmp][c1] != nullptr) return false;
				}
			}
		}
		return true;
	}

}
	//PIECES STARTS HERE

// Constructors
King::King(int r1, int c1, bool isWhite) {
	LinkedList<Move> moves;
	moves.insert(Move(0, 1));
	moves.insert(Move(0, -1));
	moves.insert(Move(1, 0));
	moves.insert(Move(-1, 0));
	moves.insert(Move(1, 1));
	moves.insert(Move(1, -1));
	moves.insert(Move(-1, -1));
	moves.insert(Move(-1, 1));
	this->row = r1;
	this->col = c1;
	this->isWhite = isWhite;
	this->isMoved = false;
}











Queen::Queen(int r1, int c1, bool isWhite) {
	LinkedList<Move> moves;
	for (int i = -8; i < 9; i++) {
		for (int j = -8; j < 9; j++) {
			moves.insert(Move(i, j));
		}
	}
		this->row = r1;
		this->col = c1;
		this->isWhite = isWhite;
}

Bishop::Bishop(int r1, int c1, bool isWhite) {
	LinkedList<Move> moves;
	for (int i = -8; i < 9; i++) {
		int j = i;
		moves.insert(Move(i, j));
	}
	for (int m = -8; m < 9; m++) {
		int n = m * -1;
		moves.insert(Move(m, n));
	}
	this->row = r1;
	this->col = c1;
	this->isWhite = isWhite;
}

Knight::Knight(int r1, int c1, bool isWhite) : Piece(r1, c1, "Knight", function <LinkedList<Move>>()) {
	LinkedList<Move> moves;
	moves.insert(Move(2, 1));
	moves.insert(Move(1, 2));
	moves.insert(Move(-1, 2));
	moves.insert(Move(-2, 1));
	moves.insert(Move(-2, -1));
	moves.insert(Move(-1, -2));
	moves.insert(Move(1, -2));
	moves.insert(Move(2, -1));
	this->col = c1;
	this->row = r1;
	this->isWhite = isWhite;
}

Rook::Rook(int r1, int c1, bool isWhite) : Piece(r1, c1, "Knight", function <LinkedList<Move>>()) {
	LinkedList<Move> moves;
	for (int i = -8; i < 9; i++) {
		moves.insert(Move(i, 0));
		moves.insert(Move(0, i));
	}
	this->row = r1;
	this->col = c1;
	this->isWhite = isWhite;
	this->isMoved = false;
}

Pawn::Pawn(int r1, int c1, bool isWhite) : Piece(r1, c1, "Knight", function <LinkedList<Move>>()) {
	LinkedList<Move> moves;
	moves.insert(Move(1, 0));
	this->isMoved = false;
}
// MoveChecks
	bool Queen::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool King::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board) && dumbMove(r2, c2, board)) return true;
		else if (isCastle(r2, c2) && isInterrupted(r2, c2, board) && isRookMoved(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Knight::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Bishop::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Rook::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;

		else {
			return false;
		}
	}

	bool Pawn::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else if (crossMove(r2, c2, board) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else if (enPassant(r2, c2, board) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Pawn::isInterrupted(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (c2 == c1) {
			if (board[r2][c2] != nullptr) return true;
		}
		return false;
	}
	
	// Special moves

	bool King::isRookMoved(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		(r2 == 0 && (c2 == 1 || c2 == 6)) || (r2 == 7 && (c2 == 1 || c2 == 6));
		if (r2 == 0 && c2 == 1) {
			if (board[0][0] != nullptr) {
				try {
					Rook* rook = (Rook*)board[0][0];
					if (rook->isMoved) return false;
				}
				catch (exception e) {
					return false;
				}
				return true;
			}
			return false;
		}
		else if (r2 == 0 && c2 == 6) {
			if (board[0][0] != nullptr) {
				try {
					Rook* rook = (Rook*)board[0][7];
					if (rook->isMoved) return false;
				}
				catch (exception e) {
					return false;
				}
				return true;
			}
			return false;
		}
		else if (r2 == 7 && c2 == 1) {
			if (board[7][0] != nullptr) {
				try {
					Rook* rook = (Rook*)board[7][0];
					if (rook->isMoved) return false;
				}
				catch (exception e) {
					return false;
				}
				return true;
			}
			return false;
		}
		else if (r2 == 7 && c2 == 6) {
			if (board[7][7] != nullptr) {
				try {
					Rook* rook = (Rook*)board[7][7];
					if (rook->isMoved) return false;
				}
				catch (exception e) {
					return false;
				}
				return true;
			}
			return false;
		}
	}

	bool King::isCastle(int r2, int c2) {
		if (this->isMoved == true) return false;
		else if ((r2 == 0 && (c2 == 1 || c2 == 6)) || (r2 == 7 && (c2 == 1 || c2 == 6))) return true;
		else return false;
	}

	bool Pawn::enPassant(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (((r2 - r1 == 2) || (r2 - r1 == -2)) && (c2 == c1) && (board[r2][c2] == nullptr)) {
			return true;
		}
		return false;
	}

	bool Pawn::crossMove(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if ((r2 - r1 != 1 && this->isWhite) || (r2 - r1 != -1 && !this->isWhite)) return false;
		if (abs(c2 - c1) != 1) return false;
		if (board[r2][c2] == nullptr) return false;
		if (board[r2][c2]->isWhite == this->isWhite) return false;
		return true;
	}

	void Pawn::convert(int r2, int c2, string convertTo, LinkedList <LinkedList <Piece*>> board) {
		if (((this->isWhite == 1) && (r2 == 7)) || ((this->isWhite == 0) && (r2 == 0))) {
			cout << "Type A The Piece You'd Like To Convert Your Pawn To";
			cin >> convertTo;
			delete this;
		}
	}
	
	bool Queen::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool King::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board) && dumbMove(r2, c2, board)) return true;
		else if (isCastle(r2, c2) && isInterrupted(r2, c2, board) && isRookMoved(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Knight::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Bishop::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Rook::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;

		else {
			return false;
		}
	}

	bool Pawn::moveCheck(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (isInMoveSet(r2, c2) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else if (crossMove(r2, c2, board) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else if (enPassant(r2, c2, board) && isInBoard(r2, c2) && isInterrupted(r2, c2, board)) return true;
		else {
			return false;
		}
	}

	bool Pawn::isInterrupted(int r2, int c2, LinkedList<LinkedList<Piece*>> board) {
		int r1 = this->row, c1 = this->col;
		if (c2 == c1) {
			if (board[r2][c2] != nullptr) return true;
		}
		return false;
	}