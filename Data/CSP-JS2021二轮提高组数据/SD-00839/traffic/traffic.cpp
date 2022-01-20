#include<cstdio>
#include<iostream>
using namespace std;
int n,m,T;
int t;
inline int read()
{
	int s=0;bool w=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') w=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48); ch=getchar();}
	return w ? ~s+1 : s;
}
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			t=read();
		}
	}
	for(int i=1;i<=m-1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t=read();
		}
	}
	for(int i=1;i<=700;i++) printf("/kk");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


