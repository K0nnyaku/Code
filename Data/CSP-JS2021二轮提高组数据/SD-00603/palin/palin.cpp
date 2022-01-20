#include<bits/stdc++.h>
using namespace std;
inline bool cmp(string s)
{
	for(int l=0,r=s.size()-1;l<=r;l++,r--)
	{
		if(s[l]!=s[r])return false;
	}
	return true;
}
inline int read()
{
	int x(0);char c(0);bool flag(0);
	for(;!isdigit(c);c=getchar())if(c=='-')flag=1;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return flag?-x:x;
}
int T,n,x;
namespace Work1
{
	deque<int>q;
	string b;
	string ans;
	string opt;
	inline void init()
	{
		b.clear();
		q.clear();
		ans.clear();
		opt.clear();
		for(int i=1;i<=2*n;i++)
		{
			x=read();
			q.push_back(x);
		}
	}
	void dfs(int step)
	{
		if(step==n*2+1)
		{
			if(!cmp(b))return;
			if(ans>opt||ans.empty())ans=opt;
			return;
		}
		int x=q.front(),y=q.back();
		
		b+=(char(x+'0'));
		q.pop_front();
		opt+="L";
		
		dfs(step+1);
		
		q.push_front(x);
		b.erase(b.end()-1);
		opt.erase(opt.end()-1);
	
		
		b+=(char(y+'0'));
		q.pop_back();
		opt+="R";
		
		dfs(step+1);
		
		q.push_back(y);
		b.erase(b.end()-1);
		opt.erase(opt.end()-1);
	}
	void Solve()
	{
		init();
		dfs(1);
		cout<<(ans==""?"-1":ans)<<endl;
	}
}
//namespace Work2
//{
//	deque<int>q;
//	string b;
//	string ans;
//	string opt;
//	bool used[1000005];
//	inline void init()
//	{
//		b.clear();
//		q.clear();
//		ans.clear();
//		opt.clear();
//		memset(used,0,sizeof used);
//		for(int i=1;i<=2*n;i++)
//		{
//			x=read();
//			q.push_back(x);
//		}
//	}
//	void Solve()
//	{
//		init();
//		int last;
//		for(int l=0,r=n*2-1;l<=r;l++,r--)
//		{
//			if(l==0)
//			{
//				ans+='L';
//				used[q[l]]=1;
//				last=q[l];
//			}
//			else if(i+1<=n)
//			{
//				if()
//			}
//		}
//	}
//}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
//		if(n<=20)
		Work1::Solve();
//		else Work2::Solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
