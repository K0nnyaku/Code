#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>
#define ll long long
#define ull unsigned long long
using namespace std;
template<class T> void read(T &x){
	x=0;int w=0;char g=getchar();
	while(!isdigit(g)){w |=(g=='-');g=getchar();}
	while(isdigit(g)){x=(x<<3)+(x<<1)+(g xor 48);g=getchar();}
	x=w ?-x : x;
	return ;
}
const int maxn=5e4+5;
const long long mod=1e9+7;
int n;
long long ans;
long long a[maxn];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int num=a[i] ^ a[j];
			num=num%mod;
			ans+=num*num%mod;
			ans%=mod;
		}
	printf("%lld",(ans+mod)%mod);
	return 0;
}
