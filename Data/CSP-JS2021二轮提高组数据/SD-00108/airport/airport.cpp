#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m1,m2,a,b;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1+m2;i++){
		scanf("%d%d",&a,&b);
	}
	printf("%d",n+m2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
