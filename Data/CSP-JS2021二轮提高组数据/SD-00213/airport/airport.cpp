#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
struct seg
{
	int l;
	int r;
	int rnk;
}a[N];
bool cmp(seg a,seg b){return a.l<b.l;}
int n,In,Out,inzhan[N],outzhan[N];
int nxt[N];
bool vis[N],vis2[N];
queue<seg>q;
vector<int>num[N];
set<int>preans;
int main()
{
//	clock_t c1=clock();
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//================================================
	scanf("%d%d%d",&n,&In,&Out);
	for(int i=1;i<=In;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+In+1,cmp);
	for(int i=1;i<=In;i++) a[i].rnk=i;
	
	for(int k=1;k<=In;k++)
	if(nxt[k]==0 || nxt[k]==-1)
	{
		for(int i=k;i<=In;i++)
		{
			bool glag=false;
			if(!q.empty())
			{
				int nowl=q.front().l,nowr=q.front().r;
				if(nowr<=a[i].l && !vis2[q.front().rnk])
					nxt[q.front().rnk]=i,q.pop(),glag=true;
//				else break;
			}
			if(!glag)q.push(a[i]);
		}
		while(!q.empty()) nxt[q.front().rnk]=-1,q.pop();
		memset(vis2,0,sizeof(vis2));
	}
//	for(int i=1;i<=In;i++) printf("%d ",nxt[i]);puts("");
	for(int i=1;i<=In;i++)
	{
		num[i].push_back(i);
		if(!vis[i])
			for(int j=nxt[i];j!=-1;j=nxt[j])
				num[i].push_back(j),vis[j]=1;
//		printf("now i=%d\n",i);
	}
	int cnt=0;
	for(int i=1;i<=In;i++)
	{
		if(!preans.count(i))
		for(vector<int>::iterator it=num[i].begin();it!=num[i].end();it++)
			 preans.insert(*it);
		inzhan[++cnt]=preans.size();
	}
	for(int i=In+1;i<=n;i++) inzhan[i]=inzhan[i-1];
	memset(vis,0,sizeof(vis));
	memset(nxt,0,sizeof(nxt));
	for(int i=1;i<=In;i++) num[i].clear();
	preans.clear();cnt=0;
	//================================================
	for(int i=1;i<=Out;i++) scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+Out+1,cmp);
	for(int i=1;i<=Out;i++) a[i].rnk=i;
	for(int k=1;k<=Out;k++)
	if(nxt[k]==0 || nxt[k]==-1)
	{
		for(int i=k;i<=Out;i++)
		{
			bool hlag=false;
			if(!q.empty())
			{
				int nowl=q.front().l,nowr=q.front().r;
				if(nowr<=a[i].l) nxt[q.front().rnk]=i,q.pop(),hlag=true;
//				else break;
			}
			if(!hlag)q.push(a[i]);
		}
		while(!q.empty()) nxt[q.front().rnk]=-1,q.pop();
	}
//	while(!q.empty()) nxt[q.front().rnk]=-1,q.pop();
//		for(int i=1;i<=Out;i++) printf("%d ",nxt[i]);puts("");

	for(int i=1;i<=Out;i++)
	{
		num[i].push_back(i);
		if(!vis[i])
			for(int j=nxt[i];j!=-1;j=nxt[j])
				num[i].push_back(j),vis[j]=1;
	}
	for(int i=1;i<=Out;i++)
	{
		if(!preans.count(i))
		for(vector<int>::iterator it=num[i].begin();it!=num[i].end();it++)
			 preans.insert(*it);
			 
		outzhan[++cnt]=preans.size();
	}
	
	for(int i=Out+1;i<=n;i++) outzhan[i]=outzhan[i-1];
	int ans=-1;
	for(int i=0;i<=n;i++) ans=max(ans,inzhan[i]+outzhan[n-i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	//================================================
//	cerr<<endl<<"Time:"<<clock()-c1<<"ms"<<endl;
	return 0;
}

