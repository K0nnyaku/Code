#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m1,m2; 
int in_,out_;
int tail[100010][2];
int num_ap[100010][2]; 
int ans;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int nei_apmax=0;
	for(int i=1;i<=m1;i++){
		cin>>in_>>out_;
		for(int j=1;;j++){
			if(in_>tail[j][0]){
				tail[j][0]=out_;
				num_ap[j][0]++;
				nei_apmax=max(nei_apmax,j);
				break;
			}
		}
	}
	int wai_apmax=0;
	for(int i=1;i<=m2;i++){
		cin>>in_>>out_;
		for(int j=1;;j++){
			if(in_>tail[j][1]){
				tail[j][1]=out_;
				num_ap[j][1]++;
				wai_apmax=max(wai_apmax,j);
				break;
			}
		}
	}
	if(n==0) {
		cout<<0;
		return 0;
	}
	int ans_1,ans_2;
	for(int i=0;i<=n;i++){
		ans_1=0;
		ans_2=0;
		if(i!=0)
			for(int j=1;j<=i;j++)
				ans_1+=num_ap[j][0]; 
		if(n-i!=0)
			for(int j=1;j<=n-i;j++)
				ans_2+=num_ap[j][1];
		ans=max(ans,ans_1+ans_2);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
//by KS_tips_CN in CSP-S2021
//airport
