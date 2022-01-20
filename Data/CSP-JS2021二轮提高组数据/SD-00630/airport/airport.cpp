#include<bits/stdc++.h>

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

const int N=4e5+5;
int n,m1,m2,l1[N],r1[N],l2[N],r2[N],b[N],id[N],sm1[N],sm2[N],m,ans;

set<int> can;
vector<int> ad[N],dl[N];

signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;++i)
	{
		l1[i]=read();b[++m]=l1[i];
		r1[i]=read();b[++m]=r1[i];
	}
	for(int i=1;i<=m2;++i)
	{
		l2[i]=read();b[++m]=l2[i];
		r2[i]=read();b[++m]=r2[i];
	}
	sort(b+1,b+1+m);
	m=unique(b+1,b+1+m)-b-1;
	for(int i=1;i<=n;++i)
		can.insert(i);
	for(int i=1;i<=m1;++i)
	{
		l1[i]=lower_bound(b+1,b+1+m,l1[i])-b;
		r1[i]=lower_bound(b+1,b+1+m,r1[i])-b;
		ad[l1[i]].push_back(i);
		dl[r1[i]+1].push_back(i);
	}
	for(int i=1;i<=m+1;++i)
	{
		for(int j=0;j<dl[i].size();++j)
			if(id[dl[i][j]])
			{
				can.insert(id[dl[i][j]]);
				id[dl[i][j]]=0;
			}
		for(int j=0;j<ad[i].size();++j)
			if(!can.empty())
			{
				int tmp=*(can.begin());
				id[ad[i][j]]=tmp;
				can.erase(tmp);sm1[tmp]++;
			}
		ad[i].clear();dl[i].clear();
	}
	for(int i=1;i<=m2;++i)
	{
		l2[i]=lower_bound(b+1,b+1+m,l2[i])-b;
		r2[i]=lower_bound(b+1,b+1+m,r2[i])-b;
		ad[l2[i]].push_back(i);
		dl[r2[i]+1].push_back(i);
	}
	for(int i=1;i<=m+1;++i)
	{
		for(int j=0;j<dl[i].size();++j)
			if(id[dl[i][j]])
			{
				can.insert(id[dl[i][j]]);
				id[dl[i][j]]=0;
			}
		for(int j=0;j<ad[i].size();++j)
			if(!can.empty())
			{
				int tmp=*(can.begin());
				id[ad[i][j]]=tmp;
				can.erase(tmp);sm2[tmp]++;
			}
		ad[i].clear();dl[i].clear();
	}
	for(int i=1;i<=n;++i)
		sm1[i]+=sm1[i-1];
	for(int i=1;i<=n;++i)
		sm2[i]+=sm2[i-1];
	for(int i=0;i<=n;++i)
		ans=max(ans,sm1[i]+sm2[n-i]);
	printf("%d\n",ans);
	return 0;
}
