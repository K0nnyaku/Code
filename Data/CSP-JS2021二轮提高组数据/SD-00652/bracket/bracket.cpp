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
const ll maxn = 505;
const ll mod = 1e9 + 7;
ll n , k;
char c[ maxn ] , judge[ maxn ];
ll ans;
struct Stack{
	ll stack_my[ maxn ] , stack_top;
	Stack( ll cnt_top_ = 0 ){
		stack_top = cnt_top_;
	}
	inline void push( ll x ){
		stack_my[ ++ stack_top ] = x;
		return ;
	}
	inline void pop(){
		-- stack_top;
	}
	inline ll top(){
		return stack_my[ stack_top ];
	}
	inline bool empty(){
		return !stack_top;
	}
}s;
inline bool solve(){
	/*
	For( i , 1 , n )
		putchar( judge[ i ] );
	putchar( '\n' );
	*/
	ll cnt_xing = 0 , last = 0 , last_stack = 0;
	s.stack_top = 0;
	For( i , 1 , n ){
		if( judge[ i ] == '(' ){
			if( cnt_xing > 0 ){
				last = i - cnt_xing;
				last_stack = s.stack_top;
				cnt_xing = 0;
			}
			s.push( 1 );
		}
		else if( judge[ i ] == ')' ){
			s.pop();
			if( s.stack_top < 0 ) return false;
			cnt_xing = 0;
		}
		else if( judge[ i ] == '*' ){
			++ cnt_xing;
			if( last ){
				if( last_stack == s.stack_top ) return false;
				last = 0;
			}
		}
		if( cnt_xing > k )
			return false;
	}
	if( !s.empty() ) return false;
	if( judge[ 1 ] == '*' || judge[ n ] == '*' )
		return false; 
	
	//puts( "YES" ); 
	return true;
}
inline void dfs( ll p ){
	if( p == n + 1 ){
		if( solve() )
			++ ans;
		return ;
	}
	judge[ p ] = c[ p ];
	if( c[ p ] == '?' ){
		judge[ p ] = '*';
		dfs( p + 1 );
		judge[ p ] = '(';
		dfs( p + 1 );
		judge[ p ] = ')';
		dfs( p + 1 );
	}
	else dfs( p + 1 );
	return ;
}
int main(){
	freopen( "bracket.in" , "r" , stdin );
	freopen( "bracket.out" , "w" , stdout );
	read( n ) , read( k );
	scanf( "%s" , c + 1 );
	dfs( 1 );
	write( ans , "\n" );
	fclose( stdin );
	fclose( stdout );
	return 0;
}

