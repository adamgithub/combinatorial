#include "combinator.h"

Combinator::Combinator( int k, int n ) : k(k), n(n)
{
	gears.resize( k + 1 );
	reset( k );

	 // Guard
	gears[ k ] = n;

	// First step
	gears[ 0 ] = -1;
	curr_gear = 0;
}

void inline Combinator::reset( int count )
{
	for( int i = 0; i < count; ++i )
		gears[i] = i;
}

bool inline Combinator::turn_gear( int idx )
{
	return gears[idx] + 1 < gears[idx+1];
}

bool inline Combinator::switch_gear( int& idx )
{
	while( ! turn_gear(idx) )
		idx += 1;

	return idx < k;
}

bool Combinator::operator() (vector< int >& v)
{
	if(! turn_gear(curr_gear) ) {
		if(! switch_gear( curr_gear ))
			return false;
		
		reset( curr_gear );
	}

	gears[curr_gear] += 1;
	if( curr_gear > 0 )
		curr_gear -= 1;
	
	for( int i = 0; i < k; ++i )
		v[i] = gears[i];
	return true;
}

