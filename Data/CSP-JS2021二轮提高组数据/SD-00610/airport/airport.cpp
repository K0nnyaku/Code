#include<vector>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#define qr read()
#define in(x) x=read()
#define mp make_pair
#define nc getchar
#define int ll
#define y0 ccf
#define y1 moe
#define ps wxj
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=' ';
	int f=1;
	ll x=0;
	for(;!isdigit(ch);ch=nc())if(ch=='-')f*=-1;
	for(;isdigit(ch);ch=nc())x=x*10+ch-'0';
	return f*x;
}
struct node
{
	int l,r,id;
	bool operator < (const node& bb)const{return l<bb.l;}
}e1[1000010],e2[1000010];
set<node>s;
int v[1000010],b[1000010],c[1000010],s1[1000010],s2[1000010];
bool cmp(node e1,node e2)
{
	return e1.l<e2.l;
}
signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=qr,m1=qr,m2=qr;
	for(int i=1;i<=m1;i++)in(e1[i].l),in(e1[i].r),b[2*i-1]=e1[i].l,b[2*i]=e1[i].r,e1[i].id=i;
	for(int i=1;i<=m2;i++)in(e2[i].l),in(e2[i].r),c[2*i-1]=e2[i].l,c[2*i]=e2[i].r,e2[i].id=i;
//	sort(e1+1,e1+1+m1,cmp);
//	sort(e2+1,e2+1+m2,cmp);
	sort(b+1,b+1+2*m1);
	sort(c+1,c+1+2*m2);
	int now1=unique(b+1,b+1+2*m1)-b-1,now2=unique(c+1,c+1+2*m2)-c-1;
	for(int i=1;i<=m1;i++)
	{
		e1[i].l=lower_bound(b+1,b+1+now1,e1[i].l)-b;
		e1[i].r=lower_bound(b+1,b+1+now1,e1[i].r)-b;
		s.insert(e1[i]);
	}
	int cnt=0;
	while(!s.empty())
	{
		cnt++;
		node now=*s.begin();
		while(1)
		{
			v[now.id]=cnt;
			s.erase(now);
			if(s.lower_bound((node){now.r,0,0})==s.end())break;
			now=*s.lower_bound((node){now.r,0,0});
		}
	}
	for(int i=1;i<=m1;i++)s1[v[i]]++;
	for(int i=1;i<=n;i++)s1[i]+=s1[i-1];
	for(int i=1;i<=m2;i++)
	{
		e2[i].l=lower_bound(c+1,c+1+now2,e2[i].l)-c;
		e2[i].r=lower_bound(c+1,c+1+now2,e2[i].r)-c;
		s.insert(e2[i]);
	}
	cnt=0;
	while(!s.empty())
	{
		cnt++;
		node now=*s.begin();
	//	cout<<now.id<<'\n';
		while(1)
		{
			v[now.id]=cnt;
			s.erase(now);
			if(s.lower_bound((node){now.r,0,0})==s.end())break;
			now=*s.lower_bound((node){now.r,0,0});
		}
	}
	for(int i=1;i<=m2;i++)s2[v[i]]++;
	for(int i=1;i<=n;i++)s2[i]+=s2[i-1];
//	for(int i=0;i<=n;i++)cout<<i<<":"<<s1[i]<<'\n';
//	for(int i=0;i<=n;i++)cout<<i<<":"<<s2[i]<<'\n';
	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,s1[i]+s2[n-i]);
	cout<<ans;
	return 0;
}
