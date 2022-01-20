//Brute Force for 40pts
//CCF完美的出了4个我不擅长的题 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rp(i, a, b) for(int i = (a); i <= (b); i++)

const int N = 1e5 + 10;
struct fli { int l, r;} cn[N], fo[N];
int n, m1, m2;
int ls[N << 2];

int cmp(fli a, fli b) {
	if(a.l == b.l) return a.r < b.r;
	else return a.l < b.l;
}

int main ()
{
	freopen("airport.in","r",stdin); freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m1 >> m2;
	rp(i, 1, m1) {cin >> cn[i].l >> cn[i].r; ls[i] = cn[i].l; ls[i + m1] = cn[i].r;}
	rp(i, 1, m2) {cin >> fo[i].l >> fo[i].r; ls[i + 2 * m1] = fo[i].l; ls[i + 2 * m1 + m2] = fo[i].r;}
	sort(ls + 1, ls + 2 * m1 + 2 * m2 + 1);
	int len = 2 * m1 + 2 * m2;
//	cerr << len << endl;
	sort(cn + 1, cn + m1 + 1, cmp);
	sort(fo + 1, fo + m2 + 1, cmp);
	rp(i, 1, m1) {
		cn[i].l = lower_bound(ls + 1, ls + len + 1, cn[i].l) - ls;
		cn[i].r = lower_bound(ls + 1, ls + len + 1, cn[i].r) - ls;
//		cerr << cn[i].l << " " << cn[i].r << endl;
	}
	rp(i, 1, m2) {
		fo[i].l = lower_bound(ls + 1, ls + len + 1, fo[i].l) - ls;
		fo[i].r = lower_bound(ls + 1, ls + len + 1, fo[i].r) - ls;
//		cerr << fo[i].l << " " << fo[i].r << endl;
	}
	//离散化一手 ----------------- Debug Finished
	
	int ans = -1;
	rp(i, 0, n) {
		int a = i, b = n - i;
		int ls1 = a, ls2 = b;
		int cnt1 = 0, cnt2 = 0;
		priority_queue<int, vector<int>, greater<int>> q;
		rp(j, 1, m1) {
			while(q.size() && q.top() < cn[j].l) {
				q.pop();
				ls1 += 1;
			}
//			cerr << j << " " << q.size() << endl;
			if(ls1 > 0) q.push(cn[j].r), cnt1++, ls1--; 
		}
//		cerr << endl;
		priority_queue<int, vector<int>, greater<int>> qq;
		rp(j, 1, m2) {
			while(qq.size() && qq.top() < fo[j].l) {
				qq.pop();
				ls2 += 1;
			}
			if(ls2 > 0) qq.push(fo[j].r), cnt2++, ls2--;
		}
		ans = max(cnt1 + cnt2, ans);
//		cerr << cnt1 << endl;
	}
	cout << ans;
	return 0;
}
/* 3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
	
/*2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
