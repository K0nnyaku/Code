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
const int maxn=2e5+5;
int n; 
int a[maxn],b[maxn],c[maxn];
int main(){
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	read(n);
	for(int i=0;i<n;i++)
		read(a[i]);
	for(int i=0;i<n;i++)
		read(b[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i]=max(c[i],a[j]+b[(i-j+n)%n]);
	for(int i=0;i<n;i++)
		printf("%d ",c[i]);
	return 0;
}
