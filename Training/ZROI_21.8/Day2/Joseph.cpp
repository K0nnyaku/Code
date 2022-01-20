#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 4e2 + 10;
const int MAXM = 1e3 + 10;

int Kind[MAXN];
int n, m, x;

bool Check();

int main() 
{
	freopen("In.in", "r", stdin);

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= 3 * m + 1; i++) scanf("%d", &x), Kind[x]++;
	for(int i = 1; i <= n; i++) 
		printf("i = %d, kind = %d\n", i, Kind[i]);

	for(int i = 1; i <= n; i++) 
	{
		Kind[i]++;

		if(Check()) 
			printf("%d ", i);

		Kind[i]--;
	}
	

	return 0;
}

bool Check()
{
	int Tk[MAXN]; 
	for(int i = 1; i <= n; i++)
		Tk[i] = Kind[i];	

	for(int i = 1; i <= n-m; i++) 
	{

	}

	return k >= 4;
}















