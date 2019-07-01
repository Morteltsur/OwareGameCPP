/*
 * WariUI.h
 *
 *  Created on: Nov 20, 2017
 *      Author: mor
 */

#ifndef WARIUI_H_
#define WARIUI_H_
#include <iostream>
#include "WariBoard.h"
#include "WariPlayer.h"
using namespace std;

class WariUI{
private:
	enum {SIZE_S_N=6};
public:
	WariUI(){}	//default c'tor
	WariUI(const WariUI& ui){};	//copy c'tor
	~WariUI(){}	//d'tor
	void printBoard(const WariBoard& board,const WariPlayer& n,const WariPlayer& s)const;	//prints board with player points
	void printInitBoard(const WariBoard& board)const;	//initial print of board- no player points
	void invalidMove()const;	//prints invalid move
	void announceWinner(const WariPlayer& p)const;	//prints winner
	void announceTie()const;	//prints tie
	void PlayerNow(const WariPlayer& p)const;	//prints "N: " or "S: "
	void Quit(const WariPlayer& p)const;	//prints who quit
	string getMove()const;	//get player move from cin
};

#endif /* WARIUI_H_ */
