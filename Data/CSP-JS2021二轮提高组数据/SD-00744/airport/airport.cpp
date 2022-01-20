#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;
#define uLL unsigned long long
#define INF 0x3f3f3f3f
#define LL long long
inline int read(){
	int s=0, f=1; char c=getchar();
	while(!isdigit(c)) { if(c=='-') f=-f; c=getchar(); }
	while(isdigit(c)) s=(s<<3)+(s<<1)+(c^48), c=getchar();
	return s*f;
}
inline void File(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
}
const int M=100000+5;
struct node { int l, r; } a[M], b[M];
int n, an, bn, ans, aloc, bloc, sm[2][M];
vector<pair<int, int> > u, v;
inline bool cmp(node x, node y) { return x.l<y.l; }
int main(){
	File();
	n=read(), an=read(), bn=read();
	for(int i=1; i<=an; ++i) a[i].l=read(), a[i].r=read();
	for(int i=1; i<=bn; ++i) b[i].l=read(), b[i].r=read();
	sort(a+1, a+an+1, cmp);
	sort(b+1, b+bn+1, cmp);
	for(int i=1; i<=an; ++i) u.push_back(make_pair(a[i].l, a[i].r));
	for(int i=1; i<=bn; ++i) v.push_back(make_pair(b[i].l, b[i].r));
	while(!u.empty()){
		vector<pair<int, int> >::iterator bg=u.begin();
		int cnt=1, pos=u[0].second;
		u.erase(bg);
		while(true){
			vector<pair<int, int> >::iterator it=upper_bound(u.begin(), u.end(), make_pair(pos, 0));
			if(it==u.end()) break;
			++cnt;
			pos=(*it).second;
			u.erase(it);
		}
		sm[0][++aloc]=cnt;
	}
	for(int i=1; i<=aloc; ++i) sm[0][i]+=sm[0][i-1];
	while(!v.empty()){
		vector<pair<int, int> >::iterator bg=v.begin();
		int cnt=1, pos=v[0].second;
		v.erase(bg);
		while(true){
			vector<pair<int, int> >::iterator it=upper_bound(v.begin(), v.end(), make_pair(pos, 0));
			if(it==v.end()) break;
			++cnt;
			pos=(*it).second;
			v.erase(it);
		}
		sm[1][++bloc]=cnt;
	}
	for(int i=1; i<=bloc; ++i) sm[1][i]+=sm[1][i-1];
	for(int i=0; i<=n; ++i) ans=max(ans, sm[0][min(i, aloc)]+sm[1][min(n-i, bloc)]);
	printf("%d", ans);
	return 0;
}

