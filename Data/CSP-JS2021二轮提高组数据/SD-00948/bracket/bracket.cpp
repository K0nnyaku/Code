//
/*
Author : Zmonarch
Knowledge :
*/
#include <bits/stdc++.h>
using namespace std ;
const int N = 1e6 + 10 ;
const int mod = 1e9 + 7 ; 
int read() {
	int x = 0 , f = 1 ; char ch = getchar() ;
	while(!isdigit(ch)) {if(ch == '-') f = - 1; ch = getchar();}
	while( isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f ;
}
int n , m , Ans ; 
int a[N] , sta[N]; 
char s[N] ;
int f[N] , g[N] ;
bool check() {
	int tmp = 0 , t1 = 0 , top = 0 ; bool tag = true ;
	for(int i = 1 ; i <= n ; i++) 
	{
		if(s[i] == '(') t1++ , sta[++top] = i ; 
		else if(s[i] == ')') t1-- , f[sta[top]] = i , top-- , tmp = 0;
		if(s[i] == '*')
		{
			++tmp ; 
			if(tmp > m) return false ;
			if(s[i + 1] == '*') continue ;
			if(s[i - 1] == ')') 
			{
				int p ; 
				for(int j = 1 ; j <= i - 1 ; j++) if(s[j] == '*') p = j ; 
				int tL = 0 , tR = 0 ; 
				for(int k = p ; k <= i - 2 ; k++) 
				{
					if(s[k] == '(')  tL++ ; 
					else if(s[k] == ')') tR++ ; 
				}
				if(tR >= tL) return false ; 
			}
			
		} 
		if(t1 < 0) return false ;  
	}
	if(t1 || tmp) return false ; 
	
}

void dfs(int num) {
	if(num == n + 1) 
	{
		int t1 = 0 , t2 = 0 , tmp = 0 ; 
		bool tag = check() ; 
		if(tag) Ans++ ; 
		return ; 
	}
	if(s[num] != '?') dfs(num + 1) ; 
	else 
	{
		s[num] = '*' , dfs(num + 1) , s[num] = '?' ; 
		s[num] = '(' , dfs(num + 1) ; s[num] = '?' ; 
		s[num] = ')' , dfs(num + 1) ; s[num] = '?' ; 
	}
	return ; 
}
void Solve1() {
	dfs(1) ; 
	printf("%lld\n" , ((Ans % mod) + mod) % mod) ; 
} 
int main() {
	freopen("bracket.in" , "r" , stdin) ; 
	freopen("bracket.out" , "w" , stdout) ; 
	n = read() , m = read() ; cin >> s + 1 ; 
	Solve1() ;
	fclose(stdin) ; fclose(stdout) ; 
	return 0 ;
}
/*
7 3 
(*??*??
*/
