#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5 * 1e5 + 10; 
int t, cnt;
int ans[N];

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while(t --)
	{
		int n;
		int a[N];
		memset(a, 0, sizeof(a));
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++){
			scanf("%d", &a[i]);
		}
		
		cout << -1 << endl;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

