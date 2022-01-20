#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct node
{
	int u,v;
};
bool cmp(node x,node y)
{
	return x.u<y.u;
}
struct nn
{
	int d,x;
};
nn fin;
int maxn=-1;
int flag;
node a[100010],b[100010];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i].u>>a[i].v;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>b[i].u>>b[i].v;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);  
	for(int i=0;i<=n;i++)
	{
	    int x=i;
	    int cnt1=0,cnt2=0;
	    fin.d=1919810;
	    for(int j=1;j<=m1;j++)
	    {
	    	if(fin.d<a[j].u&&x<i)
	    	{
	    		x++;
	    		if(fin.x<a[j].u)
	    		{
	    			x++;
	    			fin.x=fin.d=a[j].v;
				}
	    		if(fin.x>a[j].v)
	    		{
	    			fin.d=a[j].v;
	    			//flag=1;
				}
				else if(fin.x<=a[j].v)
				{
					fin.d=fin.x;
					fin.x=a[j].v;
					//flag=1;
				}
			}//cout<<i<<" "<<x<<" "<<"jntm"<<" "<<j<<endl;
	    	if(!x)
	    	{
	    		continue;
			}
			x--;
			cnt1++;
			//cout<<">"<<cnt1<<endl;
			if(fin.d==1919810)
			{
				fin.d=fin.x=a[j].v;
			}
			if(fin.d!=1919810&&fin.d>=a[j].u)
			{
				//fin.d=fin.x;
				fin.x=min(fin.x,a[j].v);
			}
			if(fin.d!=1919810&&fin.d>=a[j].u&&fin.x<=a[j].v)
			{
				fin.x=a[j].v;
			}
			flag=0;
//			cout<<fin.d<<" "<<fin.x<<"______"<<endl;
//			if(fin.d==1919810)
//			{
//				fin.d=fin.x=a[j].v;
//			}	
		}
		int y=n-i;
		fin.d=1919810;
		for(int w=1;w<=m2;w++)
		{
			if(fin.d<b[w].u&&y<n-i)
			{
				y++;
				if(fin.x<b[w].u)
				{
					x++;
					fin.x=fin.d=b[w].v;
				}
				if(fin.x>b[w].v)
				{
					fin.d=b[w].v;
					//flag=1;
				}
				else
				{
					fin.d=fin.x;
					fin.x=b[w].v;
					//flag=1;
				}
			}
			if(!y)
			{
				continue;
			}
			y--;
			cnt2++;
			if(fin.d==1919810)
			{
				fin.d=fin.x=b[w].v;
			}
			if(fin.d!=1919810&&fin.d>=b[w].u)
			{
				fin.x=min(fin.x,b[w].v);
			}
			if(fin.d!=1919810&&fin.d>=b[w].u&&fin.x<=b[w].v)
			{
				fin.x=b[w].v;
			}
//			flag=0;
//			if(fin.d==1919810);
//			{
//				fin.d=fin.x=b[j].v;
//			}
		}
		maxn=max(maxn,cnt1+cnt2);
	}
    cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
