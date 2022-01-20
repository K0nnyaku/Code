#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#define N 100010
#define WS 110
#define MAXN 9999999
using namespace std;
int n,m,f[WS][WS],vis[WS],ans,cun[WS],cnt;
priority_queue<pair<int,int> > q;
int hea[N],k,dis[N],pd[N],o,qu,cha[N];
struct bian{
	int to,net;
}a[2*N];
char ch;
struct wen{
	int sha,d;
}que[WS];
inline void jia(int k){
	int u=floor(k/2);
	f[k][u]=f[u][k]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	k=u;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
}
inline void add(int u,int v){
	a[++cnt].to=v;
	a[cnt].net=hea[u];
	hea[u]=cnt;
}
int main()
{
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u;
	if(n<=50){
		for(int i=1;i<=m;i++){
			cin>>ch>>u;
			que[i].d=u;
			if(ch=='?')
				que[i].sha=1;
			if(ch=='-')
				que[i].sha=0,vis[u]=1;
		}
		memset(f,0x3f,sizeof(f));
		f[1][1]=0;
		for(int i=2;i<=n;i++){
			f[i][i]=0;
			if(vis[i]) continue;
			u=floor(i/2);
			f[u][i]=f[i][u]=1;
		}
		for(int i=m;i>=1;i--){
			if(que[i].sha==0)
				jia(que[i].d);
			else{
				ans=0;
				for(int j=1;j<=n;j++){
					for(int k=1+j;k<=n;k++){
						if(f[j][k]<=que[i].d) ans++;
					}
				}
				cun[++cnt]=ans;
			}
		}
		for(int i=cnt;i>=1;i--) printf("%d\n",cun[i]);
	}
	else{
		for(int i=2;i<=n;i++){
			u=floor(i/2);
			add(u,i);
			add(i,u);
		}
		for(int i=1;i<=n;i++){
			memset(pd,0,sizeof(pd));
			memset(dis,0x3f,sizeof(dis));
			while(!q.empty()) q.pop();
			q.push(make_pair(0,i));
			dis[i]=0;
			while(!q.empty()){
				o=q.top().second;
				q.pop();
				if(pd[o]) continue;
				pd[o]=1;
				for(int j=hea[o];j;j=a[j].net){
					qu=a[j].to;
					if(pd[qu]) continue;
					if(dis[qu]>dis[o]+1){
						dis[qu]=dis[o]+1;
						q.push(make_pair(-dis[qu],qu));
					}
				}
			}
			for(int j=1;j<=n;j++) cha[dis[j]]++;
		}
		cha[0]=0;
		for(int i=2;i<=n;i++) cha[i]+=cha[i-1];
		for(int i=1;i<=m;i++){
			scanf("%d",&k);
			k=min(k,n);
			printf("%d\n",cha[k]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
