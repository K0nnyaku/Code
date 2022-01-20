#include<iostream>
#include<cstdio>
using namespace std;
int b[100001],n,m1,m2;
struct plane
{
	int a;
	int l;
};
plane f1[100001],f2[100001],tmp;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int ch,us,ans[100003];
	int y,w;
    cin>>n>>m1>>m2;
    for(int z=1;z<=m1;z++)
    {
    	cin>>f1[z].a>>f1[z].l;
    }
    for(int z=1;z<=m2;z++)
    {
    	cin>>f2[z].a>>f2[z].l;
    }
    for(int w=m1;w>=2;w--)
	{
		for(int y=2;y<=w;y++)
		{
		
		   if(f1[y-1].a>f1[y].a)
		   {
			 f1[y-1]=tmp;
			 f1[y-1]=f1[y];
			 f1[y]=tmp;
		   }
	    }
	} 
	for(int w=m2;w>=2;w--)
	{
		for(int y=2;y<=w;y++)
		{
		
		   if(f2[y-1].a>f2[y].a)
		   {
			 f2[y-1]=tmp;
			 f2[y-1]=f2[y];
			 f2[y]=tmp;
		   }
	    }
	} 
    us=0;
    int v,x,t,r;
    v=3;
    r=1;
    for(int ch=0;ch<=n;ch++)
    {
    	us=n-ch;
    	if(ch>=1)
    	v=1;
    	for(int k=1;v<=ch;v++)
    	{
    		for(int t=1;t<=m1;t++)
    		{
    			for(int s=1;s<=v;s++)
    			{
    				if(f1[b[s]].l<f1[t].a)
    				{
    					ans[ch+1]++;
    				}
    			}
    		}
    	}
    	if(us>=1)
    	v=1;
    	for(int k=1;v<=us;v++)
    	{
    		for(int t=1;t<=m2;t++)
    		{
    			for(int s=1;s<=v;s++)
    			{
    				if(f2[b[s]].l<f2[t].a)
    				{
    					ans[ch+1]++;
    				
    				}
    			}
    		}
    	}
    }
    int ax;
    for(int ax=0;r<=n+1;r++)
    {
    	if(ans[r]>ax)
    	{
    		ax=ans[r];
    	}
    }
    cout<<ax;
	fclose(stdin);
	fclose(stdout);
	return  0;
}         
