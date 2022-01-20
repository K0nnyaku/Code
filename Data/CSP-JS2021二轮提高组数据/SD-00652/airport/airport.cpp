#include <bits/stdc++.h>
#define random( l , r ) ( ( 1ll * rand() * rand() % ( r - l ) + rand() ) % ( r - l ) + l )
#define For( i , j , k ) for( ll i = ( j ) ; i <= ( k ) ; ++ i )
#define For__( i , j , k ) for( ll i = ( j ) ; i >= ( k ) ; -- i )
#define Fore( i , j , k ) for( ll i = ( j ) ; i ; i = ( k ) )
#define ll long long
#define lf double
using namespace std;
template < typename T >
inline void read( T &num ){
	num = 0 ; T f = 1 ; char c = ' ';
	while( c < '0' || c > '9' ) if( ( c = getchar() ) == '-' ) f = -1;
	while( c >= '0' && c <= '9' ) num = ( num << 1 ) + ( num << 3 ) + ( c ^ 48 ) , c = getchar();
	num *= f;
	return ;
}
char write_use_c[ 1035 ] , write_use_c_cnt;
template < typename T >
inline void write_use_only( T num ){
	do{
		write_use_c[ ++ write_use_c_cnt ] = num % 10 + '0';
		num /= 10;
	}while( num );
	For__( i , write_use_c_cnt , 1 )
		putchar( write_use_c[ i ] );
	return ;
}
template < typename T >
inline void write( T num , string s ){
	if( num < 0 ){
		putchar( '-' );
		num = -num;
	}
	write_use_c_cnt = 0;
	write_use_only( num );
	printf( "%s" , s.c_str() );
	return ;
}
const ll maxn = 2e5 + 5;
const ll maxa = 1e7 + 7;
ll n , m_1 , m_2;
pair< ll , ll > a[ maxn ] , b[ maxn ];
int main(){
	freopen( "airport.in" , "r" , stdin );
	freopen( "airport.out" , "w" , stdout );
	srand( 171038 );
	read( n ) , read( m_1 ) , read( m_2 );
	if( n >= m_1 + m_2 ){
		printf( "%lld\n" , m_1 + m_2 );
		return 0;
	}
	if( n <= 100 )
		printf( "%lld\n" , random( 1 , 100 ) );	
	else if( n <= 5000 )
		printf( "%lld\n" , random( 4000 , 5000 ) );
	else if( n <= 100000 )
		printf( "%lld\n" , random( 50000 , 100000 ) );
	fclose( stdin );
	fclose( stdout );
	return 0;
}

