#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std ;
const int MAXN = 1e5 + 7 ;
struct Edge{
	int a , b , opt ;
}G1[ MAXN ] , G2[ MAXN ] ; 
int cntn , cntw ;
int pren[ MAXN ] , prew[ MAXN ] , visf[ MAXN ] ;
int ansn[ MAXN ] , answ[ MAXN ] ;
int n , m1 , m2 ;
bool cmp( Edge x , Edge y ){
	return x.a < y.a ;
}
bool cmp2( int a , int b ){
	return a > b ;
}
void Init(){
	cntn = 0 , cntw = 0 ;
	for( int i = 1 ; i <= m1 ; i ++ ){
		for( int j = 1 ; j <= cntn ; j ++ ){
			if( G1[ i ].a < pren[ j ] ){
				continue ;
			}else{
				visf[ i ] = 1 ;
				pren[ j ] = G1[ i ].b ;
				ansn[ j ] ++ ;
				break ;
			}
		}
		if( visf[ i ] == 0 ){
			cntn ++ ;
			pren[ cntn ] = G1[ i ].b ;
			visf[ i ] = 1 ;
			ansn[ cntn ] ++ ; 
		}
	}
	memset( visf , 0 , sizeof(visf ) ) ;
	for( int i = 1 ; i <= m2 ; i ++ ){
		for( int j = 1 ; j <= cntw ; j ++ ){
			if( G2[ i ].a < prew[ j ] ){
				continue ;
			}else{
				visf[ i ] = 1 ;
				prew[ j ] = G2[ i ].b ;
				answ[ j ] ++ ;
				break ;
			}
		}
		if( visf[ i ] == 0 ){
			cntw ++ ;
			prew[ cntw ] = G2[ i ].b ;
			visf[ i ] = 1 ;
			answ[ cntw ] ++ ; 
		}
	}
	
}
int main(){
	freopen( "airport.in" , "r" , stdin ) ;
	freopen( "airport.out" , "w" , stdout ) ;
	cin >> n >> m1 >> m2 ;
	for( int i = 1 ; i <= m1 ; i ++ ){
		cin >> G1[ i ].a >> G1[ i ].b ;
	}
	for( int i = 1 ; i <= m2 ; i ++ ){
		cin >> G2[ i ].a >> G2[ i ].b ;
	}
	sort( G1 + 1 , G1 + 1 + m1 , cmp ) ;
	sort( G2 + 1 , G2 + 1 + m2 , cmp ) ;
	Init() ;
	int ans = 0 ;
	for( int i = 0 ; i <= n ; i ++ ){
		int t1 = i , t2 = n - i ;
		int sum = 0 ;
		for( int j = 1 ; j <= t1 ; j ++ ){
			sum += ansn[ j ] ;
		}
		for( int j = 1 ; j <= t2 ; j ++ ){
			sum += answ[ j ] ;
		}
		ans = max(sum , ans ) ;
	}
	cout << ans <<endl ;
	fclose( stdin ) ;
	fclose( stdout ) ;
	return 0 ;
}
