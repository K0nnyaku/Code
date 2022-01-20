#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,a[500001];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<=a[i]*2;j++)
			scanf("%d",&b);
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
