#include<cstdio>
#include<iostream> 
using namespace std;
int ans,A1,B1,A2,B2; 
int one[100005],two[100005];
int n,m1,m2,a1[100005],b1[100005],a2[100005],b2[100005];
int guonei(int sum1){
	int ans1=0;
	int summ=sum1;
	if(sum1==0) return 0;
	for(int i=A1;i<=B1;i++){
		for(int j=1;j<=m1;j++){
			if(sum1>0&&i==a1[j]){
				sum1--;
				ans1++;
				one[j]++;
				break;
			}
			else if(i==b1[j]&&one[j]!=0){
				sum1++;
				break;
			}
		}
	}
	//cout<<ans1<<" ";
	return ans1;
}
int guowai(int sum2){
	int ans2=0;
	int summ=sum2;
	if(sum2==0) return 0;
	for(int i=A2;i<=B2;i++){
		for(int j=1;j<=m2;j++){
			if(sum2>0&&i==a2[j]){
				sum2--;
				ans2++;
				two[j]++;
				break;
			}
			else if(i==b2[j]&&sum2<summ&&two[j]!=0){
				sum2++;
				break;
			}
		}
	}
	//cout<<ans2<" ";
	return ans2;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen(" airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i]>>b1[i];
		if(i==1) A1=a1[1];
		A1=min(A1,a1[i]);
		B1=max(B1,b1[i]);
	}
	for(int i=1;i<=m2;i++){
		cin>>a2[i]>>b2[i];
		if(i==1) A2=a2[1];
		A2=min(A2,a2[i]);
		B2=max(B2,b2[i]);
	}
//	cout<<A1<<" "<<B1<<" "<<A2<<" "<<B2<<endl;
	for(int i=0;i<=n;i++){
	   ans=max(ans,guonei(i)+guowai(n-i));
//	   cout<<guonei(i)+guowai(n-i)<<endl;	
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
