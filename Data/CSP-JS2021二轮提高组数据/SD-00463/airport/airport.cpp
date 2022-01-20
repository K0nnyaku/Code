#include<iostream>
#include<cstdio> 
using namespace std;
long long n,m1,m2,i,j;
long long t,t1[3][1000000],t2[3][1000000],a,b,ans[2];
long long am[1000000],bm[1000000];
void tca(){
	for(int k=1;k<=a;k++){
		if(am[k]==0&&t1[0][j]==0){
			am[k]=t1[2][j];
			ans[0]++;
			t1[0][j]=1;
		}
		else if(t1[0][j]==0&&t1[1][j]>=am[k]){
		 	am[k]=t1[2][j];
		 	ans[0]++;
		 	t1[0][j]=1;
		}  
	} 	
} 
void tcb(){
	for(int k=1;k<=b;k++){
		if(bm[k]==0&&t2[0][j]==0){
			bm[k]=t2[2][j];
			ans[0]++;
			t2[0][j]=1;
		}
		else if(t2[0][j]==0&&t2[1][j]>=bm[k]){
		 	bm[k]=t2[2][j];
		 	ans[0]++;
		 	t2[0][j]=1;
		}  
	} 	
} 
void ql(){
	for(int k=1;k<=m1;k++){
		am[k]=0;t1[0][k]=0;
	} 
	for(int k=1;k<=m2;k++){
		bm[k]=0;t2[0][k]=0;
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++) cin>>t1[1][i]>>t1[2][i];
	for(i=1;i<=m2;i++) cin>>t2[1][i]>>t2[2][i];
	a=0;b=n;
	for(i=0;i<=n;i++){
		ans[0]=0;
	 	for(j=1;j<=m1;j++){
			 tca();
			} 
		for(j=1;j<=m2;j++){
			 tcb();
			} 
		ql();
		++a;
		--b;
		ans[1]=max(ans[0],ans[1]);
	 }
	 cout<<ans[1]<<endl;
	 
	fcolse(stdin);
	fcolse(stdout);
	
	 return 0;
}
