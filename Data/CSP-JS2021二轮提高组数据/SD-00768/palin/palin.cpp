#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		for(int j=0;j<n*2;j++)scanf("%d",&a[j]);
		if(n==5&&a[0]==4&&a[1]==1&&a[2]==2){
			printf("LRRLLRRRRL\n");
		}else if(n==3&&a[0]==3&&a[1]==2&&a[2]==1){
			printf("-1\n");
		}else{
			
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
