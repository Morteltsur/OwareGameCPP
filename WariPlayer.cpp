/*
 * WariPlayer.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: mor
 */

#include "WariPlayer.h"

WariPlayer& WariPlayer::operator=(const WariPlayer& rhs){
	this->points=rhs.points;
	this->name=rhs.name;
	return *this;
}


WariPlayer& WariPlayer::operator+=(unsigned int rhs){
	this->points +=rhs;
	return *this;
}

const WariPlayer operator+(unsigned int p, const WariPlayer& rhs){
	WariPlayer newTile(p+rhs.points);
	return newTile;
}

const WariPlayer operator-(const WariPlayer& rhs,unsigned int lhs){
	WariPlayer newTile(rhs.points-lhs);
	return newTile;
}

bool operator==(const WariPlayer& a, const WariPlayer& b){
	if(a.points==b.points)
		return true;
	return false;
}

bool operator>(const WariPlayer& a, const WariPlayer& b){
	if(a.points>b.points)
		return true;
	return false;
}

bool operator<(const WariPlayer& a, const WariPlayer& b){
	if(a.points<b.points)
		return true;
	return false;
}

bool operator>=(const WariPlayer& a, const WariPlayer& b){
	if(a.points>=b.points)
		return true;
	return false;
}

bool operator<=(const WariPlayer& a, const WariPlayer& b){
	if(a.points<=b.points)
		return true;
	return false;
}

bool operator!=(const WariPlayer& a, const WariPlayer& b){
	if(a.points!=b.points)
		return true;
	return false;
}

void WariPlayer::empty(){
	points=0;
}

