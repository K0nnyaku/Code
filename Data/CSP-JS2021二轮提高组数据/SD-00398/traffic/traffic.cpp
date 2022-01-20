#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int ans;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
			ans+=x;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			int x;
			scanf("%d",&x);
		}
	}
	while(t--){
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
