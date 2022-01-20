#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 11;
struct CH{
	int bg, ed;
}a[N];
struct AM{
	int bg, ed;
}b[N];
int n, m_1, m_2, ans = 0;
int cmp1(CH x, CH y){
	return x.bg < y.bg;
}
int cmp2(AM x, AM y){
	return x.bg < y.bg;
}
void dfs(int x, int y){
	int tmp = 0;
	priority_queue<int> q;
	for(int i = 1; i <= x; ++i) q.push(-a[i].ed), tmp++;
	int p = x + 1;
	while(p <= m_1){
		if(x == 0)  break;
		int now = abs(q.top());
		if(a[p].bg >= now){
			q.pop();
			q.push(-a[p].ed);
			tmp++;
		}
		p++;
	} 
	priority_queue<int> qb;
	for(int i = 1; i <= y; ++i) qb.push(-b[i].ed), tmp ++;
	p = y + 1;
	while(p <= m_2){
		if(y == 0) break;
		int nowb = abs(qb.top());
		if(b[p].bg >= nowb){
			qb.pop();
			qb.push(-b[p].ed);
			tmp++;
		}
		p++;
	}
	ans = max(ans, tmp);
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m_1, &m_2);
	for(int i = 1; i <= m_1; ++i)
		scanf("%d %d", &a[i].bg, &a[i].ed);
	for(int i = 1; i <= m_2; ++i)
		scanf("%d %d", &b[i].bg, &b[i].ed);
	sort(a + 1, a + 1 + m_1, cmp1);
	sort(b + 1, b + 1 + m_2, cmp2);
	for(int i = 0; i <= n; ++i)
		dfs(i, n - i);
	cout << ans; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

