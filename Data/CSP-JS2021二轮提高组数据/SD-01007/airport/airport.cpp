#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll maxn=100005;

ll n,m1,m2;
ll ans[maxn];

ll read()
{
	ll x=0,f=1; char ch=getchar();
	while(ch>='9'||ch<='0')
		f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

void prinf(ll x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	prinf(x/10);
	putchar(x%10+'0');
}

struct zj_in
{
	ll go1,lea1;
}zj_in[maxn];

struct zj_ou
{
	ll go2,lea2;
}zj_ou[maxn];

//struct bz
//{
//	int l,r;
//}bz[maxn];

ll daan(ll x,ll y)
{
	ll ans1=1,ans2=1;
//	ll zz1=-1,zz2=-1;
ll cnt=0;
bool flag=false;
ll bz[maxn];
//bool cmp(bz & a,bzconst const b)
//{
//	if(>b)
//		return
//}


//	int u=x;
	if(x==0)	return 0;
	x--;
	if(y==1)
	{
		bz[x]=zj_in[1].lea1;
		for(ll i=2;i<=m1;i++)
		{
			if(zj_in[i].go1>bz[x]||x>0)
			{
				ans1++;
				x--;
				if(zj_in[i].go1>bz[x])
					x++;
				bz[x]=zj_in[x].lea1;
//				cout<<i<<": "<<x<<endl;
			}
		}
		return ans1;
	}
	if(y==2)
	{
		bz[x]=zj_ou[1].lea2;
		for(ll i=2;i<=m2;i++)
		{
			if(zj_ou[i].go2>bz[x]||x>0)
			{
				ans2++;
				x--;
				if(zj_ou[i].go2>bz[x])
					x++;
				bz[x]=zj_ou[x].lea2;
//				cout<<i<<": "<<x<<endl;
			}
		}
		return ans2;
}
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
//	for(ll i=1;i<=m1;i++)
//		zj_in[i].go1=read(),zj_in[i].lea1=read();
//	for(ll i=1;i<=m2;i++)
//		zj_ou[i].go2=read(),zj_ou[i].lea2=read();
	for(ll i=1;i<=m1;i++)
	{
		scanf("%d %d",&zj_in[i].go1,&zj_in[i].lea1);
//		if(zj_in[i].go1>zz1)
//		{
//			ans1++;
//			zz1=zj_in[i].lea1;
//		}
	}
	for(ll i=1;i<=m2;i++)
	{
		scanf("%d %d",&zj_ou[i].go2,&zj_ou[i].lea2);
//		if(zj_ou[i].go2>zz2)
//		{
//			ans2++;
//			zz2=zj_ou[i].lea2;
//		}
//		cout<<"fds"<<zj_ou[i].lea2<<endl;
	}
	
	for(ll i=0;i<=n;i++)
	{
		ans[i]=daan(i,1)+daan(n-i,2);
	}
	ll maxx=-1;
	for(ll i=0;i<=n;i++)
	{
		maxx=max(maxx,ans[i]);
	}
		
	prinf(maxx);
	fclose(stdin);	
	fclose(stdout);
	
	return 0;
}
