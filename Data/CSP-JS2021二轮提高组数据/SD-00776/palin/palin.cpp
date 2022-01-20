#include<iostream>
#include<cstring>
using namespace std;
int a[600005];
int check(int n) {
	for(int i=1;i<=n;i++) {
		if(a[i]!=a[2*n+1-i]) return 0;
	}
	return 1;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
		for(int i=1;i<=2*n;i++) {
			scanf("%d",&a[i]);
		}
		if(check(n)) {
			for(int i=1;i<=2*n;i++) printf("L");
			puts("");
		} else puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
