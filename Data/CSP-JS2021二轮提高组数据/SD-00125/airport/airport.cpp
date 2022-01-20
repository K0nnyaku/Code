#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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

const int N = 100005 ;
int n , m1 , m2 , da[N] , db[N] , t[N<<2] , ans ;
pair < int , int > a[N] ;

void change ( int k , int l , int r , int x , int y )
{
	if ( l == r )
	{
		t [ k ] = y ;
		return ;
	}
	int mid = ( l + r ) >> 1 ;
	if ( x <= mid )
		change ( k << 1 , l , mid , x , y ) ;
	else
		change ( k << 1 | 1 , mid + 1 , r , x , y ) ;
	t [ k ] = min ( t [ k << 1 ] , t [ k << 1 | 1 ] ) ;
}

int query ( int k , int l , int r , int x )
{
	if ( t [ k ] > x )
		return n + 1 ;
	if ( l == r )
		return l ;
	int mid = ( l + r ) >> 1 , res = n + 1 ;
	if ( t [ k << 1 ] < x )
		return query ( k << 1 , l , mid , x ) ;
	return query ( k << 1 | 1 , mid + 1 , r , x ) ;
}

int main ( )
{
	freopen ( "airport.in" , "r" , stdin ) ;
	freopen ( "airport.out" , "w" , stdout ) ;
	n = read ( ) ;
	m1 = read ( ) ;
	m2 = read ( ) ;
	for ( int i = 1 ; i <= m1 ; ++ i )
	{
		a [ i ] .first = read ( ) ;
		a [ i ] .second = read ( ) ;
	}
	sort ( a + 1 , a + 1 + m1 ) ;
	change ( 1 , 1 , n , 1 , a [ 1 ] .second ) ;
	++ da [ 1 ] ;
	for ( int i = 2 ; i <= m1 ; ++ i )
	{
		int k = query ( 1 , 1 , n , a [ i ] .first ) ;
		if ( k == n + 1 )
			continue ;
		++ da [ k ] ;
		change ( 1 , 1 , n , k , a [ i ] .second ) ;
	}
	memset ( t , 0 , sizeof ( t ) ) ;
	for ( int i = 1 ; i <= m2 ; ++ i )
	{
		a [ i ] .first = read ( ) ;
		a [ i ] .second = read ( ) ;
	}
	sort ( a + 1 , a + 1 + m2 ) ;
	change ( 1 , 1 , n , 1 , a [ 1 ] .second ) ;
	++ db [ 1 ] ;
	for ( int i = 2 ; i <= m2 ; ++ i )
	{
		int k = query ( 1 , 1 , n , a [ i ] .first ) ;
		if ( k == n + 1 )
			continue ;
		++ db [ k ] ;
		change ( 1 , 1 , n , k , a [ i ] .second ) ;
	}
	for ( int i = 1 ; i <= n ; ++ i )
	{
		da [ i ] += da [ i - 1 ] ;
		db [ i ] += db [ i - 1 ] ;
	}
	for ( int i = 0 ; i <= n ; ++ i )
		ans = max ( ans , da [ i ] + db [ n - i ] ) ;
	cout << ans << endl ;
	return 0 ;
}
