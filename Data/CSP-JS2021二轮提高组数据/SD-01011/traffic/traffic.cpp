#include<bits/stdc++.h>
#define ll long long
const int maxn = 1e6 + 7;
using std::cin;
using std::cout;
using std::min;
using std::max;
using std::abs;
using std::sort;
using std::unique;
using std::set;
using std::map;
using std::vector;
int read(){
	int x = 0, fl = 1; char ch = getchar();
	while(ch > '9' || ch < '0'){if(ch == '-')fl = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0'){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
	return x * fl;
}
signed main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	puts("wdnmd"); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

