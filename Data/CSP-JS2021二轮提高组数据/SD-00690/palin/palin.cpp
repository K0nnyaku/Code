#include<iostream>
#include<cstdio>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
int t,n;
deque<int> a,b,c;
string ans[2];
inline int read()
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x;
}
inline bool check(int x,bool tag)
{
	ans[0].clear();
	ans[1].clear();
	ans[0].push_back(tag? 'R':'L');
	ans[1].push_back('L');
	a.clear();
	b.clear();
	int pos=-1;
	for(int i=0;i<(int)c.size();++i)
		if(c[i]==x)
		{
			pos=i;
			break;
		}
	for(int i=0;i<pos;++i)
		a.push_back(c[i]);
	for(int i=pos+1;i<(int)c.size();++i)
		b.push_front(c[i]);
	for(int i=1;i<n;++i)
	{
		if(!a.empty())
		{
			if(a.size()>1&&a.front()==a.back())
			{
				ans[0].push_back('L');
				ans[1].push_back('L');
				a.pop_front();
				a.pop_back();
				continue;
			}
			if(!b.empty()&&a.front()==b.back())
			{
				ans[0].push_back('L');
				ans[1].push_back('R');
				a.pop_front();
				b.pop_back();
				continue;
			}
		}
		if(!b.empty())
		{
			if(!a.empty()&&b.front()==a.back())
			{
				ans[0].push_back('R');
				ans[1].push_back('L');
				b.pop_front();
				a.pop_back();
				continue;
			}
			if(b.size()>1&&b.front()==b.back())
			{
				ans[0].push_back('R');
				ans[1].push_back('R');
				b.pop_front();
				b.pop_back();
				continue;
			}
		}
		return 0;
	}
	return 1;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		c.clear();
		for(int i=1;i<=(n<<1);++i)
		{
			int x=read();
			c.push_back(x);
		}
		int tmp=c.front();
		c.pop_front();
		if(check(tmp,0))
		{
			reverse(ans[1].begin(),ans[1].end());
			cout<<ans[0]<<ans[1]<<endl;
			continue;
		}
		c.push_front(tmp);
		tmp=c.back();
		c.pop_back();
		if(check(tmp,1))
		{
			reverse(ans[1].begin(),ans[1].end());
			cout<<ans[0]<<ans[1]<<endl;
			continue;
		}
		puts("-1");
	}
	return 0;
}
