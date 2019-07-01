/*
 * WariBoard.h
 *
 *  Created on: Nov 19, 2017
 *      Author: mor
 */

#ifndef WARIBOARD_H_
#define WARIBOARD_H_

#include "WariTile.h"
class WariBoard {
public:
	enum {BOARD_SIZE=12};
private:
	WariTile board[BOARD_SIZE];

public:
	WariBoard(){}	//default c'tor
	WariBoard(const WariBoard& b);	//copy c'tor
	~WariBoard(){}	//d'tor
	void increaseTile(unsigned int i);	//increases given tile index (by index)
	unsigned int emptyTile(unsigned int index); //returns value of seeds in tile emptied
	WariTile getTile(unsigned int i) const;	//returns copy of given tile (by index)
	void setTile(unsigned int i, unsigned int val);	//sets tile of given index
	bool is_S_empty() const;	//returns true if S side of board empty
	bool is_N_empty() const;	//returns true if N side of board empty
	bool isEmpty() const;	//returns true if all board empty
	unsigned int operator[](unsigned int i);	//access to number of seeds in given tile index
	WariBoard& operator=(const WariBoard& b);	//assignment operator
};

#endif /* WARIBOARD_H_ */
