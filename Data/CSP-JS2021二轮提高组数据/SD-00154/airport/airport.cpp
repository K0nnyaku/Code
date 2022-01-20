#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<bitset>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 100007, inf = 0x3f3f3f3f;

struct Line
{
	int in, out;
}ln1[N], ln2[N];

bool operator < (const Line &a, const Line &b)
{
	return a.in < b.in;
}

int n, m1, m2, last;
int ans1[N], ans2[N];
bool sl[N];

inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
};

void input(void)
{
	n = read();
	m1 = read();
	m2 = read();
	for(int i = 1; i <= m1; ++i)
	{
		ln1[i].in = read();
		ln1[i].out = read();
	}
	for(int i = 1; i <= m2; ++i)
	{
		ln2[i].in = read();
		ln2[i].out = read();
	}
	sort(ln1+1, ln1+1+m1);
	sort(ln2+1, ln2+1+m2);
};

void solve1()
{
	last = 0;
	memset(sl, false, m1+7);
	
	for(int k = 1; k <= n; ++k)
	{
		ans1[k] = ans1[k-1];
		for(int i = 1; i <= m1; ++i)
		{
			if(sl[i])
				continue;
			if(ln1[i].in >= last)
			{
				sl[i] = true;
				++ans1[k];
				last = ln1[i].out;
			}
		}
		last = 0;
	}
	
	memset(sl, false, m2+7);
	last = 0;
	
	for(int k = 1; k <= n; ++k)
	{
		ans2[k] = ans2[k-1];
		for(int i = 1; i <= m2; ++i)
		{
			if(sl[i])
				continue;
			if(ln2[i].in >= last)
			{
				sl[i] = true;
				++ans2[k];
				last = ln2[i].out;
			}
		}
		last = 0;
	}
};

int solve2()
{
	int ans = -inf;
	for(int k = 0; k <= n; ++k)
	{
		ans = max(ans, ans1[k] + ans2[n-k]);
	}
	return ans;
};

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	input();
	solve1();
	printf("%d", solve2());
	return 0;
}
