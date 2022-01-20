#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
#define ll long long
#define db double
const int N=2e5+10;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
int n,m[2],cnt;
struct node{
	int a,b;
	bool operator <(const node &x) const
	{
		return x.b<b;
	}
}pl[2][N];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int solve(int p,int lim)
{
	int val=0;
	priority_queue<node> q;
	cnt=1;
	q.push(pl[p][1]);
	if(cnt<=lim) val++;
	for(int i=2;i<=m[p];i++)
	{
		node u=q.top();
		if((u.b>=pl[p][i].a&&cnt==lim)||cnt>lim) continue;
		val++;cnt++;
		q.push(pl[p][i]);
		if(cnt>lim) cnt--,q.pop();
	}
	while(!q.empty()) q.pop();
	return val;
}
int ans=-1;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m[0]=read();m[1]=read();
	for(int i=1;i<=m[0];i++)
	{
		pl[0][i].a=read();
		pl[0][i].b=read();
	}
	sort(pl[0]+1,pl[0]+1+m[0],cmp);
	for(int i=1;i<=m[1];i++)
	{
		pl[1][i].a=read();
		pl[1][i].b=read();
	}
	sort(pl[1]+1,pl[1]+1+m[1],cmp);
	//for(int i=1;i<=m[0];i++) cout<<pl[0][i].a<<" "<<pl[0][i].b<<endl; 
	for(int i=0;i<=n;i++)
	{
		int nei=solve(0,i),wai=solve(1,n-i);
		//cout<<i<<" "<<nei<<" "<<wai<<endl;
		ans=max(ans,nei+wai);
	}
		
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 6 5
8 10
12 14
9 15
1 20
21 32
11 33
1 9
4 6
6 7
7 8
11 20
*/
