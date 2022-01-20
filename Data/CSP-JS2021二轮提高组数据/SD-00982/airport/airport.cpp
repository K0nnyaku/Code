#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cctype>
using namespace std;

template <typename T>
inline void read(T &x)
{
	x = 0;
	T f=1;
	char c=getchar();
	for (; !isdigit(c); c=getchar())
	{
		if (c=='-')
			f *= -1;
		}	
	for (; isdigit(c); c=getchar())
		x = (x<<1) + (x<<3) + c - '0';
	x *= f;
}

const int maxn = 1e6;
int n;
struct node{
	int from, to;
};
node m1[maxn],m2[maxn];
int f1[maxn],f2[maxn];
int m1num,m2num;
bool vis1[maxn],vis2[maxn];
int las;
int ans;
int cnts;
int main ()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n),read(m1num),read(m2num);
	for (int i=1; i<=m1num; i++)
	{
		read(m1[i].from),read(m1[i].to);
	}
	for (int i=1; i<=m2num; i++)
	{
		read(m2[i].from),read(m2[i].to);
	}
	cnts = m1num;
	for (int i=1; i<=n; i++)
	{
		f1[i] += f1[i-1];
		las = 0;
		m1num = cnts;
		cnts = 0;
		for (int j=1; j<=m1num; j++)
		{
			if (las < m1[j].from)
			{
				las = m1[j].to;
				f1[i]++;
			}
			else 
				m1[++cnts] = m1[j];
		}
	}
	cnts = m2num;
	for (int i=1; i<=n; i++)
	{
		f2[i] += f2[i-1];
		las = 0;
		m2num = cnts;
		cnts = 0;
		for (int j=1; j<=m2num; j++)
		{
			if (las < m2[j].from)
			{
				las = m2[j].to;
				f2[i]++;
			}
			else 
				m2[++cnts] = m2[j];
				
		}
	}
	
	for (int i=0; i<=n; i++)
		ans = max(ans, f1[i]+f2[n-i]);
	printf("%d",ans);
	return 0;
}














