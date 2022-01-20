#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
inline int read()
{
	int num=0,w=1;char ch=getchar();
	while(ch<'0'||'9'<ch) {if(ch=='-') w=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') {num*=10;num+=(ch-'0');ch=getchar();}
	return num*w;
}
int n,m,u;
char ch;
int dis[101][101];
int mapp[101][101];
inline void fl()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=mapp[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j]<=u) ans++;
	printf("%d\n",ans/2);
}
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	memset(mapp,0x3f3f3f,sizeof(mapp));
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++) mapp[i][i/2]=1,mapp[i/2][i]=1;
	while(m--)
	{
		cin>>ch>>u;
		if(ch=='?') fl();
		if(ch=='-') mapp[u][u/2]=0x3f3f3f,mapp[u/2][u]=0x3f3f3f;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
