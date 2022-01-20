#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;
const int inf = 0x3f3f3f3f;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	struct Edge
	{
		int next,to,flow;
	}e[MAXM<<1];
	int head[MAXN], etot;
	inline void add_one(int u,int v,int flow)
	{
		e[++etot] = (Edge){ head[u],v,flow};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow)
	{
		add_one(u,v,flow);
		add_one(v,u,0);
	}
	inline void del_edge(int u)
	{
		head[u] = e[head[u]].next;
	}
	
	int n,s,t;
	int dep[MAXN], cur[MAXN];
	inline void init(int _n,int _s,int _t){ n = _n; s = _s; t = _t;}
	inline void clear(void){ memset(head,-1,sizeof(head)); etot = -1;}
	inline bool bfs(void)
	{
		for(int i=1; i<=n; ++i) dep[i] = -1, cur[i] = head[i];
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dep[v] == -1) dep[v] = dep[u] + 1, q.push(v);
			}
		}
		return ~dep[t];
	}
	int dfs(int u,int maxf)
	{
		if(u == t || !maxf) return maxf;
		int res = 0;
		for(int &i=cur[u], f; ~i; i=e[i].next)
			if(e[i].flow && dep[e[i].to] == dep[u] + 1 && (f = dfs(e[i].to, min(maxf, e[i].flow))))
			{
				e[i].flow -= f; e[i^1].flow += f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	
	inline int dinic(void)
	{
		int res = 0;
		while(bfs()) res += dfs(s,inf);
		return res;
	}
	inline void reset(void)
	{
		for(int i=1; i<=etot; i+=2)
			e[i^1].flow += e[i].flow, e[i].flow = 0;
	}
	inline void pop_back(void)
	{
		int u = e[etot].to, v = e[etot-1].to;
		del_edge(u); del_edge(v);
		etot -= 2;
	}
};

Max_Flow<MAXN * MAXN * 4, MAXN * MAXN * 10> mf;

int pi[MAXN][MAXN], po[MAXN][MAXN];

int main(void)
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	
	mf.clear();
	int pcnt = 0, s = ++pcnt, t = ++pcnt;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			pi[i][j] = ++pcnt;
			po[i][j] = pcnt;
		}
	
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int x = read();
			mf.add_edge(pi[i][j], po[i+1][j], x);
			mf.add_edge(pi[i+1][j], po[i][j], x);
		}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
		{
			int x = read();
			mf.add_edge(pi[i][j], po[i][j+1], x);
			mf.add_edge(pi[i][j+1], po[i][j], x);
		}
	mf.init(pcnt, s, t);
	
	static int xs[MAXN * 4], ys[MAXN * 4];
	int cur = 0;
	for(int i=1; i<=m; ++i) ++cur, xs[cur] = 1, ys[cur] = i;
	for(int i=1; i<=n; ++i) ++cur, xs[cur] = i, ys[cur] = m;
	for(int i=m; i>=1; --i) ++cur, xs[cur] = n, ys[cur] = i;
	for(int i=n; i>=1; --i) ++cur, xs[cur] = i, ys[cur] = 1;
	
	while(Q--)
	{
		int k;
		scanf("%d",&k);
		vector<int> pt(k), val(k), clr(k);
		for(int i=0; i<k; ++i) scanf("%d%d%d",&val[i],&pt[i],&clr[i]);
		
		int save = mf.etot;
		for(int i=0; i<k; ++i)
		{
			int id = pt[i];
			int x = xs[id], y = ys[id];
			if(clr[i])
				mf.add_edge(s, pi[x][y], val[i]);
			else
				mf.add_edge(po[x][y], t, val[i]);
		}
		
		printf("%d\n",mf.dinic());
		
		while(mf.etot > save) mf.pop_back();
		mf.reset();
	}
	return 0;
}
