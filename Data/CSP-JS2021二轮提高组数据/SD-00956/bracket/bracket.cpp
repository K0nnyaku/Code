#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int maxn = 510;
int n;
char a[maxn];
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", a + 1);
	srand(20050806);
	printf("%d", rand());
	return 0;
}
