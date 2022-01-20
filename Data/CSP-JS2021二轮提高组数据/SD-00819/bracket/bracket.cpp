#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

namespace _yz
{
	typedef long long ll;
	const ll N=500+10;
	ll n,k,snum[N],bnum[N],top,val,ans=0;
	char s[N],tmp[N];
	void dfs(ll step)
	{
		if(step>n)
		{
			top=0;val=0;
			//for(ll i=1;i<=n;i++)
			//	cout<<tmp[i];
			//cout<<endl;
			memset(snum,0,sizeof(snum));
			memset(bnum,0,sizeof(bnum));
			for(ll i=1;i<=n;i++)
			{
				if(tmp[i]=='(')
				{
					top++;
					bnum[top]++;
				}
				else if(tmp[i]=='*')
				{
					snum[top]++;
					while(tmp[i]=='*')
					{
						val++;
						i++;
					}
					i--;
					if(val>k) return;
					val=0;
				}
				else
				{
					//printf("*%lld ()%lld\n",snum[top],bnum[top+1]);
					if(snum[top]>bnum[top+1]&&(bnum[top+1]!=0&&snum[top]!=1)) return;
					snum[top]=bnum[top+1]=0;
					top--;
				}
				if(top<0) return;
			}
			if(top!=0) return;
			if(tmp[1]=='*'||tmp[n]=='*') return;
			ans++;
			return;
		}
		if(s[step]!='?')
		{
			dfs(step+1);
		}
		else
		{
			tmp[step]='(';
			dfs(step+1);
			tmp[step]=')';
			dfs(step+1);
			tmp[step]='*';
			dfs(step+1);
		}
	}
	void main()
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++)
		{
			cin>>s[i];
			tmp[i]=s[i];
		}
		dfs(1);
		cout<<ans<<endl;
		return;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	_yz::main();
	return 0;
}
/*
7 3
(*??*??

5
-----------
10 2
???(*??(?)

19
-----------
18 3
((**()*(*))*)(***)

1
*/
