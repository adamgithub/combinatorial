#include "combinator.h"

Combinator::Combinator( int k, int n, vector< int >& gears ) : k(k), n(n), gears(gears)
{
	gears.resize( k );
	reset( k );

	// First step
	gears[ 0 ] = -1;
	curr_gear = 0;
}

void inline Combinator::reset( int count )
{
	for( int i = 0; i < count; ++i )
		gears[i] = i;
}

bool inline Combinator::can_turn_gear( int idx )
{
	return gears[idx] + 1 < gears[idx+1];
}

bool inline Combinator::switch_gear( int& idx )
{
	while( ! can_turn_gear( idx ) )
		idx += 1;

	return idx < k;
}

bool Combinator::next()
{
	// Guard
	gears.push_back( n );

	if(! can_turn_gear(curr_gear) ) {
		if(! switch_gear( curr_gear ))
			return false;

		reset( curr_gear );
	}

	gears[curr_gear] += 1;
	if( curr_gear > 0 )
		curr_gear -= 1;

	// No guard
	gears.pop_back();
	return true;
}

