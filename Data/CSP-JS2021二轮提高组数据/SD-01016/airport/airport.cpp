#include <map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define M 1010
#define lson rt << 1
#define rson rt << 1 | 1

using namespace std;
int n, m1, m2, ans = -1, cnt, num;
int aa[N << 1], bb[N << 1];
map<int, int> ma;
struct node {
  int l, r;
}guo[N], wai[N];
struct Seg {
  int sum, len, lazy;
}tree[N << 4];

int read() {
	int s = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
	return f ? -s : s;
}

void push_up(int rt) {
  tree[rt].sum = tree[lson].sum + tree[rson].sum;
}

void build(int rt, int l, int r) {
  tree[rt].len = r - l + 1, tree[rt].lazy = tree[rt].sum = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(lson, l, mid), build(rson, mid + 1, r);
  push_up(rt);
}

void push_down(int rt) {
  if (!tree[rt].lazy) return;
  tree[lson].sum += tree[rt].lazy * tree[lson].len;
  tree[rson].sum += tree[rt].lazy * tree[rson].len;
  tree[lson].lazy += tree[rt].lazy;
  tree[rson].lazy += tree[rt].lazy;
  tree[rt].lazy = 0;
}

void change(int rt, int c, int l, int r, int L, int R) {
  if (L <= l && r <= R) {
    tree[rt].lazy += c;
    tree[rt].sum += c * tree[rt].len;
    return;
  }
  push_down(rt);
  int mid = (l + r) >> 1;
  if (L <= mid) change(lson, c, l, mid, L, R);
  if (R > mid) change(rson, c, mid + 1, r, L, R);
  push_up(rt);
}

int query(int rt, int l, int r, int pos) {
  if (l == r) return tree[rt].sum;
  push_down(rt);
  int mid = (l + r) >> 1;
  if (pos <= mid) return query(lson, l, mid, pos);
  else return query(rson, mid + 1, r, pos);
}

bool cmp(node a, node b) {
  if (a.l == b.l) return a.r < b.r;
  else return a.l < b.l;
}

void init() {
  sort(aa + 1, aa + cnt + 1);
  for (int i = 1; i <= cnt; i++)
    if (aa[i] != aa[i - 1]) {
      bb[++num] = aa[i];
      ma[aa[i]] = num;
    }
  for (int i = 1; i <= m1; i++) {
    guo[i].l = ma[guo[i].l];
    guo[i].r = ma[guo[i].r];
  }
  for (int i = 1; i <= m2; i++) {
    wai[i].l = ma[wai[i].l];
    wai[i].r = ma[wai[i].r];
  }
}

int check(int pos) {
  build(1, 1, num);
  int sum = 0;
  for (int i = 1; i <= m1; i++) {
    int x = query(1, 1, num, guo[i].l);
    if (x == pos) continue;
    else sum++, change(1, 1, 1, num, guo[i].l, guo[i].r);
  }
  build(1, 1, num);
  for (int i = 1; i <= m2; i++) {
    int x = query(1, 1, num, wai[i].l);
    if (x == n - pos) continue; 
    else sum++, change(1, 1, 1, num, wai[i].l, wai[i].r);
  }
  return sum;
}

//void sanfen(int l, int r) {
//  int mid = (l + r) >> 1;
//  int Lans = check(l), Rans = check(r), MIDans = check(mid);
//  ans = max(ans, max(Lans, max(Rans, MIDans)));
//  if (l == r) return;
////  sanfen(l, mid), sanfen(mid + 1, r);
//  if (MIDans >= Lans && MIDans >= Rans) {
//    sanfen(l, mid), sanfen(mid + 1, r);
//    return;
//  }
//  if (MIDans >= Lans && MIDans <= Rans) {
//    sanfen(mid + 1, r);
//    return;
//  }
//  if (MIDans < Lans && MIDans >= Rans) {
//    sanfen(l, mid);
//    return;
//  }
//  if (MIDans < Lans - 1 && MIDans < Rans - 1) return;
//  sanfen(l, mid), sanfen(mid + 1, r);
//  return;
//}

int main() {
  freopen("airport.in", "r", stdin);
  freopen("airport.out", "w", stdout);
  n = read(), m1 = read(), m2 = read();
  for (int i = 1; i <= m1; i++) {
    guo[i].l = read(), guo[i].r = read();
    aa[++cnt] = guo[i].l, aa[++cnt] = guo[i].r;
  }
  for (int i = 1; i <= m2; i++) {
    wai[i].l = read(), wai[i].r = read();
    aa[++cnt] = wai[i].l, aa[++cnt] = wai[i].r;
  }
  init();
  sort(guo + 1, guo + m1 + 1, cmp);
  sort(wai + 1, wai + m2 + 1, cmp);
//  sanfen(0, n);
  for (int i = 0; i <= n; i++) 
    ans = max(ans, check(i));
  cout << ans;
  fclose(stdin), fclose(stdout);
  return 0;
}
