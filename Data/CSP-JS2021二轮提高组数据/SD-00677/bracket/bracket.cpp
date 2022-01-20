#include<bits/stdc++.h>
using namespace std;
namespace _wf
{
	typedef long long ll;
	const ll N=505;
	bool v[N];
	ll n,k,ans;
	string s;
	char c[N];
	inline void read(ll &x)
	{
		x=0;ll f=1;
		char ch=getchar();
		while(!isdigit(ch))
		{
			if(ch=='-') f=-1;
			ch=getchar();
		}
		while(isdigit(ch))
		{
			x=(x<<1)+(x<<3)+(ch^48);
			ch=getchar();
		}
		x=x*f;
	}
	inline void dfs(ll now,ll left,ll row,ll step)
	{
		//if(f[][]) return;
		//f[] =1;
		//if(left>n-now+1) return;//
		if(now>=n+1)
		{
			
			if(left!=0) 
			{
				return;
			}
			ans++;
			return;
		}
		if(s[now]!='?')
		{
			if(s[now]=='(') 
			{
				c[now]='(';
				dfs(now+1,left+1,0,step+1);
			}
			if(s[now]==')')
			{
				c[now]=')';
				v[step]=0;
				dfs(now+1,left-1,0,step-1);
			}
			if(s[now]=='*')
			{
				if(row>=k) return;
				if(v[step]&&row==0) return;//
				v[step]=1;
				c[now]='*';
				dfs(now+1,left,row+1,step);
			}
			return;
		}
		c[now]=')';
		v[step]=0;
		dfs(now+1,left-1,0,step-1);
		
		c[now]='(';
		dfs(now+1,left+1,0,step+1);
		
		if(row>=k) return;
		if(v[step]&&row==0) return;//
		v[step]=1;
		c[now]='*';
		dfs(now+1,left,row+1,step);
	}
	void work1()
	{
		//v[0]=1;///***
		dfs(1,0,0,0);
	}
	void mymain()
	{ 
		read(n),read(k);
		cin>>s;
		s="%"+s;
		work1();
		cout<<ans;
		//else work2();
	} 
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	_wf::mymain();
	return 0;
}

