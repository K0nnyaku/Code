#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 5e2 + 10;
const int MAXM = 1e6 + 10;
int n,m,T,cnt,Sum = 0;
int a[MAXN][MAXN];
int w[MAXN][MAXN];
struct Node {
	int nex_,to_,dis_;
}e[MAXM];
int head[MAXM];
int read()
{
	int s = 0,f = 0;char ch = getchar();
	while(!isdigit(ch)) f |= ch == '-',ch = getchar();
	while(isdigit(ch)) s = (s << 3) + (s << 1) + (ch ^ 48),ch = getchar();
	return f ? -s : s;
}
void add_edge(int From_,int To_,int Dis_)
{
	e[++ cnt].to_ = To_;
	e[cnt].dis_ = Dis_;
	e[cnt].nex_ = head[From_];
	head[From_] = cnt;
}
int Dis(int x,int y)
{
	return x * (n - 1) + y;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n = read(),m = read(),T = read();
	for(int i = 1;i <= n - 1;i ++) {
		for(int j = 1;i <= m;j ++) {
			int val = read();
			add_edge(Dis(i,j),Dis(i + 1,j),val); 
			w[Dis(i,j)][Dis(i + 1,j)] = val;
			Sum += val;
		}
	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= m - 1;j ++) {
			int val = read();
			add_edge(Dis(i,j),Dis(i,j + 1),val);
			w[Dis(i,j)][Dis(i,j + 1)] = val;
			Sum += val;
		}
	}
	while(T --) {
		int K = read();
		for(int i = 1;i <= K;i ++) {
			int val = read(),pos = read(),col = read();
		}
		printf("%d\n",Sum / 2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

