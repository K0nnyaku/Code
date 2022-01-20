#include <cstdio>
#include <iostream>
#include <algorithm> 
#include <cstring>
#define orz cout << "AK IOI" << "\n"

using namespace std;
const int maxn = 1e5 + 10;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
void print(int X)
{
	if(X < 0) X = ~(X - 1), putchar('-');
	if(X > 9) print(X / 10);
	putchar(X % 10 ^ '0');
	return ;
}
int Max(int a, int b){
	return a > b ? a : b;
}
int Min(int a, int b){
	return a < b ? a : b;
}
int n, m1, m2, ans, pos[maxn];
struct node{
	int s, ed; 
}a1[maxn], a2[maxn];
bool cmp(node a, node b) {return a.s < b.s;}
int work1(int tot)
{
	if(tot == 0) return 0;
	if(tot > m1) return m1;
	memset(pos, 0, sizeof pos);
	int to = 0, cnt = 0, js = 0, now = 1;
	for(int i = 1; i <= m1; i++)
	{
		int flag = js; 
		for(int j = 1; j <= flag; j++)
			if(pos[j] <= a1[i].s) {js--, pos[j] = 0, now = j; break;}
		if(js < tot) cnt++, js++, to = max(to, a1[i].ed), pos[now] = a1[i].ed, now++;
	}
	return cnt;
}
int work2(int tot)
{
	if(tot == 0) return 0;
	if(tot > m2) return m2;
	memset(pos, 0, sizeof pos);
	int to = 0, cnt = 0, js = 0, now = 1;
	for(int i = 1; i <= m2; i++)
	{
		int flag = js; 
		for(int j = 1; j <= flag; j++)
			if(pos[j] <= a2[i].s) {js--, pos[j] = 0; now = j; break;}
		if(js < tot) cnt++, js++, to = max(to, a2[i].ed), pos[now] = a2[i].ed, now++;
	}
	return cnt;
}
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for(int i = 1; i <= m1; i++) a1[i].s = read(), a1[i].ed = read();
	sort(a1 + 1, a1 + m1 + 1, cmp);
	for(int i = 1; i <= m2; i++) a2[i].s = read(), a2[i].ed = read();
	sort(a2 + 1, a2 + m2 + 1, cmp);
	for(int i = 0; i <= n; i++)
	{
		int ans1 = work1(i);
		int ans2 = work2(n - i);
		ans = Max(ans, ans1 + ans2);
	}
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
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
