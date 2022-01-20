#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
const int MAXN = 1e5 + 10;
using std::pair;
using std::make_pair;
int n, m1, m2;
int ans = -1;
std::set<int> s;
struct node{
	int s, t;
} p1[MAXN], p2[MAXN];
template <class I> inline void read(I &x){
	x = 0; int f = 1; char ch;
	do { ch = getchar(); if(ch == '-') f = -1; } while(ch < '0' || ch > '9');
	do { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); } while(ch >= '0' && ch <= '9');
	x *= f; return; 
}
inline bool cmp(node a, node b){
	if(a.s == b.s) return a.t < b.t;
	else return a.s < b.s;
}
inline int pos(int u){
	std::set<int>::iterator it;
	int pp = 0;
	if(!s.size()) return 0;
	for(it = s.begin(); it != s.end(); ++it){
		++pp;
		if(*it > u) { --pp; break; }
	}
	return pp;
}
inline int calc(int u){
	int v = n - u;
	int res = 0, c1 = 0, c2 = 0;
	s.clear();
	for(int i = 1; i <= m1; ++i){
		if(i - c1 - pos(p1[i].s) <= u) ++res, s.insert(p1[i].t);
		else ++c1;
//		std::cout << pos(p1[i].s) << '\n';
	}
	s.clear();
	for(int i = 1; i <= m2; ++i){ 
		if(i - c2 - pos(p2[i].s) <= v) ++res, s.insert(p2[i].t);
		else ++c2;
//		std::cout << pos(p2[i].s) << '\n';
	}
	return res;
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n), read(m1), read(m2);
	for(int i = 1; i <= m1; ++i){
		read(p1[i].s), read(p1[i].t);
	}
	for(int i = 1; i <= m2; ++i){
		read(p2[i].s), read(p2[i].t);
	}
	std::sort(p1 + 1, p1 + m1 + 1, cmp);
	std::sort(p2 + 1, p2 + m2 + 1, cmp);
	int l = 0, r = n;
	int mid = (l + r) >> 1;
	while(l <= r){
		int v1 = calc(mid), v2 = calc(mid + 1);
//		std::cout << v1 << ' ' << v2 << '\n';
//		printf("%d %d %d\n", l, r, mid);
		ans = std::max(ans, std::max(v1, v2));
		if(v1 > v2) r = mid - 1;
		else l = mid + 1;
		mid = (l + r) >> 1;
	} 
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
