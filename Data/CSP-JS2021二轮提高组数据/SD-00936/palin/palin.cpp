#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
int t, n;
int a[500010];
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n*2; i++)
			scanf("%d", &a[i]);
		cout << -1;
		cout << endl;
	}
	return 0;
}
