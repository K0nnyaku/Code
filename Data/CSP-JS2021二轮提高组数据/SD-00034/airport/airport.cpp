#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,sum,res,last;
int kt[10000003];
int lggn[100000],lggw[100000],gnt,gwt;
bool goon(int d,int p){
	int q=0;
	if(d>m1+m2&&d<=2*m1+m2)for(int i=1;i<=p;i++)if(d==lggn[i]+m1+m2)q=i;
	if(q){
		for(int i=q;i<=p;i++)lggn[i]=lggn[i+1];
		return 1;
	}
	return 0;
}
bool goow(int d,int p){
	int q=0;
	if(d>2*m1+m2)for(int i=1;i<=p;i++)if(d==lggw[i]+m1+m2)q=i;
	if(q){
		for(int i=q;i<=p;i++)lggw[i]=lggw[i+1];
		return 1;
	}
	return 0;
}
void go(int x){
	int gn=x,gw=n-x,cntgn=0,cntgw=0,res=0;
	for(int i=1;i<=last;i++){
		if(!kt[i])continue;
		if(kt[i]<=m1&&cntgn<gn){cntgn++;res++;lggn[cntgn]=kt[i];continue;}
		if(kt[i]>m1&&cntgw<gw&&kt[i]<=m1+m2){cntgw++;res++;lggw[cntgw]=kt[i];continue;}
		if(goon(kt[i],cntgn)){cntgn--;continue;}
		if(goow(kt[i],cntgw)){cntgw--;continue;}
	} 
	sum=max(sum,res);
	return;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int a,b;
	for(int i=1;i<=m1;i++){
		cin>>a>>b;
		kt[a]=i;
		kt[b]=i+m1+m2;
		last=max(b,last);
	}
	for(int i=m1+1;i<=m1+m2;i++){
		cin>>a>>b;
		kt[a]=i;
		kt[b]=i+m1+m2;
		last=max(b,last);
	}
	for(int i=0;i<=n;i++)go(i);
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//21!9-324@emb 

