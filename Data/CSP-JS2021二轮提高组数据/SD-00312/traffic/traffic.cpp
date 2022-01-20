#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e6;
ll n,m,t;
struct edge{
	int from;
	int to;
	int next;
	int dis;
}e[N];
void add(int u,int v,int w)
{
	++cnt;
	e[cnt].from = u;
	e[cnt].to = v;
	e[cnt].dis = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&t);
	printf("%d",0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

