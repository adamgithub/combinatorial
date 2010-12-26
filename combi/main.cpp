#include <vector>
#include <iostream>
#include <sstream>
#include "combinator.h"

template< typename T >
ostream& operator<< ( ostream& os, vector< T > const v )
{
	typename vector< T >::const_iterator it = v.begin();
	typename vector< T >::const_iterator et = v.end();

	for( ; it != et; ++it )
		os << *it << " ";
	return os;
}

int main( int argc, char *argv[] )
{
	if( argc != 3 ) {
		cout << "Usage: " << argv[0] << " k n" << endl;
		return 1;
	}

	int k, n;

	stringstream sstrm;
	sstrm << argv[1] << " " << argv[2];
	sstrm >> k >> n;
	cout << "k = " << k << " n = " << n << endl;


	Combinator cmb( k, n );
	vector< int > v( k );

	while( cmb(v) )
		cout << v << endl;
}

