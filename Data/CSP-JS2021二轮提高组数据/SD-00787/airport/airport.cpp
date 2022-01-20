#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2;
struct ty{
	int arr;
	int lea;
	int vis;
};
bool cmp(ty a,ty b){
	return a.arr<b.arr;
}
ty is[100005];
ty os[100005];
int ansi=0;
int anso=0;
int ansii[100005]={0};
int ansoo[100005]={0};
int maxx=0;
int findi(){
	int maxn=0;
	if(ansi==m1){
		return ansi;
	}
	for(int i=1;i<=m1;i++){
		if(is[i].vis==0&&is[i].arr>=maxn){
			ansi++;
			is[i].vis=1;
			maxn=is[i].lea;
		}
	}
	return ansi;
}
int findo(){
	int maxn=0;
	if(anso==m2){
		return anso; 
	}
	for(int i=1;i<=m2;i++){
		if(os[i].vis==0&&os[i].arr>=maxn){
			anso++;
			os[i].vis=1;
			maxn=os[i].lea;
		}
	}
	return anso;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>is[i].arr>>is[i].lea;
		is[i].vis=0;
	}
	sort(is+1,is+m1+1,cmp);
	for(int i=1;i<=m2;i++){
		cin>>os[i].arr>>os[i].lea;
		os[i].vis=0;
	}
	sort(os+1,os+m2+1,cmp);
	for(int i=1;i<=n;i++){
		ansii[i]=findi();
		ansoo[i]=findo();
	}
	for(int i=0;i<=n;i++){
		maxx=max(maxx,ansii[i]+ansoo[n-i]);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
