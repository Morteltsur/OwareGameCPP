/*
 * WariTile.cpp
 *
 *  Created on: Nov 19, 2017
 *      Author: mor
 */

#include "WariTile.h"

WariTile& WariTile::operator++(){
	this->seeds+=1;
	return *this;
}
const WariTile& WariTile::operator++(int){
	WariTile& temp(*this);
	this->seeds+=1;
	return temp;
}

bool operator==(const WariTile& a, const WariTile& b){
	return (a.seeds==b.seeds);
}

bool operator>(const WariTile& a, const WariTile& b){
	return (a.seeds>b.seeds);
}

bool operator<(const WariTile& a, const WariTile& b){
	return (a.seeds<b.seeds);
}

bool operator>=(const WariTile& a, const WariTile& b){
	return (a.seeds>=b.seeds);
}

bool operator<=(const WariTile& a, const WariTile& b){
	return (a.seeds<=b.seeds);
}

bool operator!=(const WariTile& a, const WariTile& b){
	return (a.seeds!=b.seeds);
}

void WariTile::empty(){
	seeds=0;
}

unsigned int WariTile::getSeeds() const{
	return seeds;
}

const WariTile operator+(const WariTile& lhs, const WariTile& rhs){
	WariTile newTile(lhs.seeds+rhs.seeds);
	return newTile;
}

WariTile& WariTile::operator+=(const WariTile& rhs){
	this->seeds +=rhs.seeds;
	return *this;
}

WariTile& WariTile::operator=(const WariTile& rhs){
	if(this==&rhs)
		return *this;
	else
		this->seeds=rhs.seeds;
	return *this;
}

