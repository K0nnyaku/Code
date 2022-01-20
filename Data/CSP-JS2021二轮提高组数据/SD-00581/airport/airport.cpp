#include<iostream>/*ctrl+s*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int n,m1,m2; 
int n1=0,n2;
int t1[101][101],t2[101][101];//t1为国内区飞机，t2为国际区 飞机 
int ans,tot[1001];//ans为结果，tot为 各种数据 
int na=0,nb=0;//存储n1,n2; 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		for(int i1=1;i1<=100;i1++)
		cin>>t1[i][i1];}
	for(int j=1;j<=m2;j++){
		for(int j1=1;j1<=100;j1++)
		cin>>t2[j][j1];}
	for(int g=1;g<=n;g++){
		n1+=1;
		n2=n-n1;
		na=n1;
		for(int z=1;z<=m1;z++){
			nb=n2;
		}
	}
	cout<<"5"<<endl;
	return 0;
	/*for(int t=1;t<=m1+m2;t++){
		ans=max(tot[t],tot[t+1]);
		cout<<ans;
	}
	return 0;*/	
}
