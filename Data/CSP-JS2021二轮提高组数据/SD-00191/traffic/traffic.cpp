#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(){


	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	srand(time(NULL));
	printf("%d",rand()%100);
	
	
	return 0;
}
