#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const ll N=100010;
ll head[N],ver[N],nxt[N],tot;
ll edge[N];
ll n,m;
void add(ll x,ll y,ll z)
{
	ver[++tot]=y;
	edge[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}
ll getbit(ll state,ll x)
{
	return (state>>x)&1;
}
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
ll totot(string x)
{
	reverse(x.begin(),x.end());
	ll len=x.length()-1,ans=0;
	for(ll i=0;i<=len;i++)
		if(x[i]=='1') ans+=qpow(2,i);
	return ans;
}
string refresh(string a)
{
	if(a.length()==0) return "0";
	string ans;
	bool flag=false;
	for(ll i=0;i<=a.length()-1;i++)
	{
		if(a[i]=='1') flag=true;
		if(flag==true) ans+=a[i];
	}
	if(ans.length()==0) ans="0";
	return ans;
}
string ttoto(ll x)
{
	string ans;
	ll cnt=31;
	while(cnt>=0)
	{
		ll Pow=qpow(2,cnt);
		if(x-Pow>=0) x-=Pow,ans+='1';
		else ans+='0';
		cnt--;
	}
	return refresh(ans);
	return ans;
}
int main()
{
	clock_t c1=clock();
	freopen("cut.in","r",stdin);
	freopen("cut.out","w",stdout);

	//================================
	cin>>n>>m;
	while(m--)
	{
		ll x,y;string z;
		cin>>x>>y>>z;
		add(x,y,totot(z));
		add(y,x,totot(z));
		ll finalans=0;
		for(ll state=0;state<=(1<<n)-1;state++)
		{
			ll ans=0;
			for(ll i=0;i<n;i++)
			{
				if(getbit(state,i))
				{
					i++;
					for(ll j=head[i];j;j=nxt[j])
					{
						ll z=edge[j];
						ans^=z;
					}
					i--;
				}
			}
			finalans=max(finalans,ans);
		}
		cout<<ttoto(finalans)<<endl;
	}
	
	//================================
	cerr<<endl<<"Time:"<<clock()-c1<<"(ms)";
    return 0;
}
/*
3 6
1 2 1
1 2 1
3 3 111
1 3 101101
1 2 1011
2 3 111011


*/	

