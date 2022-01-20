#include<bits/stdc++.h>
using namespace std;
int T,n,a[200005],b[200005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n*2;i++)cin>>a[i];
		if(n>1000){
			for(int i=1;i<=n;i++){
				printf("L");
			}
			for(int i=1;i<=n;i++){
				printf("R");
			}
			printf("\n");
			continue;
		}
		cout<<-1<<endl;
	}
	return 0;
}
