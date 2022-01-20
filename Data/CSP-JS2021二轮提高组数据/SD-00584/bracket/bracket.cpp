#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <stack>
using namespace std ;
const int MAXN = 501 ;
int n , k ;
char s[ MAXN ] ; 
int ans ;
int num[ MAXN ] , cnt ;
inline bool checki( char *m ){
	int lend = strlen( m ) ;
	stack< char > S ;
	stack< int >id ;
	if( (m[ 0 ] == '*' || m[ lend - 1 ] == '*') || (m[ 0 ] == ')' || m[ lend - 1 ] == '(') ){
		return 0 ;
	}
	int cnt = 0 ;
	for( int i = 0 ; i < lend ; i ++ ){
		if( m[ i ] == '(' ){
			S.push( '(' ) ;
			id.push( i ) ;
			cnt = 0 ;
			continue ;
		}
		
		if( m[ i ] == ')' ){
			if( (S.top() == '(' && m[ id.top() - 1 ] == '*') && m[ i + 1 ] == '*' ){
				return 0 ;
			}
			S.pop() ;
			id.pop() ;
			cnt = 0 ;
			continue ;
		} 
		
 		if( m[ i ] == '*' ){
			cnt ++ ;
		}
		
		if( cnt > k ){
			return 0 ;
		}
	}
	if( !S.empty() ){
		return 0 ;
	}
	return 1 ;
}

void solve( int now ){
	if(now == cnt + 1 ){
		if( checki( s ) ){
			ans ++ ;
		}
		return ;
	}
	s[ num[ now ] ] = '(' ;
	solve( now + 1 ) ;
	
	s[ num[ now ] ] = ')' ;
	solve( now + 1 ) ;
	
	s[ num[ now ] ] = '*' ;
	solve( now + 1 ) ;
}
int main(){
	freopen( "bracket.in" , "r" , stdin ) ;
	freopen( "bracket.out" , "w" , stdout ) ;
	cin >> n >> k ;
	for( int i = 0 ; i < n ; i ++ ){
		cin >>s[ i ] ;
	}
	int len = strlen( s ) ;
	for( int i = 0 ; i < len ; i ++ ){
		if(s[ i ] == '?' ){
			num[ ++ cnt ] = i ;
		}
	}
	solve( 1 ) ;
	cout << ans << endl ;
	fclose( stdin ) ;
	fclose( stdout ) ;
	return 0 ;
}
/*
7 3
(*??*??
*/
