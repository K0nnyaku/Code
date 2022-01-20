#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	char c=getchar();
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return s;
}
int n,m,Ma,Mb;
struct sP{
	int l,r;
	bool kind;
}a[200007];
bool cmp2(sP x,sP y)
{
	return x.l<y.l;
}
priority_queue<pair<int,int> > q[2];
set <int> s[2];
int js[2][200007];
int sum[2][200007];
int wz[200007];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),Ma=read(),Mb=read();
	m=Ma+Mb;
	for(int i=1;i<=Ma;++i)
	a[i].l=read(),a[i].r=read(),a[i].kind=0;
	for(int i=1;i<=Mb;++i)
	a[i+Ma].l=read(),a[i+Ma].r=read(),a[i+Ma].kind=1;
	sort(a+1,a+m+1,cmp2);
	for(int i=1;i<=Ma;++i)
	s[0].insert(i);
	for(int i=1;i<=Mb;++i)
	s[1].insert(i);
	for(int i=1;i<=m;++i)
	{
		int l=a[i].l,r=a[i].r;
		bool kind=a[i].kind;
		if(!q[0].empty())
		{
			pair<int,int> kk=q[0].top();
			int fad=-kk.first,u=kk.second;
			while(fad<l)
			{
				s[a[u].kind].insert(wz[u]);
				q[0].pop();
				if(q[0].empty())
				break;
				kk=q[0].top();
				fad=-kk.first,u=kk.second;
			}
		}
		if(!q[1].empty())
		{
			pair<int,int> kk=q[1].top();
			int fad=-kk.first,u=kk.second;
			while(fad<l)
			{
				s[a[u].kind].insert(wz[u]);
				q[1].pop();
				if(q[1].empty())
				break;
				kk=q[1].top();
				fad=-kk.first,u=kk.second;
			}
		}
	//	cout<<l<<" "<<r<<" "<<kind<<" "<<(*s[kind].begin())<<endl;
		wz[i]=(*s[kind].begin());
		++js[kind][wz[i]];
		s[kind].erase(wz[i]);
		q[kind].push(make_pair(-r,i));
	}
	for(int j=0;j<2;++j)
	{
		for(int i=1;i<=n;++i)
		sum[j][i]=sum[j][i-1]+js[j][i];
	}
	int ans=0;
	for(int i=0;i<=n;++i)
	ans=max(ans,sum[0][i]+sum[1][n-i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
