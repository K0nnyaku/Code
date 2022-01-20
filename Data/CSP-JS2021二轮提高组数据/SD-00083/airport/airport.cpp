#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int read()
{
	int res=0,f=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) res*=10,res+=c-'0',c=getchar();
	return res*f;
}
int n,m1,m2,ans1[N],ans2[N];
set <pair<int,int> > q1,q2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1,x,y;i<=m1;i++)
	{
		x=read(),y=read();
		q1.insert(make_pair(x,y));
	}
	for(int i=1;i<=n;i++)
	{
		
		int cnt=0;
		if(!q1.size()) break;
		set <pair<int,int> >::iterator it=q1.begin();cnt++;
		q1.erase(*it);
		while(1)
		{
			//cout<<"opps"<<endl;
			if(!q1.size()) break;
			int jie=(*it).second;
			set <pair<int,int> >::iterator p=q1.lower_bound(make_pair(jie,0));
			if(p==q1.end()) break;
			q1.erase(*p);it=p,cnt++;
		}
		ans1[i]=cnt;
	}
	for(int i=1,x,y;i<=m2;i++)
	{
		x=read(),y=read();
		q2.insert(make_pair(x,y));
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		if(!q2.size()) break;
		set <pair<int,int> >::iterator it=q2.begin();cnt++;
		q2.erase(*it);
		while(1)
		{
			if(!q2.size()) break;
			int jie=(*it).second;
			set <pair<int,int> >::iterator p=q2.lower_bound(make_pair(jie,0));
			if(p==q2.end()) break;
			q2.erase(*p);it=p,cnt++;
		}
		ans2[i]=cnt;
	}
	for(int i=1;i<=n;i++) ans1[i]+=ans1[i-1],ans2[i]+=ans2[i-1];
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,ans1[i]+ans2[n-i]);
	cout<<ans;
}

