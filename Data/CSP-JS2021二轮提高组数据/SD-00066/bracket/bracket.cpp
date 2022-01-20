#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

int n,m,k;

int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		char c;
		cin>>c;
		if (c!='?') m++;
	}
	printf("%d",(n*m/k)-1);
	return 0;
	
	
	
	
}
