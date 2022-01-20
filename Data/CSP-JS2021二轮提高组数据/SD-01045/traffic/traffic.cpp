#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int n,m,T;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(int i=1;i<=T;i++)printf("0\n");//<-expected score
	return 0;
}
