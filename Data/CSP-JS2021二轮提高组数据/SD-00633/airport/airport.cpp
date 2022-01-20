#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
#define ll long long
struct tj{
	int kt=0;
	int xc=0;
	int xh;
}zg[100000];
bool cmp(tj a,tj b){
	return a.xc<b.xc;
}
bool cmp1(tj a,tj b){
	if(a.xh=b.xh){
		return a.kt>b.kt;
	}
		return a.xh<b.xh;
}
int x,y;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,j=0,z=0,cnt=0;
	scanf("%d %d %d",&n,&m1,&m2);
	zg[0].xh=0;
	for(int i=0;i<m1;i++){
		cin>>x>>y;
		sort(zg+0,zg+j,cmp);
		if(zg[0].xc<x){
			zg[0].kt++;
			zg[0].xc=y;
		}else{
			j++;
			zg[j].kt++;
			zg[j].xc=y;
			zg[j].xh=j;
		}
	}
	zg[j+1].xh=0;
	for(int i=0;i<m2;i++){
		cin>>x>>y;
		sort(zg+j+1,zg+j+1+z,cmp);
		if(x>zg[j+1].xc){
			zg[j+1].kt++;
			zg[j+1].xc=y;
		}else{
			z++;
			zg[j+1+z].kt=1;
			zg[j+1+z].xc=y;
			zg[j+1+z].xh=z;
		}
	}
	sort(zg+0,zg+j+z+1,cmp1);
	for(int i=0;i<n;i++) cnt+=zg[i].kt;
	cout<<cnt; 
	fclose(stdout);
	fclose(stdin);
	return 0;
}
