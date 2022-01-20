#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=1e6+3;
bool come1[maxn],out1[maxn];
bool come2[maxn],out2[maxn];
inline ll read()
{
	ll f=1,a=0;char ch;
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-1;ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		a=a*10+ch-48; ch=getchar();
	}
	return a*f;
}
struct node{
	int a,b,num;
}gn[maxn],gw[maxn];
bool cmp(node a,node b)
{
	return a.a<b.a;
}
int  n,m1,m2;
int maxgn=0,maxgw=0;
int ans;
priority_queue<int,vector<pair<int,int> >,greater<pair<int,int> > > q;
int check1(int lim)
{
	//if(lim==0) return 0;
	while(!q.empty())	q.pop();
	int cnt1=0;
	q.push(make_pair(gn[1].b,gn[1].num));
	
		for(int i=2;i<=m1;i++)
		{
			if(q.top().first<gn[i].a || cnt1 <= lim)
			{
				q.pop();
				q.push(make_pair(gn[i].b,gn[i].num));
				cnt1++; 
			}
		}
	return cnt1;
}
bool check2(int lim)
{
//	if(lim==0) return 0;
	while(!q.empty())	q.pop();
	int cnt2=0;
	q.push(make_pair(gw[1].b,gw[1].num));
		for(int i=2;i<=m2;i++)
		{
			if(q.top().first < gw[i].a || cnt2 <= lim)
			{	
				q.pop();
			//	cout<<q.top().first<<endl;
				q.push(make_pair(gw[i].b,gw[i].num));
				cnt2++;
			}
		}
		return cnt2;
//	cout<<cnt1<<endl;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout)
	n=read();m1=read();m2=read();

	for(int i=1;i<=m1;i++)
	{
		int a,b;
		a=read(),b=read();
		gn[i].a=a;gn[i].b=b;gn[i].num=i;
	}
	for(int i=1;i<=m2;i++)
	{
		int a,b;
		a=read(),b=read();
		gw[i].a=a;gw[i].b=b;gw[i].num=i;
	}
	sort(gn+1,gn+m1+1,cmp);sort(gw+1,gw+m2+1,cmp);
	int ans=0;
	
	for(int j=0;j<=n;j++)
	{
		int agn=j,agw=n-j;
	//	cout<<agn<<"  "<<agw<<endl;
	//	cout<<check1(0)<<" "<<check2(0)<<endl;
		ans=max(ans,check1(agn)+check2(agw));
	}
	cout<<ans+2<<endl;
	return 0;
}
