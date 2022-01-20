#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair 
using namespace std;
const int N = 1e5 + 5;
int n, x, y, ans;
int a[N], aa[N], b[N], bb[N];
struct node{
	int a, b;
}m1[N], m2[N];
inline int cmp(node a, node b){
	return a.a < b.a;
}
inline void work(int l1, int l2){
	int res = 0, siz;
	priority_queue <int> q1, q2; 
	for (int i = 1; i <= x; ++i){
		while (! q1.empty()){
			int a = - q1.top();
			if (a < m1[i].a) q1.pop();
			else break;
		}
		siz = q1.size();
		if (siz < l1){
			q1.push(- m1[i].b);
			res ++;
		}
	}
	for (int i = 1; i <= y; ++i){
		while (! q2.empty()){
			int a = -q2.top();
			if (a < m2[i].a) q2.pop();
			else break;
		}
		siz = q2.size();
		if (siz < l2){
			q2.push(- m2[i].b);
			res ++;
		}
	}
	ans = max(ans, res);
}

int main(){
	freopen ("airport.in", "r", stdin);
	freopen ("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &x, &y);
	for (int i = 1; i <= x; ++i){
		scanf("%d%d", &m1[i].a, &m1[i].b);
	}
	sort(m1 + 1, m1 + x +1, cmp);
	for (int i = 1; i <= y; ++i){
		scanf("%d%d", &m2[i].a, &m2[i].b);
	}
	sort(m2 + 1, m2 + y + 1, cmp);
	for (int i = 0; i <= n; ++i){
		work(i, n - i);
	}
	printf("%d\n", ans);
	return 0;
} 
