#include<iostream>
#include<cstdio>

using namespace std;

int n,m,T;//500
struct paths{
	int fromx,fromy,tox,toy;
	int weight;
}path[250001],pathb[250001];

int now;

int k,w[51],p[51];bool c[51];

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	if(n<=22&&m<=22)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				now++;
				cin>>path[now].weight;
				path[now].fromx=i;
				path[now].fromy=j;
				path[now].tox=i+1;
				path[now].toy=j;// i*m+j
			}
		}
		for(int i=1;i<=m-1;i++)
		{
			for(int j=1;j<=n;j++)
			{
				now++;
				cin>>path[now].weight;
				path[now].fromx=j;
				path[now].fromy=i;
				path[now].tox=j;
				path[now].toy=i+1;
			}
		}
		for(int ijk=1;ijk<=T;ijk++)
		{
			cin>>k;
			for(int i=1;i<=k;i++)
			{
				cin>>w[0]>>p[0]>>c[0];
				if(p[0]<=m)p[0]=-p[0];
				else if(m+1<=p[0]&&p[0]<=m+n)p[0]=p[0]-m;
				else if(m+n+1<=p[0]&&p[0]<=2*m+n)p[0]=p[0]-2*m-n-1;
				else p[0]=-p[0]+2*m+2*n+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
