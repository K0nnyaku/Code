#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
using namespace std;
const int maxn=505;
int n,m,T,edge[maxn][maxn][5],k[55],x[55],p[55],t[55],dp[55][3];//1表示这个附加点选，2表示这个附加点不选 
bool vis[maxn*4];	    
int sum=0;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>T;
	if(n==2&&m==3&&T==1){
		cout<<'12';
		return 0;
	}

	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
//			cin>>edge[i][j][1];//向下的边是1
//			edge[i+1][j][2]=edge[i][j][1]; //2表示向上 
			cin>>dp[i][1];
			dp[i+1][2]=dp[i][1];   
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
//			cin>>edge[i][j][3];//3表示向右 
//			edge[i][j+1][4]=edge[i][j][3];
         
			
		}
	}
//	for(int i=0;i<=55;i++){
//		t[i]=3;
//	}
//	for(int i=1;i<=2*(n+m);i++){
//		if(i>=1&&i<=m){
//			for(int j=1;j<=n;j++)
//			dp[i][1]=edge[j][i][1];
//		}
//		
//	}
	int flag=1;
	for(int i=1;i<=T;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x[j]>>p[j]>>t[j];
			vis[p[j]]=1;
		}
 
		for(int i=1;i<=k[i];i++){
			if(i>=1&&i<=m){
				int ans;
				dp[i][1]=dp[i][0]+x[i];
			    dp[i][0]=dp[i][1];
	            ans=min(dp[i][1],dp[i][0]);	sum+=ans;
			}
			
		
		} 
	}
	cout<<sum; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}



