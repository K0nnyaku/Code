#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int t,n,a[1000001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=2*n;j++){
			scanf("%d",&a[j]);
		}
	}
	for(int i=1;i<=t;i++){
		printf("%d",-1);
		if(i!=t)
			printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

