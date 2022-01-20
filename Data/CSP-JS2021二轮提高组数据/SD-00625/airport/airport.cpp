#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans;
int num1[100000010],num2[100000010],ans1[100010],ans2[100010];
struct FLY{
	int arr,lea;
}
nat[100010],fre[100010];
int cmp(FLY a,FLY b){
	return a.arr<b.arr; 
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;	
	for(int i=1;i<=m1;i++)
	cin>>nat[i].arr>>nat[i].lea;
	sort(nat+1,nat+1+m1,cmp);
	for(int i=1;i<=m2;i++)
	cin>>fre[i].arr>>fre[i].lea;
	sort(fre+1,fre+1+m2,cmp);
	for(int i=1;i<=n;i++){
		int cnt1=0;
		for(int k=1;k<=100010;k++)
		num1[k]=0;
		if(i==m1){
			for(int j=i;j<=n;j++)
			ans1[j]=m1;
			break;
		}
		else{
			for(int j=1;j<=m1;j++){
				if(num1[nat[j].arr]<i){
					ans1[i]++;
					for(int x=nat[j].arr;x<=nat[j].lea;x++){
						num1[x]++;
					}
				}
			}
			if(ans1[i]==m1&&i<n){
				for(int z=i+1;z<=n;z++)
				ans1[z]=m1;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int cnt2=0;
		for(int k=1;k<=100010;k++)
		num2[k]=0;
		if(i==m2){
			for(int j=i;j<=n;j++)
			ans2[j]=m2;
			break;
		}
		else{
			for(int j=1;j<=m2;j++){
				if(num2[fre[j].arr]<i){
					ans2[i]++;
					for(int x=fre[j].arr;x<=fre[j].lea;x++){
						num2[x]++;
					}
				}
			}
			if(ans2[i]==m2&&i<n){
				for(int z=i+1;z<=n;z++)
				ans2[z]=m2;
				break;
			}
		}
	}
	for(int i=0;i<=n;i++){
		if(ans1[i]+ans2[n-i]>ans)
		ans=ans1[i]+ans2[n-i];
	}
	cout<<ans<<endl;
	return 0;
} 
