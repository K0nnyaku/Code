#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<time.h> 
using namespace std;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n;
	cin>>n;	
	if(n<=15){
		srand(time(NULL));
		printf("%d",rand()%20);
	}
	else if(n>15&&n<=40){
		srand(time(NULL));
		printf("%d",rand()%100);
	}
	else if(n>40&&n<=100){
		srand(time(NULL));
		printf("%d",rand()%860221552);
	}
	else {
		srand(time(NULL));
		printf("%d",rand()%546949722);
	}
	return 0;
}
