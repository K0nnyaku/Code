#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define EPS 1e-8
#define int long long
#define MAXN 2000000
#define INF 1e13 + 7

using namespace std;

inline int read()
{
	int x = 0, f = 1; char c  = getchar();
	while (c > '9' || c < '0') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') { x = x * 10 + (c ^ 48); c = getchar();}
	return f * x;	   
}

struct node{
	int s, t;
}a[MAXN], b[MAXN];

priority_queue<int> q;

int res, n, m1, m2, num;

inline int coun1(int r)
{
	int NUM = 0;
	while (!q.empty()) q.pop();
	for (int i = 1; i <= m1 ; i++)
	{
		while (!q.empty() && -q.top() <= a[i].s) q.pop();
		if ((int)q.size() < r)
		{
			q.push(-a[i].t);
			NUM++;
		}
	}
	return NUM;
}

inline int coun2(int r)
{
	int NUM = 0;
	while (!q.empty()) q.pop();
	for (int i = 1; i <= m2 ; i++)
	{
		while (!q.empty() && -q.top() <= b[i].s) q.pop();
		if ((int)q.size() < r)
		{
			q.push(-b[i].t);
			NUM++;
		}
	}
	return NUM;
}



inline int check(int R){return coun1(R) + coun2(n - R);}

void moni(int flag)
{
	double T = 1000;
	int Res = res, c = 0;
	while (T >= EPS)
	{
		int Nres = (Res + (int)((rand() * 2 / RAND_MAX) * T)) % n;
		int Nnum = check(Nres), derta = Nnum - num;
		if (Nnum < num && flag)
		{
			c++;
			if (c > 10) return;
		}
		if (Nnum > num)
			Res = Nres, res = Nres, num = Nnum, c = 0;
		else if (exp(-derta / T) < rand() / RAND_MAX)
			Res = Nres;
		T *= 0.96;
	}
}

inline int cmp(node x, node y){	return x.s < y.s;}

inline void step_1()
{
	for (int i = 1; i <= n; i++)
	{
		int Nnum = check(i);
		if (Nnum > num) num = Nnum;		
	}
	cout << num;
	
//	cout << 1 << endl;

}

inline void step_2()
{
	res = n, num = coun1(n);
	moni(0);

	cout << num;
	
//	cout << 2 << endl;

}

inline void step_3()
{
	res = n, num = coun1(n);
	moni(1);

	cout << num;
	
//	cout << 3 << endl;
	

}

signed main()
{

	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	srand(19260817);
	
	n = read(), m1 = read(), m2 = read();
	for (int i = 1; i <= m1; i++)
		a[i].s = read(), a[i].t = read();
	for (int i = 1; i <= m2; i++)
		b[i].s = read(), b[i].t = read();
	
	sort(a + 1, a + m1 + 1, cmp);
	sort(b + 1, b + m2 + 1, cmp);
	
	
	if (n <= 1000) step_1();
	else if (n <= 5000) step_2();
	else step_3();
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*

*/
