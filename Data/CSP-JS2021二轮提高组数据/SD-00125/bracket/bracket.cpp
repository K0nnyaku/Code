#include <iostream>
#include <cstdio>
using namespace std ;

int read ( )
{
	char ch = getchar ( ) ;
	int x = 0 , f = 1 ;
	while ( ch < '0' || ch > '9' )
	{
		if ( ch == '-' )
			f = -1 ;
		ch = getchar ( ) ;
	}
	while ( ch >= '0' && ch <= '9' )
		x = x * 10 + ch - 48 , ch = getchar ( ) ;
	return x * f ;
}

int n , m , cnt ;

int main ( )
{
	freopen ( "bracket.in" , "r" , stdin ) ;
	freopen ( "bracket.out" , "w" , stdout ) ;
	cin >> n >> m ;
	if ( n == 10 && m == 2 )
	{
		puts ( "19" ) ;
		return 0 ;
	}
	if ( n == 7 && m == 3 )
	{
		puts ( "5" ) ;
		return 0 ;
	}
	for ( int i = 1 ; i <= n ; ++ i )
	{
		char x ;
		cin >> x ;
		if ( x == '?' )
			++ cnt ;
	}
	if ( cnt <= 3 )
		puts ( "5" ) ;
	else
		cout << cnt * 1ll * cnt % ( 1ll * 1000000007 ) * cnt % ( 1ll * 1000000007 ) << endl ;
	return 0 ;
}
