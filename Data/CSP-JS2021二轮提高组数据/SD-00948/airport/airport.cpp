//
/*
Author : Zmonarch
Knowledge : 
*/
#include <bits/stdc++.h>
using namespace std ; 
const int N = 1e6 + 10 ; 
const int inf = 2147483647 ; 
int read() {
	int x = 0 , f = 1 ; char ch = getchar() ; 
	while(!isdigit(ch)) {if(ch == '-') f = - 1; ch = getchar();}
	while( isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f ; 
}
int n , m1 , m2 , Ans ; 
struct node {
	int L , R ; 
	bool operator < (const node &m1) const {
		return L ^ m1.L ? L < m1.L : R < m1.R ;  
	}
}a[N] , b[N] ;
struct Node{
	int L , R , Sum1 , Sum2 ;
}st[N];
int v1[N] , v2[N] , Lst[N] ; 
bool vis[N] ; 
void Work1() {
	for(int i = 1 ; i <= n ; i++) vis[i] = 0 , Lst[i] = -1 ; 
	for(int i = 1 ; i <= m1 ; i++) 
	{
		for(int j = 1 ; j <= n ; j++) 
		{
			if(!vis[j] || Lst[j] < a[i].L) 
			{
				vis[j] = 1 ; 
				Lst[j] = a[i].R ;
				v1[j]++ ;  
				break ; 
			}
		}
	}
}
void Work2() {
	for(int i = 1 ; i <= n ; i++) vis[i] = 0 , Lst[i] = -1 ; 
	for(int i = 1 ; i <= m2 ; i++) 
	{
		for(int j = 1 ; j <= n ; j++) 
		{
			if(!vis[j] || Lst[j] < b[i].L) 
			{
				vis[j] = 1 ; 
				Lst[j] = b[i].R ; v2[j]++ ; 
				break ; 
			}
		}
	}	
}
void Pushup(int u) {
	st[u].Sum1 = st[u << 1].Sum1 + st[u << 1 | 1].Sum1 ;
	st[u].Sum2 = st[u << 1].Sum2 + st[u << 1 | 1].Sum2 ; 
}
void Build(int u , int L , int R) {
	st[u].L = L ; st[u].R = R ; 
	if(L == R) return (void)(st[u].Sum1 = v1[L] , st[u].Sum2 = v2[L]) ; 
	int Mid = L + R >> 1 ; 
	Build(u << 1 , L , Mid) ; Build(u << 1 | 1 , Mid + 1 , R) ; 
	Pushup(u) ; 
}
int Q1(int u , int L , int R) {
	if(st[u].L >= L && st[u].R <= R) return st[u].Sum1 ; 
	int Mid = st[u].L + st[u].R >> 1 , ret = 0 ; 
	if(L <= Mid) ret += Q1(u << 1 , L , R) ; 
	if(Mid < R) ret += Q1(u << 1 | 1 , L , R) ; 
	return ret ;
}
int Q2(int u , int L , int R) {
	if(st[u].L >= L && st[u].R <= R) return st[u].Sum2 ; 
	int Mid = st[u].L + st[u].R >> 1 , ret = 0 ; 
	if(L <= Mid) ret += Q2(u << 1 , L , R) ; 
	if(Mid < R) ret += Q2(u << 1 | 1 , L , R) ; 
	return ret ;
}
int main() {
	freopen("airport.in" , "r" , stdin) ; 
	freopen("airport.out" , "w" , stdout) ; 
	n = read() , m1 = read() , m2 = read() ; 
	for(int i = 1 ; i <= m1 ; i++) a[i].L = read() , a[i].R = read() ; 
	for(int i = 1 ; i <= m2 ; i++) b[i].L = read() , b[i].R = read() ; 
	sort(a + 1 , a + m1 + 1) ; sort(b + 1 , b + m2 + 1) ;
	Work1() ; Work2() ; Build(1 , 1 , n) ; 
	for(int i = 1 ; i <= n ; i++) 
	 Ans = max(Ans , Q1(1 , 1 , i) + Q2(1 , 1 , n - i)) ; 
	printf("%lld\n" , Ans) ; 
	fclose(stdin) ; fclose(stdout) ; 
	return 0 ; 
}
