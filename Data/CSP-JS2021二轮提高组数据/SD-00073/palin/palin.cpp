#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
inline ll read(){
	ll x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0', c = getchar();}
	return x * f;
}
void SETTING(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
}
int n,a[N],b[N];
bool check(int x){
	int l = 1, r = n, cnt = 0;
	for(int i = n; i ; i --){
		if(!(x & (1 << (i - 1))))b[++cnt] = a[l ++];
		else b[++cnt] = a[r --];
	}
	for(int i = 1; i <= (n >> 1); i ++){
		if(b[i] != b[n - i + 1])return false;
	}
	return true;
}
void solve(){
	n = (read() << 1);
	for(int i = 1; i <= n; i ++){
		a[i] = read();
	}
	for(int i = 0; i < (1 << n); i ++){
		if(check(i)){
			for(int j = n; j ; j --){
				if(!(i & (1 << (j - 1))))printf("L");
				else printf("R");
			}
			puts("");
			return;
		}
	}
	puts("-1");
}
int main(){
	SETTING();
	int T = read();
	while(T--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

