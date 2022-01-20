#include<bits/stdc++.h>
using namespace std;

#define IR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <= k; i++)
#define Ir(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i <  k; i++)
#define SR(i, v, k, ...) for(int i = v, ##__VA_ARGS__; i >= k; i--)
#define Sr(i, v, k, ...) for(int i = v-1, ##__VA_ARGS__; i >= k; i--)
#define ER(i, v, p, q, k, ...) for(int  i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define Er(i, v, p, q, k, ...) for(int &i = p.k[q], v = p.To[i], ##__VA_ARGS__; i; i = p.Nt[i], v = p.To[i])
#define FL(x, y) memset(x, y, sizeof x)
#define FLS(x, y) fill(x.begin(), x.begin() + (y), 0);
#define DG(x) cout << "Debug: " << #x << "=" << x << "\n"
#define ERR   cout << "Fuck\n"

struct FastIN 
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c, l;
		for(c = 0; !isdigit(c); c = getchar() ) l = c;
		for(x = 0; isdigit(c); c = getchar() ) x = x * 10 - '0' + c;
		if(l == '-') x =- x;
		return *this;
	}
}IN;

template<const int V_, typename flow_t, typename cost_t, flow_t FLOW_INF,  cost_t COST_INF, const int SCALE = 16>
class CostScalingMCMF {
public: struct Edge {
		int v; flow_t c; cost_t d; int r;
		Edge() = default;
		Edge(int v, flow_t c, cost_t d, int r) : v(v), c(c), d(d), r(r) {}
	};
	CostScalingMCMF() { negativeSelfLoop = 0; }
	void Clear() {
		negativeSelfLoop = 0;
		Ir(i, 0, V_) g[i].clear();
	}
	void AdI(int s, int e, flow_t cap, cost_t dst) {
		if(s == e) {
			if(dst < 0) negativeSelfLoop += cap * dst;
			return ;
		}
		g[s].emplace_back(e, cap, dst, int(g[e].size())  );
		g[e].emplace_back(s, 0,  -dst, int(g[s].size())-1);
	}
	flow_t getMaxFlow(int V, int S, int T) {
		auto BFS = [&](){
			FLS(level, V);
			queue<int> q; q.push(S); level[S] = 1;
			while(q.size()) {
				int v = q.front(); q.pop();
				for(const auto &e : g[v]) if(!level[e.v] && e.c) q.push(e.v), level[e.v] = level[v] + 1;
			}
			return level[T];
		};
		function<flow_t(int,flow_t)> DFS = [&](int v, flow_t fl) {
			if(v == T || fl == 0) return fl;
			for(int &i=ptr[v]; i < g[v].size(); i++) {
				Edge &e = g[v][i];
				if(level[e.v] != level[v] + 1 || !e.c) continue;
				flow_t delta = DFS(e.v, min(fl, e.c));
				if(delta) {
					e.c -= delta;
					g[e.v][e.r].c += delta;
					return delta;
				}
			}
			return flow_t(0);
		};

		flow_t maxFlow = 0, tmp = 0;
		while(BFS()) {
			FLS(ptr, V);
			while((tmp = DFS(S, FLOW_INF))) maxFlow += tmp;
		}
		return maxFlow;
	}
	pair<flow_t, cost_t> MCMF(int V, int S, int T) {
		flow_t maxFlow = 0;
		cost_t eps = 0, minCost = 0;
		stack<int, vector<int> > stk;
		
		auto c_pi = [&](int v, const Edge &edge) { return edge.d + pi[v] - pi[edge.v]; };
		auto push = [&](int v, Edge &edge, flow_t delta, bool flag) {
			delta = min(delta, edge.c);
			edge.c -= delta; g[edge.v][edge.r].c += delta;
			excess[v] -= delta; excess[edge.v] += delta;
			if(flag && 0 < excess[edge.v] && excess[edge.v] <= delta) stk.push(edge.v);
		};
		auto relabel = [&](int v, cost_t delta) { pi[v] -= delta + eps; };
		auto lookAhead = [&](int v) {
			if(excess[v]) return false;
			cost_t delta = COST_INF;
			for(auto &e : g[v]) {
				if(e.c <= 0) continue;
				cost_t cp = c_pi(v, e);
				if(cp < 0) return false;
				else delta = min(delta, cp);
			}
			relabel(v, delta);
			return true;
		};
		auto discharge = [&](int v) {
			cost_t delta = COST_INF;
			for(int i = 0; i < g[v].size(); i++) {
				Edge &e = g[v][i];
				if(e.c <= 0) continue;
				cost_t cp = c_pi(v, e);
				if(cp < 0) {
					if(lookAhead(e.v)) { i--; continue; }
					push(v, e, excess[v], true);
					if(excess[v] == 0) return ;
				}
				else delta = min(delta, cp);
			}
			relabel(v, delta);
			stk.push(v);
		};

		FLS(pi, V); FLS(excess, V);
		Ir(i, 0, V)
			for(auto &e : g[i]) minCost += e.c * e.d, e.d *= V_+1, eps = max(eps, e.d);

		maxFlow = getMaxFlow(V, S, T);
		while(eps > 1) {
			eps /= SCALE; if(eps < 1) eps = 1;
			stk = stack<int, vector<int> > ();
			Ir(v, 0, V) for(auto &e : g[v]) if(c_pi(v, e) < 0 && e.c > 0) push(v, e, e.c, false);

			Ir(v, 0, V) if(excess[v] > 0) stk.push(v);
			while(stk.size()) {
				int top = stk.top(); stk.pop();
				discharge(top);
			}
		}
		Ir(v, 0, V) for(auto &e : g[v]) e.d /= V_ + 1, minCost -= e.c * e.d;
		minCost = minCost / 2 + negativeSelfLoop;
		return { maxFlow, minCost };
	}
private:
	vector<Edge> g[V_];
	cost_t negativeSelfLoop;
	array<cost_t, V_> pi, excess;

	array<int, V_> level, ptr;
};

const int N_ = 1e3 + 200 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;
CostScalingMCMF<N_, long long, long long, INF, INF> I;

int n, m,  og, sk;

int main() {

#ifdef LOCAL
	freopen("/home/k0nnyaku/Code/Data/In.in", "r", stdin);
	freopen("/home/k0nnyaku/Code/Data/WA.out", "w", stdout);
#endif

	/*
	IN >> n >> m >> og >> sk;

	IR(i, 1, m) {
		int u, v; long long c, w;
		IN >> u >> v >> c >> w;
		I.AdI(u, v, c, w);
	}

	pair<long long, long long> ans = I.MCMF(n+1000, og, sk);

	cout << ans.first << " " << ans.second;
	*/

	IN >> n >> m >> og >> sk;
	IR(i, 1, m) {
		int u, v; long long c; 
		IN >> u >> v >> c;
		I.AdI(--u, --v, c, 0);
	}

	pair<long long, long long> ans = I.MCMF(n, --og, --sk);

	cout << ans.first;


	return 0;
}













