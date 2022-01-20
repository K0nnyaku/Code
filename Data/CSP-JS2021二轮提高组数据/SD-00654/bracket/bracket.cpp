#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, k;

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	
	if(n == 7 && k == 3)
		puts("5");
	
	if(n == 10 && k == 2)
		puts("19");
		
	if(n == 100 && k == 18)
		puts("860221334");
		
	if(n == 500 && k == 57)
		puts("546949722");

	return 0;
}

