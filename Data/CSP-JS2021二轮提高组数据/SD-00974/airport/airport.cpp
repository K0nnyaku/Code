#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N=100005;
int m,m1,m2;
struct F
{
	int a;
	int b;
	bool in;
};
F n[N],g[N];
int ton[N],tog[N];
bool to1[N],to2[N];
bool cmp(F ba,F aa)
{
	return aa.a >= ba.a;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		int x,y;
		cin>>x>>y;
		n[i].a=x;
		n[i].b=y;
	}
    for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin>>x>>y;
		g[i].a=x;
		g[i].b=y;
	}
	sort(n+1,n+m1+1,cmp);
	sort(g+1,g+m2+1,cmp);
	int mx=0;
    for(int t=0;t<=m;t++)//nation
    {
    	int c1=0,c2=0;
    	int la1=1,la1g=1;
    	int nn=0,gg=0;
    	for(int i=1;i<=n[m1].a;i++)
    	{
            if(to1[i])
			{
            	nn--;
            	to1[i]=0;
			}
			if(n[la1].a==i)
			{   
			    if(nn>=t)
			    {
			    	la1++;
				}
				else
				{
				to1[n[la1].b]=1;
			    c1++;
				la1++;
				nn++;	
				}
			}	
		}
		for(int i=1;i<=g[m2].a;i++)
    	{
    		if(to2[i])
    		{
    			gg--;
    			to2[i]=0;
			}
			if(g[la1g].a==i)
			{
                if(gg>=m-t)
                {
                	la1g++;
				}
			    else
			    {
				to2[g[la1g].b]=1;
				c2++;
				la1g++;
				gg++;
				}
			}	
		}
        mx=max(c1+c2,mx);
	}
	cout<<mx;
	return 0;
}
//\\18:30×¼Ê±ÍËÒÛ//\\


