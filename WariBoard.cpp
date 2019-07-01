/*
 * WariBoard.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: mor
 */

#include "WariBoard.h"
#include <cstdlib>

WariBoard::WariBoard(const WariBoard& b){
	*this=b;
}

void WariBoard::increaseTile(unsigned int i){
	if(i>=0 && i<BOARD_SIZE)
		board[i]++;
}

unsigned int WariBoard::emptyTile(unsigned int index){
	unsigned int to_ret=0;
	if(index>=0 && index<BOARD_SIZE){
		to_ret=board[index].getSeeds();
		board[index].empty();
	}
	return to_ret;
}

WariTile WariBoard::getTile(unsigned int i) const{
	if(i>=0 && i<BOARD_SIZE){
		WariTile to_ret;
		to_ret=(board[i]);
		return to_ret;
	}
	WariTile w(0);
	return w;
}

void WariBoard::setTile(unsigned int i, unsigned int val){
	if(i>=0 && i<BOARD_SIZE)
		board[i]=val;
}


bool WariBoard::isEmpty() const{
	return (is_S_empty() && is_N_empty());
}

bool WariBoard::is_N_empty() const{
	for(int i=0; i<BOARD_SIZE/2; i++){
		if(board[i]!=0)
			return false;
	}
	return true;
}

bool WariBoard::is_S_empty() const{
	for(int i=BOARD_SIZE/2; i<BOARD_SIZE; i++){
		if(board[i]!=0)
			return false;
	}
	return true;
}



unsigned int WariBoard::operator[](unsigned int i)
{
	if(i<0 || i>=BOARD_SIZE)
		exit(1);
	return board[i].getSeeds();
}

WariBoard& WariBoard::operator=(const WariBoard& rhs){
	if(this==&rhs) // copying from the same object
		return *this;
	else
		for(int i=0; i<BOARD_SIZE; i++){
			board[i]=rhs.board[i];
		}
	return *this;
}

