#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int a[500005];
bool hw(string k)
{
	for(int i=0;i<=k.length()/2;i++)
	if(k[i]!=k[k.length()-i-1])return 0;
	return 1;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,n;string s;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
			s+=char(a[i]+'0');
		}
		if(hw(s))
		while(n--)
		{
			printf("LL");
			printf("\n");
		}
		else printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
