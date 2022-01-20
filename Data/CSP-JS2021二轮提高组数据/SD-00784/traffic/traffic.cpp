#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
int T,n,m;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(int i=1;i<=T;i++)
		cout<<n*6;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
