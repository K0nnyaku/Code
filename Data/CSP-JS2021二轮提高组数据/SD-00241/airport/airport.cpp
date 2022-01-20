#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int f[100050];
int n,m1,m2,u;
pair<int,int>f1[100050];
pair<int,int>f2[100050];
int vis1[100050],vis2[100050];
int check(int l,int r,pair<int,int>* a,int* v){
	int mid=0;
	int k=r;
	while(l<r){
		mid=(l+r)/2;
		if(a[mid].first<u)l=mid+1;
		else r=mid;
	}
	while(v[r]==1){
		r++;
		if(r>k)return 0x3f3f3f3f;
	}
	if(a[r].first<u)return 0x3f3f3f3f;
	return r;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&f1[i].first,&f1[i].second);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&f2[i].first,&f2[i].second);
	}
	sort(f1+1,f1+m1+1);
	sort(f2+1,f2+m2+1);
	f[0]=0;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++){
		u=0;
		if(ans1==0)for(int j=check(1,m1,f1,vis1);j<=m1;j=check(j+1,m1,f1,vis1)){
			if(j>m1)break;ans1++,vis1[j]=1,u=f1[j].second;
		}
		u=0;
		if(ans2==0)for(int j=check(1,m2,f2,vis2);j<=m2;j=check(j+1,m2,f2,vis2)){
			if(j>m2)break;ans2++,vis2[j]=1,u=f2[j].second;
		}
		if(ans1>=ans2){
			f[i]=f[i-1]+ans1;
			ans1=0;
		}
		else{
			f[i]=f[i-1]+ans2;
			ans2=0;
		}
	}
	printf("%d",f[n]); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
