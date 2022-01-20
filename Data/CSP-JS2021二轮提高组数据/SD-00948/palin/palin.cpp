//
/*
Author : Zmonarch
Knowledge :
*/
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 10 ;
const int M = 20 ; 
int read() {
	int x = 0 , f = 1 ; char ch = getchar() ;
	while(!isdigit(ch)) {if(ch == '-') f = - 1; ch = getchar();}
	while( isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f ;
}
int n , cnt; 
int a[N] , b[N] , pos[N] ;
char s[N] ; 
string Ans[N] ; 
bool check() {
	for(int i = 1 ; i <= n / 2 ; i++) 
	 if(b[i] != b[n - i + 1]) return false ; 
	return true ;
}
void dfs(int num , int numL , int numR) {
	if(num == n + 1) 
	{
//		for(int i = 1 ; i <= n ; i++) cout << b[i] << " " ; 
//		printf("\n") ; 
		if(!check()) return ; 
		cnt++ ; //cout << cnt << endl ; 
		for(int i = 1 ; i <= n ; i++) 
		{
			if(pos[i] == 0) Ans[cnt] += 'L' ; 
			else Ans[cnt] += 'R' ;
		}
	//	cout << "sb\n" << endl ; 
//		cout << Ans[cnt] << endl ; 
//		for(int i = 1 ; i <= n ; i++) 
//		 printf("%lld " ,b[i]) ; 
//		printf("\n") ; 
		return ; 
	}
	b[num] = a[numL + 1] ; pos[num] = 0 ; 
	dfs(num + 1 , numL + 1 , numR) ; 
	b[num] = 0 ; pos[num] = 0 ; 
	b[num] = a[n - numR] ; pos[num] = 1 ;
	dfs(num + 1 , numL , numR + 1) ;
	b[num] = 0 ; pos[num] = 0 ;
	return ; 
}
int main() {
	freopen("palin.in" , "r" , stdin) ; 
	freopen("palin.out" , "w" , stdout) ; 
	int T = read() ; 
	while(T--) 
	{
		n = read() ; n = (n << 1)  ; cnt = 0 ;
		for(int i = 1 ; i <= n ; i++) a[i] = read() ; 
		if(n <= 30) 
		{
			dfs(1 , 0 , 0) ;  sort(Ans + 1 , Ans + cnt + 1) ; 
			if(!cnt) printf("-1\n") ; 
			else cout << Ans[1] << endl ; 
		}
		for(int i = 1 ; i <= n ; i++) printf("L") ; 
		printf("\n") ; 
	}
	fclose(stdin) ; fclose(stdout) ; 
	return 0 ;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
