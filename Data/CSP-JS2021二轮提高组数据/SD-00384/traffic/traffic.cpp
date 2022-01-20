#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<t;i++)printf("%d\n",rand()%1024653);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
