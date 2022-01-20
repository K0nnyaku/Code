#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAXN 505

ll rll();
ull rull();

//ull dp[MAXN][MAXN][MAXN];
ull n,k;
char str[MAXN];
ull ans=0;

#define ifis(a,x) (((a)==(x))?(1):(0))
/* 
void s( ull nn, char ch, ull kk, ull ll, ull rr) {
	#define snp1 str[nn+1]
	if( kk > k) return;
	if( rr > ll) return;
	if( nn >= n) {
		
	}
	
	if( str[nn+1] == '?') {
		s( nn+1, '(', kk, ll+1);
		s( nn+1, ')', kk, ll);
		s( nn+1, '*', kk+1, ll);
	}else {
		s( nn+1, snp1, kk+ifis(snp1,'*'),ll+ifis(snp1,'('), rr+ifis(snp1, ')'));
	}
}
*/ 
int main( int argc, char** argv) {
	//freopen( "a.in", "r", stdin);
	//freopen( "a.out", "w", stdout);
	n=rull();k=rull();
	scanf( "%s", str);
	if( str[0] == '?') {
		//s( 0, '(', 0, 1);
		//s( 0, '*', 1, 0);
	}else {
		//s( 0, str[0], ifis(str[0],'*'), ifis(str[0],'('));
	}
	return 0;
}

ll rll() {
	ll a=0;char c;bool minus = false;
	c = getchar();
	while( (c < '0' || c > '9') && c != '-') {
		c = getchar();
	}
	if( c == '-') {
		minus = true;
		c = getchar();
	}
	while( c >= '0' && c <= '9') {
		a = a * 10 + (c - '0');
		c = getchar();
	}
	if( minus) a *= -1;
	return a;
}

ull rull() {
	ull a=0;char c;
	c = getchar();
	while( c < '0' || c > '9') {
		c = getchar();
	}
	while( c >= '0' && c <= '9') {
		a = a*10 + (c- '0');
		c = getchar();
	}
	return a;
}

