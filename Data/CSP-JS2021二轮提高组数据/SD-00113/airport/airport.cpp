#include <bits/stdc++.h>

#define maxn 500005

using std::sort;

int n, m1, m2, l, r, out, ans;

struct T{
	int a, b;
}t1[maxn], t2[maxn];

inline bool cmp(T x, T y){
	return x.a < y.a;
}

template <class I>
class fhq{
	private:
		int Root, cnt;
		struct T{
			int lson, rson, key, rnd, sz;
		}t[maxn];
		
	public:
		inline int make(int k){
			int root = ++cnt;
			t[root].lson = t[root].rson = 0;
			t[root].key = k;
			t[root].sz = 1;
			t[root].rnd = rand();
			return root;
		}
		
		inline void update(int root){
			t[root].sz = t[t[root].lson].sz + t[t[root].rson].sz + 1;
		}
		
		void split(int root, int k, int &x, int &y){
			if(!root){
				x = y = 0;
				return;
			}
			if(t[root].key <= k){
				x = root;
				split(t[root].rson, k, t[root].rson, y);
			}
			else{
				y = root;
				split(t[root].lson, k, x, t[root].lson);
			}
			update(root);
		}
		
		int merge(int x, int y){
			if(!x | !y){
				return x | y;
			}
			if(t[x].rnd > t[y].rnd){
				t[x].rson = merge(t[x].rson, y);
				update(x);
				return x;
			}
			else{
				t[y].lson = merge(x, t[y].lson);
				update(y);
				return y;
			}
		}
		
		inline void add(int k){
			int x, y;
			split(Root, k - 1, x, y);
			Root = merge(merge(x, make(k)), y);
		}
		
		inline int higher(int k){
			int x, y;
			split(Root, k, x, y);
			int ans = t[y].sz;
			Root = merge(x, y);
			return ans;
		}
		
		inline void clr(){
			for(int i = 1; i <= cnt; i++){
				t[i] =(T){0, 0, 0, 0, 0};
			}
			cnt = 0; Root = 0;
			return;
		}
};

fhq < int > fhq1, fhq2;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	fhq1.add(0), fhq2.add(0);
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++){
		scanf("%d %d", &t1[i].a, &t1[i].b);
	}
	for(int i = 1; i <= m2; i++){
		scanf("%d %d", &t2[i].a, &t2[i].b);
	}
	sort(t1 + 1, t1 + m1, cmp);
	sort(t2 + 1, t2 + m2, cmp);
	for(int i = 0; i <= n; i++){
		int cnt = 0;
		for(int j = 1; j <= m1; j++){
			if(fhq1.higher(t1[j].a) >= i){
				++cnt;
				continue;
			}
			fhq1.add(t1[j].b);
		}
		for(int j = 1; j <= m2; j++){
			if(fhq2.higher(t2[j].a) >= n - i){
				++cnt;
				continue;
			}
			fhq2.add(t2[j].b);
		}
		ans = std::max(ans, m1 + m2 - cnt);
		fhq1.clr(), fhq2.clr();
	}
	printf("%d\n", ans);
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16


2 4 6
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

