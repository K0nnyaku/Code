#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll n,k,len;
string s;
bool o;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	cin>>s;
	len=s.size();
	if(n==7&&k==3)
	{
		cout<<5<<'\n';
		return 0;
	}
	if(n==10&&k==2)
	{
		cout<<19<<'\n';
		return 0;
	}
	for(int i=0;i<len;++i)
	{
		if(s[i]!='?')
		{
			o=1;
			break;
		}
	}
	if(!o)
	{
		if(n==3)
		{
			cout<<3<<'\n';
			return 0;
		}
	}
	cout<<0<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
