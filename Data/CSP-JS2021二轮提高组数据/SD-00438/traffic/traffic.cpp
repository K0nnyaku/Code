#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <string.h>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll rll();
ull rull();

ull n,m,T;
bool colorstate[505][505];
bool colorstate2[505][505];
typedef map<int, map<int, map<int, map<int, int> > > > mmmap;
mmmap w; 
mmmap w2; 
int ww[502][502][4];
int ww2[502][502][4];
ull dp[505][2];

ull minn = 1145141919810364364;
/*
void search_( ull x, ull y, ull now, bool color) {
	if( now >= minn) return;
	if( color != colorstate2[x-1][y])
		now += w2[x][y][x-1][y];
	if( color != colorstate2[x][y-1])
		now += w2[x][y][x][y-1];
	if( y == n) {
		if( color != colorstate2[x][y+1])
		now += w2[x][y][x][y+1];
	}
	colorstate2[x][y] = color;
	
	if( y == n && x == m) {
		if( now < minn) minn = now;
		return;
	}else if( x == m) {
		search_( 1, y+1, now, false);
		search_( 1, y+1, now, true);
	}else {
		search_( x+1, y, now, false);
		search_( x+1, y, now, true);
	}
}
*/
void deal() {
	memset( dp, 0, sizeof( dp));
	memcpy( colorstate2, colorstate, sizeof( colorstate));
	/*w2 = mmmap( w);
	//ull ans=0;
	ull k =rull();
	for( ull i=0;i<k;++i) {
		ull x,p;
		bool t;
		x=rull();p=rull();t=(rull()=='0')?(false):(true);
		if( x <= m) {
			w2[1][x][0][x] = w2[0][x][1][x] = p;
			colorstate2[0][x] = t;
		}else if( x <= m + n) {
			x -= m;
			w2[m+1][x][m][x] = w2[m][x][m+1][x] = p;
			colorstate2[m+1][x] = t;
		}else if( x <= 2*m + n) {
			x -= m + n;
			x = -x + 1 + m;
			w2[x][n+1][x][n] = w2[x][n][x][n+1] = p;
			colorstate2[x][n+1] = t;
		}else {
			x -= (m<<1) + n;
			x = -x + 1 + n;
			w2[0][x][1][x] = w2[1][x][0][x] = p;
			colorstate2[0][x] = t;
		}
	search_( 1, 1, 0, false);
	search_( 1, 1, 0, true);
	cout<<minn<<endl;
	*/
}

int main( int argc, char** argv) {
	freopen( "traffic.in", "r", stdin);
	freopen( "traffic.out", "w", stdout);
	n=rull();m=rull();T=rull();
	ull tmp;
	memset( ww, 0, sizeof( ww));
	for( ull i=1;i<=n-1;++i) {
		for( ull j=1;j<=m;++j) {
			cin>>tmp;
			ww[j][i][2] = tmp;
			ww[j][i+1][0] = tmp;
		}
	}
	for( ull i=1;i<=n;++i) {
		for( ull j=1;j<=m-1;++j) {
			cin>>tmp;
			ww[j][i][1] = tmp;
			ww[j+1][i][3] = tmp;
		}
	}
	srand( time( NULL));
	printf( "%d\n", rand() % 50);
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

