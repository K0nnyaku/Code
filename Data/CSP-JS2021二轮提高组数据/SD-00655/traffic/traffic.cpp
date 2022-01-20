#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)

template <typename T>
T read(T &a)
{
	T res = 0, sign = 1;
	char c;
	while((c = getchar()) < '0' || c > '9') if(c == '-') sign = -1;
	while(c <= '9' && c >= '0') res = res * 10 + c - '0', c = getchar();
	a = res * sign;
	return a;
}

int n, m, t;

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
