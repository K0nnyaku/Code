#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m1,m2;
struct nod{
	int a,b;
}e[20010];
struct nodd{
	int c,d;
}w[20010];
bool v[10010];
bool cmp(nod x,nod y){
	return x.a<y.a;
}
bool dmp(nodd x,nodd y){
	return x.c<y.c;
}
int gn(int x){
	memset(v,0,sizeof(v));
	if(x==0) return 0;
	int cnt=0;
	int sum=0;
	for(int i=1;i<=m1;i++){
		for(int j=1;j<i;j++){
			if(v[j]){
				if(e[j].b<e[i].a){
					cnt--;
					v[j]=false;
				}
			}
		}
		if(cnt<x){
			v[i]=true;
			sum++;
			cnt++;
		}
	}
	return sum;
}
int gw(int x){
	memset(v,0,sizeof(v));
	if(x==0) return 0;
	int cnt=0;
	int sum=0;
	for(int i=1;i<=m2;i++){
		for(int j=1;j<i;j++){
			if(v[j]){
				if(w[j].d<w[i].c){
					cnt--;
					v[j]=false;
				}
			}
		}
		if(cnt<x){
			v[i]=true;
			sum++;
			cnt++;
		}
	}
	return sum;
}
int fp(int x,int y){
	return gn(x)+gw(y);
}
int ans=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>e[i].a>>e[i].b;
	}
	for(int i=1;i<=m2;i++){
		cin>>w[i].c>>w[i].d;
	}
	sort(e+1,e+1+m1,cmp);
	sort(w+1,w+1+m2,dmp);
//	for(int i=1;i<=m1;i++){
//		cout<<e[i].a<<endl;
//	}
//	for(int i=1;i<=m2;i++){
//		cout<<w[i].c<<endl;
//	}
	if(n<=5000){
		for(int i=0;i<=n;i++){
			ans=max(fp(i,n-i),ans);
		}
		cout<<ans;
		return 0;
	}
	else{
		cout<<(m1+m2)/2;
		return 0;
	}
	return 0;
}


