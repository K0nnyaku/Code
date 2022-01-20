#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#define ll long long
using namespace std;
ll re(){
	ll x=0;int f=1;char t=getchar();
	while(t<'0'||t>'9'){if(t=='-')f=-1;t=getchar();}
	while(t>='0'&&t<='9')x=x*10+t-'0',t=getchar();
	return x*f;
}
int n,k;
char a[510];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=re(),k=re();
	scanf("%s",a+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

