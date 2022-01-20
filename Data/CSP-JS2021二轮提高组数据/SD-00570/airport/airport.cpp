#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<bits/stdc++.h>
using namespace std;
int n,mm1,mm2,p,summ,suum,tott;
int ans=-11,vis[202020],vis1[202020];
struct node{
	long long daoda,likai,daoda1,likai1;
}e[101001],c[101001];
bool cmp( node a,node b){
	if(a.daoda<b.daoda){
		return a.daoda<b.daoda;
	}
	if(a.daoda1>b.daoda1){
		return a.daoda1<b.daoda1;

	}
}
void dfs(int k) { //k表示国内区连廊个数
	if(k==n+1) {
		cout<<ans<<endl;
		return;
	}
	memset(vis,0,sizeof(vis));
	memset(vis1,0,sizeof(vis1));
	p=0,tott=0;
	summ=k;
	if(summ>0){
		p++;
		summ--;
		vis[1]=1;
	}
	for(int i=2; i<=mm1; i++) { //国内区进行遍历
	for(int j=1;j<i;j++){
		if(vis[j]==1){//vis==1为停下 
			if(e[i].daoda>e[j].likai) {
			vis[j]=0;//飞了 
			summ++;
		   }
		}
		else continue;
	}
		if(summ>0) {
			vis[i]=1;
			p++;
			//cout<<p<<" ";
			//shij[i]=daoda[i];
			//shijia[i]=likai[i];
			summ--;
		}
		else continue;
	}	
		//for(int i=1;i<=m1;i++){
		//cout<<vis[i]<<" ";}
	//cout<<endl;
	suum=n-k;
	if(suum>0){
		tott++;
		suum--;
		vis1[1]=1;
	}
	for(int i=2; i<=mm2; i++) {
	for(int j=1;j<i;j++){
		if(vis1[j]==1){//vis==1为停下 
			if(c[i].daoda1>c[j].likai1) {
			vis1[j]=0;//飞了 
			suum++;
		   }
		}
		else continue;
	}
		if(suum>0) {
			vis1[i]=1;
			tott++;
			//cout<<tott<<" "; 
			suum--;//连廊胡数
		}
		else continue;
	}
	//cout<<endl;
	//cout<<endl;
	ans=max(ans,tott+p);
	dfs(k+1);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>mm1>>mm2;
	for(int i=1; i<=mm1; i++) {
		cin>>e[i].daoda>>e[i].likai;
	}
	sort(e+1,e+1+mm1,cmp);
	for(int i=1; i<=mm2; i++) {
		cin>>c[i].daoda1>>c[i].likai1;
	}
	sort(c+1,c+1+mm2,cmp);
	dfs(0);
fclose(stdin);
fclose(stdout);
	return 0;
}

