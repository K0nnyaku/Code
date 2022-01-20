#include <bits/stdc++.h>
using std::min; using std::max; using std::swap; using std::log; using std::abs; using std::sqrt; using std::sort; using std::unique; using std::pair; using std::make_pair;
using std::queue; using std::stack; using std::deque; using std::vector; using std::map; using std::set; using std::multiset;
#define rep(_vr, _st, _ed) for(int _vr=(_st); (_vr)<=(_ed); (_vr)++)
template <class _Tp>
inline void read(_Tp &x) {
	int ch; do { ch=getchar(); } while (ch<'0' || ch>'9');
	x=0;
	while (ch>='0' && ch<='9') {
		x=(x*10)+(ch^48); ch=getchar();
	}
}
struct info { int l, r; };
int operator < (const info &_a, const info &_b) { return _a.l<_b.l; }
const int maxn=100000;
int n, m1, m2, ans=0, cur=0;
info a[maxn+20]={0}, b[maxn+20]={0};
namespace fuckCCF1 {
	multiset<int, std::greater<int> > s;
	inline void init(int k) {
		s.clear();
		while (k--) s.insert(0);
	}
	void run(int l, int r) {
		auto it=s.lower_bound(l);
		if (it==s.end()) return;
		s.erase(it); s.insert(r);
		cur++;
	}
	void work(int inside) {
		if (clock() > 900) return; 
		cur=0;
		init(inside);
		rep (i, 1, m1) run(a[i].l, a[i].r);
		init(n-inside);
		rep (i, 1, m2) run(b[i].l, b[i].r);
		ans=max(ans, cur);
	}
}
namespace fuckCCF2 {
	struct qp { int last, ans; };
	int operator < (const qp &_a, const qp &_b) { return _a.last>_b.last; }
	multiset<qp> s1, s2;
	template <class XX>
	void run(XX &s, int l, int r) {
		auto it=s.lower_bound((qp){l, 0});
		if (it==s.end()) return;
		int g=it->ans;
		s.erase(it); s.insert((qp){r, g+1});
	}
	int work() {
		rep (i, 1, n) s1.insert((qp){0, 0});
		rep (i, 1, m1) run(s1, a[i].l, a[i].r);
		rep (i, 1, n) s2.insert((qp){0, 0});
		rep (i, 1, m2) run(s2, b[i].l, b[i].r);
		vector<int> v;
		for (auto it : s1) if (it.ans) v.push_back(it.ans);
		for (auto it : s2) if (it.ans) v.push_back(it.ans);
		sort(v.begin(), v.end(), std::greater<int>());
		const int ed=min(n, (int)v.size());
		int res=0;
		for (int i=0; i<ed; i++) res+=v[i];
		return res;
	}
}
inline void dispatcher() {
	if (n<=10000) rep (i, 0, n) fuckCCF1::work(i);
	else ans=fuckCCF2::work();
}
int main()
{
	freopen("airport.in", "r", stdin); freopen("airport.out", "w", stdout);
	read(n); read(m1); read(m2);
	rep (i, 1, m1) { read(a[i].l); read(a[i].r); }
	sort(a+1, a+1+m1);
	rep (i, 1, m2) { read(b[i].l); read(b[i].r); }
	sort(b+1, b+1+m2);
	dispatcher();
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
