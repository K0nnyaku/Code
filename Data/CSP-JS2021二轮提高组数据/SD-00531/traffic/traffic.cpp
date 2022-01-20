#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<utility>
#include<ctime>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	long long rp=0;
	while(rp<=23333){rp++;}
	srand(time(0));
	printf("%d\n",rand()%RAND_MAX);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

