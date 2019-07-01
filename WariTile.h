/*
 * WariTile.h
 *
 *  Created on: Nov 19, 2017
 *      Author: mor
 */

#ifndef WARITILE_H_
#define WARITILE_H_

class WariTile {
private:
	enum {START=4};
	unsigned int seeds;
public:
	WariTile():seeds(START){}	//default c'tor
	WariTile(unsigned int n): seeds(n){}	//conversion c'tor
	WariTile(const WariTile& w):seeds(w.seeds){}	//copy c'tor
	~WariTile(){}	//d'tor

	//operators:

	//prefix ++
	WariTile& operator++();
	//postfix ++
	const WariTile& operator++(int);
	WariTile& operator+=(const WariTile& rhs);
	friend const WariTile operator+(const WariTile& lhs, const WariTile& rhs);
	friend bool operator==(const WariTile& a, const WariTile& b);
	friend bool operator>(const WariTile& a, const WariTile& b);
	friend bool operator<(const WariTile& a, const WariTile& b);
	friend bool operator>=(const WariTile& a, const WariTile& b);
	friend bool operator<=(const WariTile& a, const WariTile& b);
	friend bool operator!=(const WariTile& a, const WariTile& b);
	WariTile& operator=(const WariTile& a);

	void empty();	//tile seeds=0
	unsigned int getSeeds() const;	//returns tile seeds
};

#endif /* WARITILE_H_ */
