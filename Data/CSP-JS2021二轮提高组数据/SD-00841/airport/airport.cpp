#include<bits/stdc++.h>
#define maxn  100005
#define ll long long
using namespace std;
ll n,m1,m2,ans=0,gk1[maxn],gk2[maxn];
struct feiji{
	ll l,r;
};
feiji a[maxn],b[maxn];
ll zuo(ll al,ll bl){
	ll sum=0;
	for(int i=1;i<=m1;i++)
	{
		for(int j=1;j<=al;j++)
		{
			if(gk1[j]<a[i].l )
			{
				gk1[j]=a[i].r ;
				sum++;break;
			}
		}
	}
	//
	for(int i=1;i<=m2;i++)
	{
		for(int j=1;j<=bl;j++)
		{
			if(gk2[j]<b[i].l )
			{
				gk2[j]=b[i].r ;
				sum++;break;
			}
		}
	}
	return sum;
}
int cmp(feiji x,feiji y)
{
	return x.l <y.l ;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
		if(n>=m1+m2){
		cout<<m1+m2;
		return 0;
	}
	for(ll r=1;r<=m1;r++)
	cin>>a[r].l >>a[r].r ;
	for(ll r=1;r<=m2;r++)
	cin>>b[r].l >>b[r].r ;
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	
	for(ll i=0;i<=n;i++)
	{
	memset(gk1,0,sizeof(gk1));memset(gk2,0,sizeof(gk2));
	if(i>m1||n-i>m2)continue;
		ll num=zuo(i,n-i);
		ans=max(num,ans);
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



