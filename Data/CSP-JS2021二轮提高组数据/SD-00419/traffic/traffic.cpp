#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<t;i++){
		printf("%d\n",2*n*m*t);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
