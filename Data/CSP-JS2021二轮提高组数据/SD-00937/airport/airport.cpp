#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m1,m2,num[1000001],t=1;
ll mx=0,mn=9999999;
ll come1[1000001],leave1[1000001],come2[1000001],leave2[1000001];
bool pan1[1000001],pan2[1000001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	ll p=n,p1=m1,p2=m2;
	for(int i=1;i<=m1;i++){
			cin>>come1[i]>>leave1[i];
			if(leave1[i]>mx)	mx=leave1[i];
			if(come1[i]<mn)		mn=come1[i];
	}
	for(int i=1;i<=m2;i++){
			cin>>come2[i]>>leave2[i];
			if(leave2[i]>mx)	mx=leave2[i];
			if(come2[i]<mn)		mn=come2[i];
	}
	for(int i=0;i<=n;i++){
		t=1;
		ll p1=i,p2=n-i,q1=i,q2=n-i;
		for(int k=0;k<=mx;k++)		pan1[k]=false;
		for(int k=0;k<=mx;k++)		pan2[k]=false;
		while(t!=mx){
			if(t>=mn){
				if(q1>0){
					for(int j=1;j<=m1;j++){
						if(t==leave1[j]&&pan1[t]){
							p1++;}

						if(t==come1[j]&&p1>0){
							num[i]++;
							p1--;
							pan1[leave1[j]]=true;
							break;}}}
				if(q2>0){
					for(int j=1;j<=m2;j++){
						if(t==leave2[j]&&pan2[t]){
							p2++;}
						if(t==come2[j]&&p2>0){
							num[i]++;

							p2--;
							pan2[leave2[j]]=true;
							break;}}}
					}t++;}}  
	sort(num,num+n+1,cmp);
	cout<<num[0]<<endl; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
