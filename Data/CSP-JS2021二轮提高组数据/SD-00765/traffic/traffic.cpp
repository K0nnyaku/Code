#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,T,x,y,sum;cin>>n>>m>>T;
	for(int i=1;i<n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&x);
	for(int i=1;i<=n;i++)
	for(int j=1;j<m;j++)
	scanf("%d",&y);
	fclose(stdin);fclose(stdout);
	return 0;
}
