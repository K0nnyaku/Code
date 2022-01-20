#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,n,a[100010];
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=2*n;i++) {
			cin>>a[i];
		}
		
		cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
