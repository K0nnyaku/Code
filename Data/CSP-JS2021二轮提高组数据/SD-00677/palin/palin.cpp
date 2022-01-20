#include<bits/stdc++.h>
using namespace std;
namespace _wf
{
	typedef long long ll;
	const ll N=500005;
	ll T,n,ans,b[N*2],num[N*2];
	char s[N*2];
	bool flag;
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
	inline void dfs(ll fr,ll to,ll step)
	{
		if(flag) return;
		if(step>(n*2))
		{
			if(flag) return;
			for(int i=1;i<=n;i++) if(b[i]!=b[2*n+1-i]) return;
			flag=1;
			for(int i=1;i<=n*2;i++) cout<<s[i];
			cout<<endl;
			return;
		}
		s[step]='L';
		b[step]=num[fr];
		dfs(fr+1,to,step+1);
		s[step]='R';
		b[step]=num[to];
		dfs(fr,to-1,step+1);
	}
	void mymain()
	{ 
		read(T);
		for(int i=1;i<=T;i++)
		{
			read(n);
			flag=0;
			for(int j=1;j<=n*2;j++) read(num[j]);
			if(n>20)
			{
				for(int j=1;j<=n;j++)
				{
					if(num[i]!=num[2*n+1-i]) flag=1;
				}
				if(flag)
				{
					cout<<"-1"<<endl;
				}
				else 
				{
					for(int j=1;j<=n;j++) cout<<"L";
					cout<<endl;
				}
			}
			else
			{
				ans=0;
				dfs(1,n*2,1);
				if(!flag) cout<<"-1"<<endl;
			}
			
		}
	} 
}
int main()
{
	//freopen("palin.in","r",stdin);
	//freopen("palin.out","w",stdout);
	_wf::mymain();
	return 0;
}

