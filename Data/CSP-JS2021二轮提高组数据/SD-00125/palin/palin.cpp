#include <iostream>
#include <cstdio>
using namespace std ;

int read ( )
{
	char ch = getchar ( ) ;
	int x = 0 , f = 1 ;
	while ( ch < '0' || ch > '9' )
		ch = getchar ( ) ;
	while ( ch >= '0' && ch <= '9' )
		x = x * 10 + ch - 48 , ch = getchar ( ) ;
	return x * f ;
}

const int N = 500005 ;
int n , a[N<<1] , p[N] , d[N] , l[N] , r[N] , c[N<<1] , clr[N<<1] ;

int find ( int x )
{
	if ( clr [ x ] == x )
		return x ;
	return clr [ x ] = find ( clr [ x ] ) ;
}

int check ( int x , int y )
{
	if ( l [ x ] < l [ y ] && l [ y ] < r [ x ] && r [ x ] < r [ y ] )
		return 1 ;
	if ( l [ y ] < l [ x ] && l [ x ] < r [ y ] && r [ y ] < r [ x ] )
		return 1 ;
	if ( l [ x ] < l [ y ] && r [ y ] < r [ x ] )
		return 2 ;
	if ( l [ y ] < l [ x ] && r [ x ] < r [ y ] )
		return 2 ;
	if ( r [ x ] < l [ y ] )
		return 3 ;
	if ( r [ y ] < l [ x ] )
		return 3 ;
	return 0 ;
}

int main ( )
{
	freopen ( "palin.in" , "r" , stdin ) ;
	freopen ( "palin.out" , "w" , stdout ) ;
	int T = 1 ;
	cin >> T ;
	while ( T -- )
	{
		n = read ( ) ;
		int tab = 1 ;
		for ( int i = 1 ; i <= ( n << 1 ) ; ++ i )
			a [ i ] = read ( ) ;
		for ( int i = 1 ; i <= n ; ++ i )
			if ( a [ i ] != a [ n - i + 1 ] )
				tab = 0 ;
		if ( tab )
		{
			for ( int i = 1 ; i <= ( n << 1 ) ; ++ i )
				printf ( "L" ) ;
			printf ( "\n" ) ;
			continue ;
		}
		int kl , kr ;
		for ( int i = 1 ; i <= ( n << 1 ) ; ++ i )
		{
			if ( d [ a [ i ] ] )
			{
				kl = i ;
				break ;
			}
			d [ a [ i ] ] = i ;
		}
		for ( int i = ( n << 1 ) ; i >= 1 ; -- i )
		{
			if ( d [ a [ i ] ] )
			{
				kr = i ;
				break ;
			}
			d [ a [ i ] ] = i ;
		}
		if ( kr - kl + 1 != n )
		{
			puts ( "-1" ) ;
			continue ;
		}
		puts ( "-1" ) ;
		continue ;
		for ( int i = 1 ; i <= ( n << 1 ) ; ++ i )
		{
			if ( p [ a [ i ] ] )
			{
				l [ a [ i ] ] = p [ a [ i ] ] ;
				r [ a [ i ] ] = i ;
				c [ p [ a [ i ] ] ] = 2 ;
				c [ i ] = 3 ;
			}
			else
				p [ a [ i ] ] = i ;
			clr [ i ] = i ;
		}
		for ( int i = 1 ; i < n ; ++ i )
		{
			for ( int j = i + 1 ; j <= n ; ++ j )
			{
				int op = check ( i , j ) ;
				if ( op == 1 )
					continue ;
				int ul = find ( i ) , ur = find ( i + n ) , vl = find ( j ) , vr = find ( j + n ) ;
				if ( op == 2 )
				{
					clr [ ul ] = vl ;
					clr [ ur ] = vr ;
				}
				else if ( op == 3 )
				{
					clr [ ul ] = vr ;
					clr [ ur ] = vl ;
				}
			}
		}
		int tf = 0 ;
		for ( int i = 1 ; i <= n ; ++ i )
		{
			if ( find ( i ) == find ( i + n ) )
			{
				puts ( "-1" ) ;
				tf = 1 ;
				break ;
			}
		}
		if ( tf ) continue ;
		for ( int i = 1 ; i < ( n << 1 ) ; ++ i )
		{
			int u = c [ i ] , v = c [ i + 1 ] ;
			if ( u & 1 )
				u = n + a [ i ] ;
			else
				u = a [ i ] ;
			if ( v & 1 )
				v = n + a [ i ] ;
			else
				v = a [ i ] ;
			
			if ( u == v )
			{
				
			}
		}
	}
	return 0 ;
}
