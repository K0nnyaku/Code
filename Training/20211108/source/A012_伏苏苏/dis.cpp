#include <cctype>
#include <cstdio>
#include <iostream>

inline int readInt() {
  int ans = 0, c, f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  do ans = ans * 10 + c - '0';
  while (isdigit(c = getchar()));
  return ans * f;
}

const int N = 1e5+3, M = 1e5+3;

int n, m, ans[M], top, fa[N], log[N], stak1[N], stak2[N], st1, st2;
int szsz[N];
bool cut[N];
char c;

struct Question {
  char c;
  int k;
  Question() {}
} q[M];

int Fint(int k) {
  return fa[k] == k?k:fa[k] = Fint(fa[k]);
}

inline int Lca(int x, int y) {
  if (x > y) std::swap(x , y);
  while (log[y] != log[x]) y >>= 1;
  while (y != x) {
  	y >>= 1;
	x >>= 1;
  }
  return x;
}

inline void Update(int x) {
  for(; x <=n; x += x & -x) ++szsz[x];
}

inline int Query(int x) {
  int sum = 0;
  for(; x; x -= x & -x) sum += szsz[x];
  return sum;
}

int main() {
  freopen("dis.in", "r", stdin);
  freopen("dis.out", "w", stdout);
  n = readInt(), m = readInt();
  for (int i = 1; i <= m; ++i) {
  	std::cin >> q[i].c;
  	q[i].k = readInt();
  	if (q[i].c == '-') cut[q[i].k - 1] = 1;
  }
  log[0] = -1;
  for (int i = 1; i <= n; ++i) log[i] = log[i >> 1] + 1;
  for (int i = 1; i <= n; ++i) fa[i] = i;
  for (int i = 1; i < n; ++i) {
  	if (!cut[i]) fa[Fint(i + 1)] = Fint((i + 1) >> 1);
  }
  for (int i = m; i >= 1; --i) {
  	if (q[i].c == '?') {
  		++top;
  		for (int j = 1; j <= n; ++j) {
  		  for (int h = j + 1; h <= n; ++h) {
  		  	if (Fint(j) == Fint(h) && log[j] + log[h] - (log[Lca(j,h)] << 1) <= q[i].k) {
  		  	++ans[top];
			}
		  }
	    }
	}
	else {
		fa[Fint(q[i].k)] = Fint(q[i].k >> 1);
	}
  }
  for (int i = top; i >= 1; --i) printf("%d\n", ans[i]);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
