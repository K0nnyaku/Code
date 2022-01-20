#include<bits/stdc++.h>
using namespace std;
const int M=5010;
int n,m1,m2;
int ans=0;	
int main()
{
	freopen("airport.in ","r","stdin");
	freopen("airport.out ","w","stdout");
	scanf("%d%d%d",&n,&m1,&m2);	
	int k,l,x,y;	
	for(int k=0;k<n;k++)
	{
		l=n-k;
		}
	int a1[M],b1[M],a2[M],b2[M];
	
	for(int i=0;i<m1;i++)
		{
			scanf("%d%d",&a1[i],&b1[i]);
			for(int i=0;i<k;i++)
					if(a1[i]>=b1[i--])	
						x++;
		}
	for(int i=0;i<m2;i++)
		{
			scanf("%d%d",&a2[i],&b2[i]);
			for(int i=0;i<l;i++)
					if(a2[i]>=b2[i--])	
						y++;
		}
		ans+=x+y;
		ans=max(ans,x+y);
	printf("%d",ans);
	return 0;
}
