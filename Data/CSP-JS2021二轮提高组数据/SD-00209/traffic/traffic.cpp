#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
__int128 a;
std::vector<__int128> b; 
template <class I> inline void read(I &x){
	x = 0; int f = 1; char ch;
	do { ch = getchar(); if(ch == '-') f = -1; } while(ch < '0' || ch > '9');
	do { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); } while(ch >= '0' && ch <= '9');
	x *= f; return; 
} 

int main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	auto it = b.begin();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
