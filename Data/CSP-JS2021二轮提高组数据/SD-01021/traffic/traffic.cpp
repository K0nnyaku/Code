#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<cstdlib>
#define ri register int
#define ll long long

using namespace std;

template <class T> void read(T&x){
	x = 0;
	int w = 0;
	char g = getchar();
	while(!isdigit(g)){
		w = (g == '-');
		g = getchar();
	}
	while(isdigit(g)){
		x = (x << 3) + (x << 1) + (g xor 48);
		g = getchar();
	}
	x = w?-x:x;
	return;
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	return 0;
}

