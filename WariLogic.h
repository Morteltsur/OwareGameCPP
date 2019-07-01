/*
 * WariLogic.h
 *
 *  Created on: Nov 30, 2017
 *      Author: mor
 */

#ifndef WARILOGIC_H_
#define WARILOGIC_H_
#include "WariBoard.h"
#include "WariPlayer.h"


class WariLogic {
private:
	WariBoard board;
	enum {MAX_SEEDS=12, DIFF=6};

	bool checkAfterMove(string s, const WariPlayer& player) const;	//check board situation after hypothetical move
	bool existOtherMove(string s, const WariPlayer& p) const;	//check if there is a different move available
public:

	WariLogic():board(){}	//default c'tor
	WariLogic(const WariLogic& copy):board(copy.board){}	//copy c'tor
	~WariLogic(){}	//d'tor

	bool isEnd()const;	//checks if no more seeds in game
	void makeMove(string s, WariPlayer& p);	//makes a move
	bool isMoveLegal(string s, const WariPlayer& p);		//check validity of move according to rules
	bool isMoveInputLegal(string s);		//check if move input is legal

	unsigned int getSumTiles(char c) const;		//returns sum of seeds in player `
	void collectPoints(WariPlayer& p, unsigned int last_tile);
	const WariBoard getBoard()const {return WariBoard(board);}	//returns a copy of the board
	WariLogic& operator=(const WariLogic& rhs);


};

#endif /* WARILOGIC_H_ */
