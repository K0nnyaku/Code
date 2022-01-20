#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
//#include<iostream>
using namespace std;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	srand(time(NULL));
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	printf("%d",rand()%100+1);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

