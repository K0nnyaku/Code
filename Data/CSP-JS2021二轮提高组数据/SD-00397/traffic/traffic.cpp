#include<cmath>
#include<cctype>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define I inline
#define fi first
#define se second

using std::pair;
using std::vector;
using std::set;
using std::map;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int,int> pii;

template<class T>I void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) { x=x*10+c-'0'; c=getchar(); } x*=f;
}

void File() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
}

int main() {

}

