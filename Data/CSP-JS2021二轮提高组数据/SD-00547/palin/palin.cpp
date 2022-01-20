#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  return x * f;
}

const int N = 1e6 + 5;

int n, a[N], b[N], num[N], ans[N], ok, l, r;

inline void DFS(int x) {
  if (ok) return;
  if (x > n << 1) {
    ok = 1;
    return;
  }
  int flag = 1;
  ans[x] = 0; //L
  b[x] = a[l++];
  num[b[x]]++;
  if (x <= n) {
    if (num[b[x]] == 2) flag = 0;
  } else {
    if (b[x] != b[2 * n - x + 1]) flag = 0; 
  }
  if (flag) DFS(x + 1);
  if (ok) return;
  l--;
  num[b[x]]--;
  flag = 1;
  ans[x] = 1; //R
  b[x] = a[r--];
  num[b[x]]++;
  if (x <= n) {
    if (num[b[x]] == 2) flag = 0;
  } else {
    if (b[x] != b[2 * n - x + 1]) flag = 0; 
  }
  if (flag) DFS(x + 1);
  if (ok) return;
  r++;
  num[b[x]]--;
}

inline void Solve() {
  memset(num, 0, sizeof(int) * (n + 1));
  n = read(), l = 1, r = n << 1, ok = 0;
  for (int i = 1; i <= n << 1; i++) a[i] = read();
  DFS(1);
  if (!ok) printf("-1");
  else for (int i = 1; i <= n << 1; i++) printf("%c", ans[i] ? 'R' : 'L');
  printf("\n");
}

int main() {
  freopen("palin.in", "r", stdin);
  freopen("palin.out", "w", stdout);
  int T = read();
  while (T--) Solve();
  return 0;
}

/*
�о���һ��̰��, ���ݷ�ΧҲ�Ƚϴ�.
�ϰ취, �ȿ�һ���޽�.
�ȿ������, ���ǿ��Դ��м�����, ��Ϊ����һ����ż��, ��ô�� n ���͵� n + 1 ��һ��������ѡ������ͬ��.
������λ�ù�ϵҪô��һ�γ���Ϊ n + 1 �Ķε���ͷ, Ҫô��һ�˵�����.
�ȴ��������, 40pts ������.
�G? ������һ��, �ǲ���ǰ�����ͺ�����һ�����Ż��ߵ���, ��˼��, ��һ���͵ڶ������������ô����,
�޷Ǿ���ǰ��, ������, ������ͷ, ����������Ӧ��, ��Ҳһ���ǰ��ŵ�, �������ǾͿ����ҵ�ǰ���ͺ�����զѡ.
�������ٸ�����. 
��ʣ��� 1h, �� B ������ͷ��, �� C ��.
�G! �������뷨, ��������˵��, ���ǾͿ��Էֶ�, �ֶ���֮��, ������������.
4 1 2 4 5 3 1 2 3 5
�������ҳ���Ϊ 6 ����ͷһ����, 2 �� 5 ����, �ȿ� 2,
��ô�ͷֳ�������, �ֱ��� 4 1 3 5 �� 4 5 3 1, ������Ҫ��ĳ��˳��ʹ��������һ��.
����, �Ӹ�jianzhi, Ӧ���ܿ첻��, ûʱ����, ������. 
Ư��! ����������! nice! ����ûʱ����, ���һ��ȥ��. 
*/ 
