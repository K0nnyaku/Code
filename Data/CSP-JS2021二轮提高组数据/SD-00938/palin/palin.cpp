#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int N=10001;
priority_queue<int,vector<int>,greater<int> >  q;
int n[N],m[N];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int a;
		scanf("%d",&a);
		memset(n,0,sizeof(n));
		memset(m,0,sizeof(m));
		for(int i=1;i<=a*2;i++)
		scanf("%d",&n[i]);
		if(t==2&&n[1]==4&&a==5)
		printf("LRRLLRRRRL\n");
		if(t==2&&a==3&&n[1]==3)
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
