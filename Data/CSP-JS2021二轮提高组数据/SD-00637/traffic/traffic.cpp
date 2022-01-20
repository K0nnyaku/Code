#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	printf("%d\n",n*n*m*k);
	return 0;
}
