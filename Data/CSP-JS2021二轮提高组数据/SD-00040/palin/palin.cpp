#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[1000005];
int b[1000005];
int ans[1000005];
int mans[1000005];
int fr,ed,k;
int tingg,sum=0;
bool tui;
void dfs(int bushu){
	if(tui==1) 
		return;
	if(bushu==2*n){
		bool pdh=0;
		for(int i=1;i<=n;i++)
			if(b[i]!=b[2*n-i+1]){
				pdh=1;
				break;
			}
			//cout<<b[i]<<" ";
		if(pdh==0){
			sum++;
			if(sum>=200){
				tui=1;
				return;
			}
			for(int i=1;i<=2*n;i++){
				if(ans[i]>mans[i]){
					for(int j=1;j<=2*n;j++)
						mans[i]=ans[i];
					return;
				}
			}
		}		
		return;
	}
	for(int i=bushu+1;i<=2*n;i++){
		for(int j=1;j<=2;j++){
			if(j==1){
				fr++;
				ans[++k]=99;
				b[bushu+1]=a[fr];
				dfs(bushu+1);
				b[bushu+1]=0;
				ans[k]=0;
				fr--;k--;
			}
			if(j==2){
				ed--;
				ans[++k]=2;
				b[bushu+1]=a[ed];
				dfs(bushu+1);
				b[bushu+1]=0;
				ans[k]=0;
				ed++,k--;
			}
		}
	}
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		memset(b,0,sizeof(b));
		memset(ans,0,sizeof(ans));
		memset(mans,0,sizeof(mans));
		tui=0;
		sum=0;
		scanf("%d",&n);
		for(int j=1;j<=2*n;j++)
			scanf("%d",&a[j]);
		fr=0,ed=2*n+1;
		dfs(0);
		bool subb=0;
		for(int j=1;j<=2*n;j++)
			if(ans[i]=='0'){
				printf("-1\n");
				subb=1;
				break;
			}
		if(subb==0){
			for(int j=1;j<=2*n;j++)
				if(ans[j]==99)
					printf("L");
				else
					printf("R");
			printf("\n");
		}
	}
	return 0;
}
