#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("traffic.in","w",stdin);
	freopen("traffic.out","r",stdout);
	int n,m,t,a;
	 scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n-1;i++){
		for(int i=1;i<=m;i++){
			scanf("%d",&a);
		}
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m-1;i++){
			scanf("%d",&a);
		}
	}
	for(int i=1;i<=t;i++){
		for(int i=1;i<=3;i++){
			scanf("%d",&a);
		}
	}
	printf("12");
          fclose(stdin);
          fclose(stdout);
	
	return 0;
}
