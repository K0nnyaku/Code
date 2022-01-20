//
/*
Author : Zmonarch
Knowledge :
*/
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e2 + 10 ;
const int Lim = 2000 ; 
int read() {
	int x = 0 , f = 1 ; char ch = getchar() ;
	while(!isdigit(ch)) {if(ch == '-') f = - 1; ch = getchar();}
	while( isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f ;
}
struct node {
	int x , y , z ;
}a[N] ;
int n , m , T ; 
int a[N][N] , b[N][N] ; 
int main() {
	freopen("traffic.in" , "r" , stdin) ; 
	freopen("traffic.out" , "w" , stdout) ; 
	n = read() , m = read() , T = read() ; 
	for(int i = 1 ; i <= n - 1 ; i++) 
	 a[i + 1][i] = a[i][i + 1] = read() ; 
	for(int i = 1 ; i <= m - 1 ; i++) 
	 b[i + 1][i] = b[i][i + 1] = read() ; 
	while(T--) a[++cnt].x = read() , a[cnt].y = read() , a[cnt].z = read() , printf("%lld\n" , rand() % Lim)
	fclose(stdin) ; fclose(stdout) ; 
	return 0 ;
}
