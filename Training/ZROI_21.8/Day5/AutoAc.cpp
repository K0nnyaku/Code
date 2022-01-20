#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e6 + 10;
#define TR(x, y) (Tr[(x)].son[(y)])

struct AcTrie {
	int son[27];
	int fail;
	int end;

	static void Add(char *T);
	static void Create();
	static int Query(char *T);

	AcTrie(int _fail = 0, int _end = 0) {
		fail = _fail; end = _end; 
		memset(son, 0, sizeof son);
	}
}Tr[MAXN];

int n, Index = 0;

int main() {
#ifdef LOCAL
	freopen("In.in", "r", stdin);
#endif 

	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		char T[MAXN];
		scanf("%s", T);
		AcTrie::Add(T);
	}
	AcTrie::Create();

	char T[MAXN];
	scanf("%s", T);
	printf("%d", AcTrie::Query(T));

	return 0;
}

void AcTrie::Add(char *T) {
	int len = strlen(T), p = 0;

	for(int i = 0; i < len; i++) {
		int ch = T[i] - 'a';
		if(TR(p, ch)) p = TR(p, ch);
		else TR(p, ch) = ++Index, p = Index;
	}

	Tr[p].end++;
}

void AcTrie::Create() {

	queue<int> q;
	for(int i = 0; i < 26; i++)
		if(TR(0, i)) q.push(TR(0, i));
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < 26; i++) {
			if(TR(u, i)) 
				Tr[TR(u, i)].fail = TR(Tr[u].fail, i),
				q.push(TR(u, i));
			else  TR(u, i) = TR(Tr[u].fail, i);
		}
	}

}

int Query(char *T) {
	int p = 0, res = 0, len = strlen(T);
	for(int i = 0; i < len; i++) {
		p = TR(p, T[i]);
		for(int j = p; j && ~Tr[j].end; j = Tr[j].fail) 
			res += Tr[j].end, Tr[j].end = -1;
	}
	return res;
}


















