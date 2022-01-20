#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int m;
int a[1000005];
int ans[1000005];
bool able[1000005];
bool ans1[1000005];
bool shuchu[1000005];
bool fin;
void sf(int l,int r,int top){
	
	if(fin==1){
		return;
	}
	if(top==2*n+1){
		fin=1;
		for(int k=1;k<=2*n;k++){
			shuchu[k]=ans1[k];
		}
	}
	if(top<=n){
		if(able[a[l]]==0){
			ans[top]=a[l];
			able[a[l]]=1;
			ans1[top]=0;
			sf(l+1,r,top+1);
			able[a[l]]=0;
		}
		if(able[a[r]]==0){
			ans[top]=a[r];
			able[a[r]]==1;
			ans1[top]=1;
			sf(l,r-1,top+1);
			able[a[r]]=0;
		}
	}
	if(top>n){
		if(ans[2*n-top+1]==a[l]){
			ans[top]=a[l];
			ans1[top]=0;
			sf(l+1,r,top+1);
		}else
		if(ans[2*n-top+1]==a[r]){
			ans[top]=a[r];
			ans1[top]=1;
			sf(l,r-1,top+1);
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n;
		for(int j=1;j<=2*n;j++){
			scanf("%d",&a[j]);
			able[j]=0;
		} 
		fin=0;
		sf(1,2*n,1);
		if(fin==1){
			for(int k=1;k<=2*n;k++){
				if(shuchu[k]==0){
					printf("L");
				}
				else{
					printf("R");
				}
			}
			cout<<endl;
		}
		else
		cout<<"-1"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

