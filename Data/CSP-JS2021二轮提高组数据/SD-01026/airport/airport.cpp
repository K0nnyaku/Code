#include<bits/stdc++.h>
using namespace std;
int n,M1,M2,temp1[100001],temp2[100001],ans,tans,mint=INT_MAX;
struct xx{
	int a,b;
}m1[100001],m2[100001],mt;
bool cmp1(xx at,xx bt){
	return at.a<bt.a;
}
bool cmp2(int at,int bt){
	return at<bt;
}
int main(){
	freopen("airport.in","r",stdin);freopen("airport.out","w",stdout);
	cin>>n>>M1>>M2;
	for(int i=1;i<=M1;i++){
		cin>>m1[i].a>>m1[i].b;
	}
	sort(m1+1,m1+M1,cmp1);
	for(int i=1;i<=M2;i++){
		cin>>m2[i].a>>m2[i].b;
	}
	sort(m2+1,m2+M2,cmp1);
	for(int A=1;A<=n;A++){
		tans=n;
		int B=n-A;
		for(int i=1;i<=A;i++){
			temp1[i]=m1[i].b;
		}
		for(int i=A+1;i<=M1;i++){
			if(temp1[1]<m1[i].a){
				tans++;
				temp1[1]=m1[i].b;
			}
		}
		
		for(int i=1;i<=B;i++){
			temp2[i]=m2[i].b;
		}
		for(int i=B+1;i<=M2;i++){
			if(temp2[1]<m2[i].a){
				tans++;
				temp2[1]=m2[i].b;
			}
		}
		if(tans>ans){
				ans=tans;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
