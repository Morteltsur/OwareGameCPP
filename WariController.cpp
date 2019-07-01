/*
 * WariController.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: mor
 */

#include "WariController.h"

void WariController::Play(){
	string s;
	WariPlayer* activePlayer=&N; //start with north player
	bool game_over=false;
	ui.printInitBoard(game.getBoard());
	while(game_over==false){
		if(game.getSumTiles(activePlayer->getName())!=0){
			ui.PlayerNow(*activePlayer);
			s=ui.getMove();
			if(s=="QUIT" || s=="QUIT "){
				if(*activePlayer==N){
					ui.Quit(*activePlayer);
					ui.announceWinner(S);
					return;
				}
				else{
					ui.Quit(*activePlayer);
					ui.announceWinner(N);
					return;
				}
			}
			while(!game.isMoveLegal(s,*activePlayer)){
				ui.invalidMove();
				s=ui.getMove();
			}
			game.makeMove(s, *activePlayer);
			game_over=checkWinner();
			if(game_over==true)
			{
				ui.announceWinner(*activePlayer);
				return;
			}
			game_over=game.isEnd();
			if(game_over==true)
			{
				ui.announceTie();
				return;
			}
			ui.printBoard(game.getBoard(), N, S);
		}
		if(activePlayer==&N)		//switch player
			activePlayer=&S;
		else
			activePlayer=&N;
	}
}

bool WariController::checkWinner() const{
	unsigned int win=25;
	if(S >=win || N>=win)
		return true;
	return false;
}

WariPlayer WariController::checkLeader() const{
	if(S>N)
		return WariPlayer(S);
	else if(S<N)
		return WariPlayer(N);
	else{
		unsigned int n=game.getSumTiles('N');
		unsigned int s=game.getSumTiles('S');
		if(s>n)
			return WariPlayer(S);
		else if(s<n)
			return WariPlayer(N);
		else
			return WariPlayer('t');
	}
}

WariController& WariController::operator=(const WariController& rhs){
	if(this==&rhs)
		return*this;
	this->game=rhs.game;
	this->S=rhs.S;
	this->N=rhs.N;
	return *this;
}
