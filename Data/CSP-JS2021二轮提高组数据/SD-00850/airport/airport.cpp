#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//#include<queue>
//#include<vector>

using namespace std;
const int M=100005;
int a1[M],b1[M],a2[M],b2[M],ans1[M],ans2[M],p[M];
int n,m1,m2,tot1,tot2,maxx;
bool f=0;

struct node
{
	int s,end;
	bool f;
} l[M],w[M];
bool cmp(node a,node b)
{
	return a.s<b.s;
}


int main()
{
	freopen("airport.in","r",stdin);
	freoprn("airport.out","w",stdout);
	
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
	{
		scanf("%d%d",&l[i].s,&l[i].end);
		
	}
	sort(l+1,l+m1+1,cmp);
	
	for(int i=1;i<=m2;++i)
	{
		scanf("%d%d",&w[i].s,&w[i].end);
		
	}
	sort(w+1,w+m2+1,cmp);
	
	int mid,l1,r1,x=1;
	for(int i=1;i<=n;++i)
	{
		ans1[i]+=ans1[i-1]; 
		ans2[i]+=ans2[i-1];
		for(int j=1;j<=m1;++j)
		{
			if(l[j].s>=p[i])
			{
				p[i]=l[j].end;
				//cout<<p[i]<<endl;
				ans1[i]++;
				l[j].f=1;
			}
		}
		//cout<<ans1[i]<<endl;
		x=1;
		for(int j=1;j<=m1;++j)
		{
			
			while(l[j].f==1)
			{
				j++;
			}
			if(j<=m1)
		    	l[x++]=l[j];
		}
		m1=x-1;
		memset(p,0,sizeof(p));
		for(int j=1;j<=m2;++j)
		{
			if(w[j].s>=p[i])
			{
				p[i]=w[j].end;
				//cout<<p[i]<<endl;
				ans2[i]++;
				w[j].f=1;
			}
		}
		//cout<<ans1[i]<<endl;
		x=1;
		for(int j=1;j<=m2;++j)
		{
			
			while(w[j].f==1)
			{
				j++;
			}
			if(j<=m2)
			  w[x++]=w[j];
		}
		m2=x-1;
		memset(p,0,sizeof(p));
		
	}
	
	
	
	for(int i=0;i<=n;++i)
	{
		
		if(ans1[i]+ans2[n-i]>maxx)
		{
			
			maxx=ans1[i]+ans2[n-i];
		}
	}
	printf("%d\n",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
