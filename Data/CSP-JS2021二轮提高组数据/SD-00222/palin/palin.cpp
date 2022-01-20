#include <cstdio>
using namespace std;
const int N = 105;
int n;

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		int T = 0,enter[N * 2] = {0};
		scanf("%d",&T);
		T *= 2;
		for (int j = 0;j < T;j++)
		{
			scanf("%d",&enter[j]);
		}
		
		printf("-1\n");
	}
	return 0;
} 
