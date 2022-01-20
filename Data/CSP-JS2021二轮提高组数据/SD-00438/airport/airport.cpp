#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <string>
#include <set>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll rll();
ull rull();

ull n,m1,m2;
struct plane {
	ull a,b;
};
plane p1[100005];
plane p2[100005];

bool cmp( const plane& a, const plane& b) {
	return a.a < b.a;
}

ull enumit( plane* a, ull num, ull nn) {
	ull time;
	ull left = nn;
	ull ans=0;
	set<ull> ends;
	for( ull i=0;i<num;++i) {
		time = a[i].a;
		while( !ends.empty()) {
			auto it = ends.begin();
			if( *it <= time) {
				ends.erase( it);
				++left;
				//break;
			}else {
				break;
			}
		}
		if( left) {
			++ans;
			ends.insert( a[i].b);
			--left;
		}
	}
	return ans;
}

#define MAX(a,b) ((a>b)?(a):(b))

int main() {
	freopen( "airport.in", "r", stdin);
	freopen( "airport.out", "w", stdout);
	n=rull();m1=rull();m2=rull();
	for( ull i=0;i<m1;++i) {
		ull aa,bb;
		aa=rull();
		bb=rull();
		p1[i].a = aa;p1[i].b = bb;
	}
	
	for( ull i=0;i<m2;++i) {
		ull aa,bb;
		aa=rull();
		bb=rull();
		p2[i].a = aa;p2[i].b = bb;
	}
	sort( p1, p1+m1, cmp);
	sort( p2, p2+m2, cmp);
	
	ull maxans = 0;
	maxans = MAX( maxans, enumit( p1, m1, n));
	//cout<<maxans<<endl;
	maxans = MAX( maxans, enumit( p2, m2, n));
	//cout<<enumit( p2, m2, n)<<endl;
	
	for( ull i=1;i<n;++i) {
		maxans = MAX( maxans, enumit( p1, m1, i) + enumit( p2, m2, n-i));
		//cout<<maxans<<endl;
	}
	cout<<maxans;
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

