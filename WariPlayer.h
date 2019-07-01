/*
 * Player.h
 *
 *  Created on: Nov 30, 2017
 *      Author: mor
 */

#ifndef WARIPLAYER_H_
#define WARIPLAYER_H_
#include <string>
using namespace std;


class WariPlayer {
private:
	unsigned int points;
	char name;
public:
	WariPlayer(char c):points(0),name(c){}	//c'tor
	WariPlayer(const WariPlayer& p):points(p.points),name(p.name){}	//copy c'tor
	WariPlayer(unsigned int p):points(p),name('t'){}	//conversion c'tor
	~WariPlayer(){}	//d'tor

	//operators:
	WariPlayer& operator=(const WariPlayer& rhs);
	WariPlayer& operator+=(unsigned int rhs);
	friend const WariPlayer operator+(unsigned int lhs, const WariPlayer& rhs);
	friend const WariPlayer operator-(const WariPlayer& lhs,unsigned int rhs);
	friend bool operator==(const WariPlayer& a, const WariPlayer& b);
	friend bool operator>(const WariPlayer& a, const WariPlayer& b);
	friend bool operator<(const WariPlayer& a, const WariPlayer& b);
	friend bool operator>=(const WariPlayer& a, const WariPlayer& b);
	friend bool operator<=(const WariPlayer& a, const WariPlayer& b);
	friend bool operator!=(const WariPlayer& a, const WariPlayer& b);

	char getName() const{return name;}	//returns player's name
	void empty();	//empties player's points
	unsigned int getPoints()const{return points;}	//return's player's points
};

#endif /* WARIPLAYER_H_ */
