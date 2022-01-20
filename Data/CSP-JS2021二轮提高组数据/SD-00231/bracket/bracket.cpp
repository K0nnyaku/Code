#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

const int mod = 1e9 + 7;

using namespace std;

int read(){
	int x = 0,w = 1;char ch = 1;
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch - '0');ch = getchar();}
	return x * w;
}

int n,k;
char c[550];
int cnt;

int ksm(int a,int b){
	int ans = 1;
	while(b){
		if(b & 1) ans = (1ll * ans * a) % mod;
		b >>= 1;
		a  = (1ll * a * a) % mod;
	}
	return ans % mod;
}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read(),k = read();
	scanf("%s",c + 1);
	for(int i = 1;i <= n;i ++){
		if(c[i] == '?') cnt ++;
	}
	cout << ksm(3,cnt) % mod;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
