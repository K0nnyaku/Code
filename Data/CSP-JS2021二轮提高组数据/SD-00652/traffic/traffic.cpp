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
int main(){
	freopen( "traffic.in" , "r" , stdin );
	freopen( "traffic.out" , "w" , stdout );
	fclose( stdin );
	fclose( stdout ); 
	return 0;
}

