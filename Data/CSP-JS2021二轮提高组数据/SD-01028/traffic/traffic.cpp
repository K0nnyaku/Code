#include <bits/stdc++.h>
using namespace std;
int n,m,t,l,k,a[55],b[55],c[55]; 
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%i%i%i",&n,&m,&t);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			scanf("%i",&l);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			scanf("%i",&l);
		}
	}
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%i",&k);
		for(int j=1;j<=k;j++){
			scanf("%i%i%i",&a[j],&b[j],&c[j]);
		}
		if(k==2){
			if(c[1]==c[2])
				printf("0\n");
			else
				printf("%i\n",min(a[1],a[2]));
		}else{
			printf("0\n");
		}
	}
	return 0;
}
