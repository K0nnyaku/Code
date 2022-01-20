#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;
//

const int MAXN = 1e3 + 10;
const int MAXM = 1e6 + 10;
const int MAXL = 1e5 + 10;

struct Edge { 
	int to, next; 
	Edge(int _to = 0, int _next = 0) {to = _to, next = _next;}
}E[MAXM << 2];
int Head[MAXN << 1], idx;
void Add(int pre, int _to) { 
	E[++idx] = Edge( _to, Head[pre] ); Head[pre] = idx; }

unordered_map<string, int> Mp;
vector<int> Pre[MAXN];
int n, cnt;
bool Vis[MAXN], Vis2[MAXN];
bool flag, tag;

bool Check(int x);
void Wk(int now, int last);

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif
	IN >> n;
	IOR(i, 0, n) {
		string S, T;
		cin >> S;
		flag = 0;

		if(Mp[S]) {
			printf("greska\n");
			flag = 1;
		}
		Mp[S] = ++cnt;

		while(cin >> T && T[0] != ';') {
			if(T[0] == ':') continue;

			if(!Mp[T] && !flag) {
				printf("greska\n");
				flag = 1;
			}
			if(!flag) {
				Add(Mp[T], cnt);
				Pre[cnt].push_back(Mp[T]);
			}
		}

		if(!flag && Check(cnt)) printf("ok\n");
		else {
			if(!flag)
				printf("greska\n");
			Head[cnt] = 0;
			Mp[S] = 0;
		}

	}

	return 0;
} /**/

bool Check(int x) {
	memset(Vis, 0, sizeof Vis);	
	memset(Vis2, 0, sizeof Vis2);

	IOR(i, 0, Pre[x].size()) {
		tag = 0;
		if(!Vis[Pre[x][i]]) {
			Vis2[Pre[x][i]] = 1;

			Wk(Pre[x][i], -1);
			if(tag) 
				return false;
		}
	}

	return true;
}

void Wk(int now, int last) {
	if(Vis[now]) { tag = 1; return ; }

	Vis[now] = 1;
	for(int i = 0; i < Pre[now].size(); i++) {
		if(Pre[now][i] == last || Vis2[Pre[now][i]]) continue;
		Wk(Pre[now][i], now);
	}
}