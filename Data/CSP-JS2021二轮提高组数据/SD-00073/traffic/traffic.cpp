#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0', c = getchar();}
	return x * f;
}
void SETTING(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
}
int main(){
	SETTING();
	int T = read();
	while(T--)printf("%d\n",rand());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

