#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n,k,a[505];
long long ans;
string s;
bool v[505];
void f(int now,int l,int c,int vn)
{
	if(now==n)
	{
		if(!(l||c))
			ans=(ans+1)%1000000007;
		return ;
	}
	switch(a[now])
	{
		case 1:
			f(now+1,l+1,0,vn+1);
			break;
		case 3:
			if(!l)
				return ;
			v[vn]=false;
			f(now+1,l-1,0,vn-1);
			break;
		case 2:
			if(c+1>k)
				return ;
			if(now)
			{
				if(a[now-1]==1)
					v[vn]=true;
				else
					if(a[now-1]==3)
					{
						if(v[vn])
							return ;
					}
			}
			f(now+1,l,c+1,vn);
			v[vn]=false;
			break;
		case 4:
			if(c+1<=k)
				f(now+1,l,c+1,vn);
			a[now]=1;
			f(now+1,l+1,0,vn+1);
			if(l)
			{
				a[now]=3;
				f(now+1,l-1,0,vn-1);
			}
			a[now]=4;
			break;
	}
	return ;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		switch(s[i])
		{
			case '(':
				a[i]=1;
				break;
			case '*':
				a[i]=2;
				break;
			case ')':
				a[i]=3;
				break;
			case '?':
				a[i]=4;
				break;
		}
	}
	if((a[0]==2)||(a[0]==3))
	{
		cout<<0<<endl;
		return 0;
	}
	a[0]=1;
	f(0,0,0,0);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
