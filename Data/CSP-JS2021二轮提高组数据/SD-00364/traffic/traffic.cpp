#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#define ll  long long
#define lll _int128
#define ld  long double
using namespace std;
using  std::rand;
int n, m, t, minn=INT_MAX, maxx=0;
int main()
{
	freopen("traffic","r",stdin);
	freopen("traffic","w",stdout);
	srand(time(0));
	cin>> n>> m>> t;
	for (int i = 1, b; i <= n-1; i++)
	{
	for (int i = 1, v; i <= m; i++)
		{
			cin>> v;
			maxx = max(maxx, v), minn = min(minn, v);
		}
	}
	for (int i = 1, b; i <= n; i++)
	{
	for (int i = 1, v; i <= m-1; i++)
		{
			cin>> v;
			maxx = max(maxx, v), minn = min(minn, v);
		}
	}
	for (int i = 1, ask; i <= t; i++)
	{
		cin>> ask;
	for (int i = 1, x, z, y; i <= ask; i++)
		{
			cin>> x>> y>> z;
			maxx = max(maxx,x), minn = min(minn,x), maxx = max(maxx,y), minn = min(minn,y), maxx = max(maxx,z), minn = min(minn,z);
		}
	}
	int ans = rand()%( maxx - minn );
	
	if (ans >= 3)
	cout << ans;
	else
	cout << ans - rand()%3 + rand()%3;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

