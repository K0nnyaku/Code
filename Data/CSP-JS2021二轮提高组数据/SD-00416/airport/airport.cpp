#include<cstdio>
#include<cstring>
#include<algorithm>
#define R register 
#define ll long long
#define N 100010

using namespace std;

inline ll read()
{
	R ll f = 1, x = 0;
	R char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

ll n, m1, m2, cnt1, cnt2, sum, a1[N], a2[N];

struct vec{
	int a, b, size, fa;//a和b表示序列的最后一个飞机的信息 
	//fa表示开头的到达时间 
}v1[N], v2[N];

struct node{
	ll a, b;
}p1[N], p2[N];//p1表示国内航班，p2表示国际航班 

struct daan{
	int size, a;
}ans1[N], ans2[N];

inline bool cmp(node a, node b)
{
	if(a.a < b.a)
		return a.a < b.a;
	else if(a.a == b.a)
		return a.b < b.b;
	return false;
}

inline bool cmp2(daan a, daan b)
{
	if(a.a < b.a)
		return true;
	else if(a.a == b.a)
		return a.size > b.size;
	return false;
}

int main()
{
	freopen("airport.in","r",stdin);freopen("airport.out","w",stdout);
	n = read(), m1 = read(), m2 = read();
	for(R int i = 1; i <= m1; ++i)
		p1[i].a = read(), p1[i].b = read();
	for(R int i = 1; i <= m2; ++i)
		p2[i].a = read(), p2[i].b = read();
	sort(p1+1, p1+1+m1, cmp);
	sort(p2+1, p2+1+m2, cmp);
	v1[++cnt1].a = p1[1].a, v1[cnt1].b = p1[1].b, v1[cnt1].size++, v1[cnt1].fa = p1[1].a;
	for(R int i = 2; i <= m1; ++i)
	{
		int j = 1;
		while(v1[j].b >= p1[i].a && j <= cnt1)
			++j;
		if(j > cnt1)
			cnt1++;
		if(v1[j].size == 0)
			v1[j].fa = p1[i].a;
		v1[j].a = p1[i].a, v1[j].b = p1[i].b, v1[j].size++;
	}
	v2[++cnt2].a = p2[1].a, v2[cnt2].b = p2[1].b, v2[cnt2].size++, v2[cnt2].fa = p2[1].a;
	for(R int i = 2; i <= m2; ++i)
	{
		int j = 1;
		while(v2[j].b >= p2[i].a && j <= cnt2)
			++j;
		if(j > cnt2)
			cnt2++;
		if(v2[j].size == 0)
			v2[j].fa = p2[i].a;
		v2[j].a = p2[i].a, v2[j].b = p2[i].b, v2[j].size++;
	}
	for(R int i = 1; i <= cnt1; ++i)
	{
		ans1[i].a = v1[i].fa;
		ans1[i].size = v1[i].size;
	}
	for(R int i = 1; i <= cnt2; ++i)
	{
		ans2[i].a = v2[i].fa;
		ans2[i].size = v2[i].size;
	}
	sort(ans1+1, ans1+cnt1+1, cmp2);
	sort(ans2+1, ans2+cnt2+1, cmp2);
	//int d1 = 1, d2 = 1;
	/*for(R int i = 1; i <= n; ++i)
	{
		if(ans1[d1].size > ans2[d2].size)
			sum += ans1[d1].size, d1++;
		else if(ans1[d1].size == ans2[d2].size)
		{
			if(ans1[d1].size < ans2[d2+1].size)
				sum += ans2[d2].size, d2++;
			else if(ans1[d1+1].size > ans2[d2].size)
				sum += ans1[d1].size, d1++;
			else 
				sum += ans1[d1].size, d1++;
		}
		else
			sum += ans2[d2].size, d2++;
	}*/
	a1[0] = a2[0] = 0;
	for(R int i = 1; i <= cnt1; ++i)
		a1[i] = a1[i-1] + ans1[i].size;
	for(R int i = 1; i <= cnt2; ++i)
		a2[i] = a2[i-1] + ans2[i].size;
	for(R int i = 0; i <= n; ++i)
		sum = max(sum, a1[i] + a2[n-i]);
	printf("%lld", sum);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
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

4

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

7
*/


