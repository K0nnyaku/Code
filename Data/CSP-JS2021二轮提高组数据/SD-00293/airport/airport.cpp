#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int size = 100015;
int n,m1,m2;
int inb[size],outb[size];
bool pd1[size],pd2[size];
map<int,int> ma,mb;
int main()
{
	freopen("airport.out","w",stdout);
	freopen("airport.in","r",stdin);
	cin >> n >> m1 >> m2;
	int a,b;
	for(int i = 1;i <= m1;i++)
	{
		cin >> a >> b;
		ma.insert({a,b});
	}
	for(int i = 1;i <= m2;i++)
	{
		cin >> a >> b;
		mb.insert({a,b});
	}
	for(int i = 1;i <= n;i++)
	{
		int last = 0;
		inb[i] += inb[i - 1];
		for(map<int,int>::iterator it = ma.begin();it != ma.end();it++)
		{
			a = (*it).first;
			b = (*it).second;
			if(a > last && !pd1[a])
			{
				pd1[a] = 1;
				last = b;
				inb[i]++;
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		int last = 0;
		outb[i] += outb[i - 1];
		for(map<int,int>::iterator it = mb.begin();it != mb.end();it++)
		{
			a = (*it).first;
			b = (*it).second;
			if(a > last && !pd2[a])
			{
				pd2[a] = 1;
				last = b;
				outb[i]++;
			}
		}
	} 
	int ans = 0;
	for(int i = 0;i <= n;i++)
		ans = max(ans,inb[i] + outb[n - i]);
	cout << ans << endl;
	return 0;
}
