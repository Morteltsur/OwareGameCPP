/*
 * WariLogic.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: mor
 */


#include "WariLogic.h"

void WariLogic::collectPoints(WariPlayer& p, unsigned int last_tile){
	if(p.getName()=='N'){
		if(last_tile%board.BOARD_SIZE<board.BOARD_SIZE/2) //last move fell on N side of board
			return;
	}
	else if(p.getName()=='S'){
		if(last_tile%board.BOARD_SIZE>=board.BOARD_SIZE/2)	//last move fell on S side of board
			return;
	}
	while(board[last_tile%board.BOARD_SIZE]==3 || board[last_tile%board.BOARD_SIZE]==2){ //check for 2-3 seeds
		if(p.getName()=='N'){		//if N reached it's own side of board
			if(last_tile%board.BOARD_SIZE<board.BOARD_SIZE/2)
				return;
		}
		if(p.getName()=='S'){		//if S reached it's own side of board
			if(last_tile%board.BOARD_SIZE>=board.BOARD_SIZE/2)
				return;
		}
		p+=board.emptyTile(last_tile%board.BOARD_SIZE);
		last_tile--; //check 1 tile before
	}
}

void WariLogic::makeMove(string s, WariPlayer& p){
	unsigned int index=s.at(0);
	index-='a';

	if(p.getName()=='S')	//if player is S, play on that side of array/board
		index+=board.BOARD_SIZE/2;

	unsigned int seeds=board.emptyTile(index);	//empty selected tile into seeds
	index++;	//start playing with seeds on next index
	while(seeds!=0){
		if(board[index%board.BOARD_SIZE]==MAX_SEEDS){
			index++;
			continue;
		}
		board.increaseTile(index%board.BOARD_SIZE);
		index++;
		seeds--;
	}
	collectPoints(p, --index);
}

bool WariLogic::isMoveInputLegal(string s){
	if(s.length()!=1)
		return false;
	else if(s.at(0)<'a' || s.at(0)>'f')
		return false;
	return true;
}

bool WariLogic::isMoveLegal(string s, const WariPlayer& p){
	//is the input legal
	if(!isMoveInputLegal(s))
		return false;
	//is tile not empty
	if(p.getName()=='N')
		if(board[s.at(0)-'a']==0) //in north
			return false;

	if(p.getName()=='S')
		if(board[s.at(0)-'a'+DIFF]==0)	//in south
			return false;

	//game rules- if opponent side is empty, does move pass
	//seeds to opponent
	if(p.getName()=='N' && getSumTiles('S')==0){
		if(checkAfterMove(s, p)==false)
			if(existOtherMove(s,p)==true)
				return false;
	}

	if(p.getName()=='S' && getSumTiles('N')==0){
		if(checkAfterMove(s, p)==false)
			if(existOtherMove(s,p)==true){
				return false;
			}
	}

	return true;
}


bool WariLogic::checkAfterMove(string s, const WariPlayer& player) const{
	WariLogic temp=*this;
	WariPlayer tmp_p=player;
	WariPlayer& tmp_pr=tmp_p;
	temp.makeMove(s, tmp_pr);
	if(player.getName()=='N' && temp.getSumTiles('S')!=0)
		return true;
	if(player.getName()=='S' && temp.getSumTiles('N')!=0)
		return true;
	return false;
}

unsigned int WariLogic::getSumTiles(char name) const{
	unsigned int cnt=0;
	WariBoard temp= board;
	if(name=='N'){
		for(int i=0; i<temp.BOARD_SIZE/2; i++){
			cnt+=temp[i];
		}
	}

	if(name=='S'){
		for(int i=temp.BOARD_SIZE/2; i<temp.BOARD_SIZE; i++){
			cnt+=temp[i];
		}
	}
	return cnt;
}

bool WariLogic::existOtherMove(string s, const WariPlayer& p) const{
	WariLogic temp= *this;
	WariPlayer tmp_p=p;
	WariPlayer& tmp_pr=tmp_p;
	for(char i='a'; i<='f'; i++){
		if(i==s.at(0))
			continue;
		string move=&i;
		temp.makeMove(move,tmp_pr);
		if(p.getName()=='N' && temp.getSumTiles('S')!=0)
			return true;
		if(p.getName()=='S' && temp.getSumTiles('N')!=0)
			return true;
		temp=*this;
	}
	return false;
}

bool WariLogic::isEnd()const{
	if(getSumTiles('N')==0 && getSumTiles('S')==0)
		return true;
	return false;
}

WariLogic& WariLogic::operator=(const WariLogic& rhs){
	if(this==&rhs)
		return *this;
	this->board=rhs.board;
	return *this;
}

