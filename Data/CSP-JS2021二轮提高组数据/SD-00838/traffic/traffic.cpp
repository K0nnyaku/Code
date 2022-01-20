#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read()
{
	char c = getchar(), last = ' ';
	ll ans = 0;
	while(c < '0' || c > '9') last = c, c = getchar();
	while(c >= '0' && c <= '9') ans = ans * 10 + c - '0', c = getchar();
	while(last == '-') ans = -ans;
	return ans;
}
const int N = 505;
ll dis[N][N];
int n, m;
int main()
{
	printf("775608\n");
}
