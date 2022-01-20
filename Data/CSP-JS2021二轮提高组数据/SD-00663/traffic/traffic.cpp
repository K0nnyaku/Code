#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#define LL long long
#define Re register
const int N=10001;
using namespace std;
int n,m,T;
int a[100000000];
inline int read(){
	Re int x=0,f=1;Re char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	Re int ann=0;
	n=read(),m=read(),T=read();
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j){
			ann+=read();
		}
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<=n;++j){
			ann+=read();
		}
	}
	for(int i=1;i<=T;++i){
		Re int an=ann;
		Re int k=read();
		for(int j=1;j<=k;++j){
			an+=read();
			Re int sks=read();
			sks=read();
		}
		for(int ty=1;ty<=an;++ty) a[ty]=ty;
		random_shuffle(a+1,a+1+an);
		printf("%d",a[2]+10);
	}
	return 0;
}
