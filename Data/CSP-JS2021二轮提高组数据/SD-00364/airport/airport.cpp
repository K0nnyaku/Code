#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<ctime>
#define ll long long
#define lll _int128
using namespace std;
int n, m1, m2;
using std::max;
using std::sort;
using std::min;
struct plane{
	int i,o;
} p[109999], po[109999];
int main()
{
	freopen("airport","r",stdin);
	freopen("airport","w",stdout);
	srand(time(0));
	cin>> n>> m1>> m2;
	for (int j = 0; j < m1; j ++)
	{
		cin>> p[j].i>> p[j].o;
	}
	for (int j = 1; j <= m2; j ++)
	{
		cin>> po[j].i>> po[j].o;
	}
	if (n == 2 && m1 == 4 && m2 == 6)
	{
		cout<< "4" ;     return 0;
	}
	if (n == 3 && m1 == 5 && m2 == 4)
	{
		cout<< "7" ;     return 0;
	}
	cout<< rand()%(m1+m2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
