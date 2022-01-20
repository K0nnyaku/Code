#include<bits/stdc++.h>
using namespace std;
namespace _xzy
{
	typedef long long ll;
	inline int read()
	{
		ll sm=0,flag=1;
		char ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')flag=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){sm=(sm<<1)+(sm<<3)+(ch^48);ch=getchar();}
		return sm*flag;
	}
	const ll N=1e5+2;
	ll t,n,flag;
	ll a[10*N],b[10*N];
	char way[10*N];
	int judge()
	{
		for(ll i=1;i<=n;++i)
		if(b[i]!=b[2*n+1-i])return 0;
		return 1;
	}
	void search(ll head,ll tail,ll top)
	{
		if(top>=2*n&&judge()&&flag==0)
		{
			for(ll i=1;i<=top;++i)
			cout<<way[i];
			cout<<endl;flag=1;return;
		}
		if(head>tail)return; 
		if(flag)return;
		top++;b[top]=a[head];way[top]='L';
		search(head+1,tail,top);
		b[top]=0;top--;
		top++;b[top]=a[tail];way[top]='R';
		search(head,tail-1,top);
		b[--top]=0;top--;
	}
	void My_main()
	{
		t=read();
		while(t--)
		{
			flag=0;
			n=read();
			for(ll i=1;i<=n*2;++i)
			a[i]=read();
			if(n<=20)
			{
				search(1,2*n,0);
				if(flag==0)
				cout<<"-1"<<endl;	
			}
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	_xzy::My_main();
	return 0;
}
