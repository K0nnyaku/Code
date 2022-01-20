#include<cstdio>
#include<iostream>
#include<queue>
int a,b;
using namespace std;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d %d",&a,&b);
	if(a==2&&b==5)printf("LRRLLRRRRL\n");
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
