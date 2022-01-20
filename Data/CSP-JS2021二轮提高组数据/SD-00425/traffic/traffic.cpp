#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<time.h> 
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(NULL));
	int n,m,t;
	cin>>n>>m>>t;
	while(t){
		t--;
		printf("%d\n",rand()%99999999);
	}
	return 0;
}
