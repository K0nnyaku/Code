#include<bits/stdc++.h>
#define ll long long 

using namespace std;

const int N = 100;

bool flag=false;
int t,n,l,r;
int ans[N*2],c[N*2],g[N*2];
int a[N*2];

bool che()
{
	for(int i=1;i<=n;i++)
	{
		if(a[l]==g[n-i+1])
		{
			g[n+i]=a[l];
			l++;
			c[n+i]=0;
		}
		else if(a[r]==g[n-i+1])
		{
			g[n+i]=a[r];
			r--;
			c[n+i]=1;
		}
		else return false;
	}
	return true;
}

bool cmp()
{
	for(int i=1;i<=2*n;i++)
	{
		if(ans[i]<c[i])return true;
		if(ans[i]>c[i])return false;
	}
	return true;
}

void geng()
{
	if(flag==false)
	{
		for(int i=1;i<=2*n;i++)
		{
			ans[i]=c[i];
		}
	}
	else 
	{
		if(!cmp())
		{
			    for(int i=1;i<=2*n;i++)
		    {
			    ans[i]=c[i];
		    }
		}
	}
}

void print()
{
	for(int i=1;i<=2*n;i++)
	{
		if(ans[i]==0)cout<<"L";
		else cout<<"R"; 
	}
	cout<<endl;
}

void init()
{
	flag=false;
	memset(ans,0,sizeof(ans));
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	
	while(t--)
	{
		init();
		cin>>n;
		
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<1<<n;i++)
		{
			l=1,r=n+n;
			for(int k=1;k<=n;k++)
			{
			    if(i>>k&1)
				{
					g[k]=a[r];
					r--;
					c[k]=1;
				}
				else 
				{
				    g[k]=a[l];
				    l++;
				    c[k]=0;
				}	
			} 
			if(che())
			{
				geng();
				flag=true;
			}
		}
		if(flag==false)cout<<-1<<endl;
		else print();
	}
	
	
	return 0;
}
