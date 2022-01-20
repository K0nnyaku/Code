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

const int N = 1e5 + 5;

int n, m1, m2, ans, ans1[N], ans2[N];

struct Node {
  Node *ls, *rs;
  int l, r, v;
  
  inline void Maintain() {
    v = min(ls->v, rs->v);
  }
} SegmentTree[N << 1], *root = SegmentTree, *top = SegmentTree;

inline void Build(Node *&o, int l, int r) {
  o->l = l, o->r = r, o->v = 0;
  if (l == r) return;
  int mid = l + r >> 1;
  o->ls = ++top, o->rs = ++top;
  Build(o->ls, l, mid); Build(o->rs, mid + 1, r);
}

inline void Find1(Node *&o, int x, int k) {
  if (o->l == o->r) {
    ans1[o->l]++;
    o->v = k;
    return;
  }
  if (o->ls->v < x) Find1(o->ls, x, k);
  else if (o->rs->v < x) Find1(o->rs, x, k);
  o->Maintain();
}

inline void Find2(Node *&o, int x, int k) {
  if (o->l == o->r) {
    ans2[o->l]++;
    o->v = k;
    return;
  }
  if (o->ls->v < x) Find2(o->ls, x, k);
  else if (o->rs->v < x) Find2(o->rs, x, k);
  o->Maintain();
}

struct Plane {
  int a, b;
} a1[N], a2[N];

inline bool cmp(Plane a, Plane b) {
  return a.a < b.a;
}

int main() {
  freopen("airport.in", "r", stdin);
  freopen("airport.out", "w", stdout);
  n = read(), m1 = read(), m2 = read();
  Build(root, 1, n);
  for (int i = 1; i <= m1; i++) a1[i].a = read(), a1[i].b = read();
  for (int i = 1; i <= m2; i++) a2[i].a = read(), a2[i].b = read();
  sort(a1 + 1, a1 + m1 + 1, cmp); sort(a2 + 1, a2 + m2 + 1, cmp);
  for (int i = 1; i <= m1; i++) Find1(root, a1[i].a, a1[i].b);
  root = SegmentTree, top = SegmentTree;
  Build(root, 1, n);
  for (int i = 1; i <= m2; i++) Find2(root, a2[i].a, a2[i].b);
  for (int i = 1; i <= n; i++) ans1[i] += ans1[i - 1];
  for (int i = 1; i <= n; i++) ans2[i] += ans2[i - 1];
  for (int i = 0, j = n; i <= n; i++, j--) ans = max(ans, ans1[i] + ans2[j]);
  printf("%d", ans);
  return 0;
}

/*
���������ȷ��, ��ž��Ǹ��������߶�, Ȼ��� n �ֳ�������, �ֱ����������߶����ĵط����߶�����.
Ȼ�����ܹ����µ������߶ε�����.
n <= 1e5
���Ӷȸо��Ǵ���log��, ����������һ��, ��ηֲ���ʹ��һ�������ڶ��Ϸ�.
����һ�����ݷ�Χ, �о���Ҫ��ɢ��, ��Ϊ����ɻ��Ƿֿ���, ���Ի�������. 
�������ǹ�ע��֪ʶ�ɻ�����Թ�ϵ, �������ľ�������. 
��ɢ��֮��, �Ȳ��, Ȼ��ǰ׺��, �������������ÿ��ʱ�̱����ǵĴ���.
Ȼ�����log��ʱ���ڲ�ѯ�����ֵ. 
��������������ô֪����Щ�ɻ����Ϸ���?
������һ���뷨��, O(n) ��ö��һ�����ŵķ���, Ȼ�� log ��ʱ���ѯ�ֱ�Ĺ���. 
����ͳ�������� log ��ʱ�����ҵ�һ��������һ������Ĺ���. 
Ŷ, ͻȻ��������ɻ����ȵ��ȵ�, Ҳ����˵, ���ǲ���̰��, ��������ȵ���ѡ, ѡ��ǰ��.
��ô�ͼ�һЩ��, ����ͼȥ.
�������, �����ǿ���Ԥ�����ÿ�����Ŷ�Ӧ�Ĺ��׵�.
���ǿ�һ����, ά��ÿ�����ŵ����һ�ܷɻ��뿪��ʱ��.
si~, ���̰�ĺ���̫��, ����������յ�, ���Ǹ���ôѡ.
������, ��һ��, ���ֻ��һ���Ļ�, �ǿ϶���һ���ɻ�, �ܽ����.
������ܽ�, ���¿�һ������, �㵽������, Ȼ�����Ǿ���Ҫ���������Ĺ�����.
�������Ĺ���, ��ʵ����һ��, Ҳ���ܽ����, Ŷ, �Ҷ���, ��ʵ������ǰ�Ӿ���.
��ʼд, ˼·��ž���ά��ÿһ����β�Ϸ�������, Ȼ��̰�ĵ���ǰ�Ӿ�����. 
����, д����, ������ nm ��, ������ֻ��Ҫ�Ѳ�ѯ��һ�����ԷŽ�ȥ�������Ż�һ�¾�����. 
Ŷ! �� lower_bound ��, ��ѯС�ڵ��ڵ�ǰֵ�ĵ�һ��, ���ڱ�֤������ͬ, �� lower_bound ��ȫ����. 
����, �������֤����, ʱ���ȥ 1h ��, һ��Ҫ��ס.
������Ҫ�ҵ� < a[i].a �ĵ�һ��, �ֿ�? �����КG! �߶�����? ����Ҳ��! �����߶�����, ��û��д���ֿ�. 
����, д����, ���˽��� 1.5h, ���Ǻô�����. ����һ��. 
*/
