#include<iostream>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	int a,b,c,ans=0;
	for(int i=1;i<=n-1;i++)for(int f=1;f<=m;f++)scanf("%d",&a),ans+=a;
	for(int i=1;i<=n;i++)for(int f=1;f<=m-1;f++)scanf("%d",&a),ans+=a;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)scanf("%d%d%d",&a,&b,&c);
	printf("%d",ans);
	return 0;
}
