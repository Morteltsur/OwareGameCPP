/*
 * WariController.h
 *
 *  Created on: Nov 30, 2017
 *      Author: mor
 */

#ifndef WARICONTROLLER_H_
#define WARICONTROLLER_H_
#include "WariLogic.h"
#include "WariUI.h"

class WariController {
private:
	WariLogic game;
	WariUI ui;
	WariPlayer S;
	WariPlayer N;

public:
	WariController():game(),ui(),S('S'),N('N'){}	//default c'tor
	WariController(const WariController& copy):game(copy.game),S(copy.S),N(copy.N){}	//copy c'tor
	~WariController(){}	//d'tor

	void Play();	//game control
	bool checkWinner()const;	//returns true if a player pass 25 points
	WariPlayer checkLeader() const;	//returns lead player
	WariController& operator=(const WariController& rhs);
};

#endif /* WARICONTROLLER_H_ */
