//biao bai xtt! by szhlg
#include<cstdio>
#include<algorithm>
#include<queue>
#define fr first
#define mp make_pair
#define sed second
using namespace std;
int read()
{
	int x = 0,f = 1; char c = getchar();
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
void chu(int x)
{
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x > 9) chu(x/10);
	putchar(x%10+'0');
}
int n,m,tt,k[2];
const int maxn = 300005;
const int s = 299999,t = 300000;
const int maxm = 505;
int hao[maxm][maxm],xtt[maxm][maxm],tc[maxm][maxm];
struct thy{
	int a,b,c;
}kk[233];
struct stu{
	int to,nxt,w;
}se[2333333];
bool vis[maxn];
int cnt,hd[maxn],dis[maxn];
void jia(int x,int y,int z)
{
	se[++cnt].to = y;
	se[cnt].w = z;
	se[cnt].nxt = hd[x];
	hd[x] = cnt;
}
void qk()
{
	for(int i=1;i<maxn;++i) dis[i] = 1e9,hd[i] = 0,vis[i] = 0;
	cnt = 0;
}
priority_queue<pair<int,int> >q;
void dij()
{
	dis[s] = 0;
	q.push(mp(0,s));
	while(!q.empty())
	{
		int u = q.top().sed;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=hd[u];i;i=se[i].nxt)
		{
			int v = se[i].to;
			if(dis[v] > dis[u] + se[i].w)
			{
				dis[v] = dis[u] + se[i].w;
				q.push(mp(-dis[v],v));
			}
		}
	}
	printf("%d\n",dis[t]);
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n = read(),m = read(),tt = read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			hao[i][j] = (i-1) * n + m;
		}
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=m;++j) 
		{
			xtt[i][j] = read();
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<m;++j)
		{
			tc[i][j] = read();
		}
	}
	while(tt != 0)
	{
		--tt;
		int x = read();
		qk();
		for(int i=1;i<n;++i)
		{
			for(int j=2;j<m;++j) 
			{
				jia(hao[i][j],hao[i][j-1],xtt[i][j]),
				jia(hao[i][j-1],hao[i][j],xtt[i][j]);
			}
		}
		for(int i=2;i<n;++i)
		{
			for(int j=1;j<m;++j)
			{
				jia(hao[i-1][j],hao[i][j],tc[i][j]),
				jia(hao[i][j],hao[i-1][j],tc[i][j]);
			}
		}
		for(int i=1;i<=2;++i) kk[i].a = read(),kk[i].b = read(),kk[i].c = read();//ÊäÈë
		if(kk[1].c == kk[2].c)
		{
			printf("0\n");
			continue;
		}
		if(kk[1].b > kk[2].b ) swap(kk[1],kk[2]);
		int aa = kk[1].b,bb = kk[2].b;
		for(int i=1;i<m;++i)
		{
			if(i < aa) jia(s,hao[1][i],tc[1][i]);
			if(i >= aa && i < bb) jia(hao[1][i],t,tc[1][i]);
			if(i >= bb) jia(s,hao[1][i],tc[1][i]);
			if(m+n+(m-i+1) < aa) jia(s,hao[n-1][i],tc[n][i]);
			if(m+n+(m-i+1) >= aa && m+n+(m-i+1)  < bb) jia(hao[n-1][i],t,tc[n][i]);
			if(m+n+(m-i+1) >= bb) jia(s,hao[n-1][i],tc[n][i]);
		}
		for(int i=1;i<n;++i)
		{
			if(i+m < aa) jia(s,hao[i][m-1],xtt[i][m]);
			if(i+m >= aa && i+m < bb) jia(hao[i][m-1],t,xtt[i][m]);
			if(i+m >= bb) jia(s,hao[i][m-1],xtt[i][m]);
			if(2*m+n+(n-i+1) < aa) jia(s,hao[i][1],xtt[i][1]);
			if(2*m+n+(n-i+1) >= aa && 2*m+n+(n-i+1) < bb) jia(hao[i][1],t,xtt[i][1]);
			if(2*m+n+(n-i+1) >= bb) jia(s,hao[i][1],xtt[i][1]);
		}
		jia(s,t,min(kk[1].a,kk[2].a));
		dij();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

