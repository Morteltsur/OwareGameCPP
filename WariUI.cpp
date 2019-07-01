/*
 * WariUi.cpp
 *
 *  Created on: Nov 21, 2017
 *      Author: mor
 */
#include "WariUI.h"


void WariUI::printBoard(const WariBoard& board,const WariPlayer& n,const WariPlayer& s)const{
	cout<<n.getPoints()<<endl;
	cout<<"N:	";
	for(int i=SIZE_S_N-1; i>=0; i--){
		if(i==0)
			cout<<"["<<(char)(i+'a')<<"] "<<board.getTile(i).getSeeds();
		else
			cout<<"["<<(char)(i+'a')<<"] "<<board.getTile(i).getSeeds()<<"	";
	}
	cout<<endl<<"S:	";
	for(int i=SIZE_S_N; i<SIZE_S_N*2; i++){
		if(i==board.BOARD_SIZE-1)
			cout<<"["<<(char)(i+-SIZE_S_N+'a')<<"] "<<board.getTile(i).getSeeds();
		else
			cout<<"["<<(char)(i+-SIZE_S_N+'a')<<"] "<<board.getTile(i).getSeeds()<<"	";
	}
	cout<<endl<<s.getPoints()<<endl;
}

void WariUI::printInitBoard(const WariBoard& board)const{
	cout<<"N:	";
	for(int i=SIZE_S_N-1; i>=0; i--){
		if(i==0)
			cout<<"["<<(char)(i+'a')<<"] "<<board.getTile(i).getSeeds();
		else
			cout<<"["<<(char)(i+'a')<<"] "<<board.getTile(i).getSeeds()<<"	";
	}
		cout<<endl<<"S:	";
		for(int i=SIZE_S_N; i<SIZE_S_N*2; i++){
			if(i==board.BOARD_SIZE-1)
				cout<<"["<<(char)(i+-SIZE_S_N+'a')<<"] "<<board.getTile(i).getSeeds();
			else
				cout<<"["<<(char)(i+-SIZE_S_N+'a')<<"] "<<board.getTile(i).getSeeds()<<"	";
		}
		cout<<endl;
	}


void WariUI::invalidMove()const {
	cout<<"Invalid move; the game awaits a valid move."<<endl;
}

void WariUI::announceWinner(const WariPlayer& p)const{
	cout<<p.getName()<<" wins the game.";
}

void WariUI::announceTie()const{
	cout<<"The game ends in a tie."<<endl;
}


string WariUI::getMove()const{
	string s;
	getline(cin, s);
	return s;
}

void WariUI::PlayerNow(const WariPlayer& p)const{
	cout<<p.getName()<<":"<<endl;;
}

void WariUI::Quit(const WariPlayer& p)const{
	cout<<p.getName()<<": QUIT"<<endl;
}






