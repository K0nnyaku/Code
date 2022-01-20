#include<bits/stdc++.h>
#define ll long long
using namespace std;

int T,n,a[500005];
bool is;
deque<int> b;
deque<char> c;

inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar(); }
	while(c>='0'&&c<='9'){ x=(x<<1)+(x<<3)+(c^48); c=getchar(); }
	return x*f;
}

void zhao(int l,int r)
{
//	cout<<l<<" "<<r<<endl;
	if(l==r)
	{
//		for(int i=1;i<=2*n;i++)
//		{
//			cout<<b[i-1];
//		}
//		cout<<endl;
		b.push_back(a[l]);
		c.push_back('L');
		bool iss=false;
		for(int i=1;i<=n;i++)
		{
			if(b[i-1]!=b[2*n-i])
			{
				iss=true;
				break;
			}
		}
		if(!iss)
		{
			is=false;
			for(int i=1;i<=n*2;i++)
			{
				cout<<c[i-1];
			}
			return;
		}
		b.pop_back();
		c.pop_back();
		b.push_back(a[r]);
		c.push_back('R');
		for(int i=1;i<=n;i++)
		{
			if(b[i-1]!=b[2*n-i])
			{
				iss=true;
				break;
			}
		}
		if(!iss)
		{
			is=false;
			for(int i=1;i<=2*n;i++)
			{
				cout<<c[i-1];
			}
			return;
		}
		b.pop_back();
		c.pop_back();
		return ;
	}
	b.push_back(a[l]);
	c.push_back('L');
	zhao(l+1,r);
	if(!is)	return;
	b.pop_back();
	c.pop_back();
	b.push_back(a[r]);
	c.push_back('R');
	zhao(l,r-1);
	if(!is)	return;
	b.pop_back();
	c.pop_back();
}

int main()
{
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		b.clear();
		c.clear();
		is=true;
		for(int i=1;i<=2*n;i++)
		{
			a[i]=read();
		}
		zhao(1,2*n);
		if(is)
		{
			cout<<-1;
		}
		cout<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}


