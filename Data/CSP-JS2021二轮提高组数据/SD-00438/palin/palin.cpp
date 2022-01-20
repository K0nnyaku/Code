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

ll rll();
ull rull();

ull n;
ull a[500005];

void s( bool left) {
	
}
void deal() {
	s( true);
	s( false);
}

int main( int argc, char** argv) {
	//freopen( "palin.in", "r", stdin);
	//freopen( "palin.out", "w", stdout);
	ull T;
	T = rull();
	while( T--) {
		n = rull();
		for( ull i=0;i<n*2;++i) {
			a[i] = rull();
		}
		deal();
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

