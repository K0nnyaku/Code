#include<bits/stdc++.h>
#define ri read<int>()
using namespace std;

template <typename T=int>
inline T read()
{
	T x=0,w=1;
	char c=0;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			w=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
template <typename T=int>
inline void write(T x)
{
	if(!x)
		putchar('0');
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	int an[130];
	int tm=0;
	while(x)
	{
		an[tm++]=x%10;
		x/=10;
	}
	while(tm)
	{
		putchar(an[--tm]+'0');
	}
}

typedef pair<int,int> pii;
int n,m1,m2;
const int N=1e5+10;
pii a1[N],a2[N];
long long ans=0;
void check(int n1,int n2)
{
	priority_queue<int,vector<int>,greater<int>> h1;
	priority_queue<int,vector<int>,greater<int>> h2;
	long long num=0,ans1=0,ans2=0;
	for(int i=1; i<=m1; i++)
	{
		int nt=a1[i].first;
		while(!h1.empty())
		{
			if(h1.top()<=nt)
			{
				h1.pop();			
			}
			else
			break;
		}
		if(h1.size()<n1)
		{
			h1.push(a1[i].second);
			ans1++;
		}
	}
	for(int i=1;i<=m2;i++)
	{
		int nt=a2[i].first;
		while(!h2.empty())
		{
			if(h2.top()<=nt)
			{
				h2.pop();			
			}
			else
			break;
		}
		if(h2.size()<n2)
		{
			h2.push(a2[i].second);
			ans2++;
		}
	}
	ans=max(ans,ans1+ans2);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=ri;
	m1=ri;
	m2=ri;
	if(n>=m1+m2)
	{
		cout<<m1+m2;
		return 0;
	}
	for(int i=1; i<=m1; i++)
	{
		a1[i].first=ri;
		a1[i].second=ri;
	}
	for(int i=1; i<=m2; i++)
	{
		a2[i].first=ri;
		a2[i].second=ri;
	}
	sort(a1+1,a1+1+m1);
	sort(a2+1,a2+1+m2);
	if(m2<m1)
	{
		for(int i=max(0,n-m2);i<=n;i++)
		{
			check(i,n-i);
		}
	}
	else
	{
		for(int i=max(0,n-m1);i<=n;i++)
		{
			check(n-i,i);
		}
	}
	cout<<ans;
	return 0;
}
