#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int a;
	cin>>a;
	if(a==2) {
		printf("LRRLLRRRRL\n-1");
	} else {
		for(int i=0;i<a;i++) {
			printf("-1\n");
		}
	}
	return 0;
}
