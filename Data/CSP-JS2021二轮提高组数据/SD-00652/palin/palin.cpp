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
const ll maxn = 2e3 + 5;
ll T;
ll n , a[ maxn << 1 ] , b[ maxn << 1 ] , cnt_b;
char opt[ maxn << 1 ]; ll opt_cnt;
bool visit[ maxn << 1 ] , flag;
inline bool solve(){
	For( i , 1 , ( cnt_b >> 1 ) )
		if( b[ i ] != b[ cnt_b - i + 1 ] ) return false;
	return true;
}
inline void dfs( ll l , ll r ){
	if( l > r ){
		if( solve() ){
			flag = true;
			printf( "%s\n" , opt + 1 );
		}
		return ;
	}
	if( !flag && ( ( r - l + 1 > n && !visit[ a[ l ] ] ) || r - l + 1 <= n ) ){
		visit[ a[ l ] ] = true;
		opt[ ++ opt_cnt ] = 'L';
		b[ ++ cnt_b ] = a[ l ];
		dfs( l + 1 , r );
		-- cnt_b;
		-- opt_cnt;
		if( r - l + 1 > n )
			visit[ a[ l ] ] = false;
	}
	if( !flag && ( ( r - l + 1 > n && !visit[ a[ r ] ] ) || r - l + 1 <= n ) ){
		visit[ a[ r ] ] = true;
		opt[ ++ opt_cnt ] = 'R';
		b[ ++ cnt_b ] = a[ r ];
		dfs( l , r - 1 );
		-- cnt_b;
		-- opt_cnt;
		if( r - l + 1 > n )
			visit[ a[ r ] ] = false;
	}
	return ;
}
int main(){
	freopen( "palin.in" , "r" , stdin );
	freopen( "palin.out" , "w" , stdout );
	read( T );
	while( T -- ){
		memset( visit , 0 , sizeof( visit ) );
		read( n );
		For( i , 1 , ( n << 1 ) )
			read( a[ i ] );
		flag = false;
		cnt_b = opt_cnt = 0;
		dfs( 1 , n << 1 );
		if( !flag ) puts( "-1" );
	}
	fclose( stdin );
	fclose( stdout );
	return 0;
}

