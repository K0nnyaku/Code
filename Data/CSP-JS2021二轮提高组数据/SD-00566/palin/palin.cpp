#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,n;
int num[1000005],ch[500005];
int ans[1000005];
int temp[1000005];
bool check;
void dfs(int k,int l,int r){
	if(check)	return ;
	if(k==n*2){
		int Check=false;
		for(int i=1;i<=n;i++)
			if(ans[i]!=ans[n*2-i+1])
				Check=true;
		if(Check)	return ;
		else{
			for(int i=1;i<=n*2;i++){
				if(temp[i]==1)
					printf("R");
				else
					printf("L");
			}
			printf("\n");
			check=true;
			return ;
		}
	}
	temp[k+1]=0;
	ans[k+1]=num[l];
	dfs(k+1,l+1,r);
	temp[k+1]=1;
	ans[k+1]=num[r];
	dfs(k+1,l,r-1);
	return ;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		check=false;
		bool pd=false;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<=n;i++){
			if(num[i]!=num[i-1] && num[i]!=num[i+n])
				continue;
			for(int j=i+1;j<=i+n;j++){
				ch[num[j]]++;
				if(ch[num[j]]>1){
					pd=true;
					break;
				}
			}
			if(pd){
				printf("-1\n");
				continue;
			}
		}
		dfs(0,1,n*2);
		if(!check)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

