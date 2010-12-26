#ifndef KOMBINATOR_H
#define KOMBINATOR_H

#include <vector>
#include <iostream>
using namespace std;

class Combinator {
public:
	vector< int > gears;
	int curr_gear;
	int k;
	int n;

	void inline reset( int count );
	bool inline turn_gear( int idx );
	bool inline switch_gear( int& idx );

public:
	Combinator( int k, int n );
	bool operator() (vector< int >& v);
};

#endif // KOMBINATOR_H

