#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

typedef pair<int,int> pii;
const int N=1e5+10;
pii In[N],Out[N];
queue<pii> Inq,Outq;

bool cmp(pii a,pii b){ return a.first<b.first; }

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,ans=0; 
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i) scanf("%d%d",&In[i].first,&In[i].second);
	for(int i=1;i<=m2;++i) scanf("%d%d",&Out[i].first,&Out[i].second);
		
	sort(In+1,In+m1+1,cmp);
	sort(Out+1,Out+m2+1,cmp);
		
	for(int in=0,out;in<=n;++in)
	{
		out=n-in;
		int tmp1=in,tmp2=out,cnt1=0,cnt2=0;
		for(int j=1;j<=m1;++j)
		{
			if(tmp1){ --tmp1,++cnt1,Inq.push(In[j]); continue; }
			if(!Inq.empty())
			{
//				cerr<<Inq.front().first<<" "<<Inq.front().second<<" "<<In[j].first<<" "<<In[j].second<<endl; 
				if(Inq.front().second>In[j].first) continue;
				else 
				{
					do{ Inq.pop(),++tmp1; }
						while(!Inq.empty()&&Inq.front().second<=In[j].first); 	
					Inq.push(In[j]),--tmp1,++cnt1;
				}	
			} 
		}
		for(int j=1;j<=m2;++j)
		{
			if(tmp2){ --tmp2,++cnt2,Outq.push(Out[j]); continue; }
			if(!Outq.empty())
			{
//				cerr<<Outq.front().first<<" "<<Outq.front().second<<" "<<Out[j].first<<" "<<Out[j].second<<endl; 
				if(Outq.front().second>Out[j].first) continue;
				else 
				{
					do{ Outq.pop(),++tmp2; }
						while(!Outq.empty()&&Outq.front().second<=Out[j].first); 	
					Outq.push(Out[j]),--tmp2,++cnt2;	
				}
			}
		}
//		cerr<<cnt1<<" "<<cnt2<<endl;
		ans=max(ans,cnt1+cnt2);
		while(!Inq.empty()) Inq.pop();
		while(!Outq.empty()) Outq.pop();
	}
	printf("%d\n",ans);
	return 0;
} 
