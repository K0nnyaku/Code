#include <iostream>
using namespace std;
int a1[100010],a2[100010],b1[100010],b2[100010];
int guonei[100010],guoji[100010];
int n=0,m1=0,m2=0;
int main(){
freopen("airport.in","r",stdin);
freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a1[i]>>a2[i];	}
	for(int i=1;i<=m2;i++){
		cin>>b1[i]>>b2[i];}
	for(int j=1;j<=m1;j++){
		for(int i=1;i<=m1;i++){
			if(a1[j]<a1[i]){
				int c=a1[i],d=a2[i];a1[i]=a1[j];a2[i]=a2[j];a1[j]=c;a2[j]=d;}}}
	for(int j=1;j<=m2;j++){
		for(int i=1;i<=m2;i++){
			if(b1[j]<b1[i]){
				int c=b1[i],d=b2[i];b1[i]=b1[j];b2[i]=b2[j];b1[j]=c;b2[j]=d;}}}
	int ans[10010];
	int rans=0;
	for (int i=0;i<=n;i++){
		int m;

		m=n-i;
		if(i!=0){
		for(int k=1;k<=i;k++){
			guonei[k]=a2[k];
			ans[i]++;}
			for(int w=i+1;w<=m1;w++){
				for(int k=1;k<=i;k++){
				if(a1[w]>guonei[k]){
					guonei[k]=a2[w];

					ans[i]++;break;
				}}}}
		if(m!=0){
		for(int k=1;k<=m;k++){
			guoji[k]=b2[k];
			ans[i]++;}
			for(int w=m+1;w<=m2;w++){
				for(int k=1;k<=m;k++){
					if(b1[w]>guoji[k]){
					guoji[k]=b2[w];

					ans[i]++;break;
				}}}}

			rans=max(ans[i],rans);}
		cout<<rans;
return 0;}
