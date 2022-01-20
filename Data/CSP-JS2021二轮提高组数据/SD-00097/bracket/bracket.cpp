#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;
const int N = 502;
inline int re()
{
	int x=0,y=1;char c=getchar();
	while(c>'9'||c<'0')
	{if(c=='-') y=-1;c=getchar();}
	while(c>='0'&&c<='9')
	x=x*10+(c^48),c=getchar();
	return x*y;
}
int n,m;
char s[N];
int l=0;
int ans=0;
int k=0;
void d(int i)
{
	if(i>=n){
		
	if(k!=0) return;
//		for(int i=0;i<n;i++)
//		cout<<s[i]<<" ";
//		cout<<endl;
	ans++;return;
	}
	
	if(s[i]=='(')
	{
		int y=l;
		k++;
		l=0;
		i++;
		
		d(i);
		
		i--;
		k--;
		l=y;
		return;
	}
	if(s[i]==')')
	{
		int y=l;
		k--;if(k<0)return;
		l=0;
		i++;
		
		d(i);
		
		i--;
		k++;
		l=y;
		return;
	}
	if(s[i]=='*')
	{
		l++;
		if(l>m)return;
		i++;
		
		d(i);
		
		i--;
		l--;
		return;
	}
	if(s[i]=='?')
	{
		if(k<n-i)
		{
		s[i]='(';
		int y=l;
		k++;
		l=0;
		
		d(++i);
		i--;
		k--;
		l=y;
		}
		
		if(i!=0&&l!=m)
		{
		s[i]='*';
		l++;
		
		d(++i);
		i--;
		l--;
		}
		
		if(k)
		{
		s[i]=')';
		int y=l;
		k--;
		l=0;
		
		d(++i);
		i--;
		k++;
		l=y;
		}
		return;
	}
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=re();m=re();
	cin>>s;
	d(0);
	cout<<ans;
	return 0;
 }
/*
7 3
(*??*??
*/
