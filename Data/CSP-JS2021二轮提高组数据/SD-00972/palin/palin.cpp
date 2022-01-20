#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=5e5+10;

int a[maxn];

int t,n;

bool hw(){
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[2*n-i+1]){
			flag=false;
			break;
		}
	}
	return flag;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		if(hw()){
			for(int j=1;j<=2*n;j++) printf("L");
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
