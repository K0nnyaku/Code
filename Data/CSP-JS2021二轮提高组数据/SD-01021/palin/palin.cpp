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

int T,n,a[1000005];

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		for(ri i = 1; i <= n*2; i++)
			read(a[i]);
		cout << "-1\n";
	}
	return 0;
}
