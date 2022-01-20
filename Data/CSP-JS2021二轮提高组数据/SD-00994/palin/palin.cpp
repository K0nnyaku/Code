#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=5*1e5+5;
int T,n,a[maxn*2],pos[maxn][2],f[maxn*2];
bool flag=0;
inline bool check()
{
	deque<int> q;
	for(int i=1;i<=2*n;++i)
	{
		if(f[i]<0)q.push_back(f[i]);
	}
	int last=min(q.front(),q.back());
	if(q.front()<q.back())q.pop_front();
	else q.pop_back();
	while(!q.empty())
	{
		int h=q.front(),b=q.back();
		if(h<b)
		{
			if(h-1!=last)return false;
			last=h;
			q.pop_front();
		}
		else
		{
			if(b-1!=last)return false;
			last=b;
			q.pop_back();
		}
	}
	return true;
}
inline void print(int head,int tail)
{
	if(head==tail)
	{
		printf("L\n");
		return;
	}
	if(f[head]<f[tail])
	{
		if(f[head]*f[tail]>0)printf("L"),print(head+1,tail);
		else printf("R"),print(head,tail-1);
	}
	else
	{
		if(f[head]*f[tail]>0)printf("R"),print(head,tail-1);
		else printf("L"),print(head+1,tail);
	}
}
inline void dfs(int head,int tail,int cnt)
{
	if(head+n-1==tail)
	{
		if(check())
		{
			print(1,2*n);
			flag=1;
			return;
		}
	}
	
	int cur=0,ath=0;
	
	if(f[head]==0)
	{
		cur=head,ath=pos[a[head]][0]==head?pos[a[head]][1]:pos[a[head]][0];
		f[cur]=cnt;f[ath]=-cnt;
		dfs(head+1,tail,cnt+1);
		f[cur]=f[ath]=0;
	}
	
	if(flag)return;
	
	if(f[tail]==0)
	{
		cur=tail,ath=pos[a[tail]][0]==tail?pos[a[tail]][1]:pos[a[tail]][0];
		f[cur]=cnt;f[ath]=-cnt;
		dfs(head,tail-1,cnt+1);
		f[cur]=f[ath]=0;
	}
	
	if(flag)return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		flag=0;
		memset(f,0,sizeof(f));
		memset(pos,0,sizeof(pos));
		
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)
		{
			scanf("%d",&a[i]);
			if(pos[a[i]][0]==0)pos[a[i]][0]=i;
			else pos[a[i]][1]=i;
		}
		dfs(1,2*n,1);
		if(flag==0)printf("-1\n");
	}
	return 0;
}
