#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
struct node{
	int ll,rr;
}a1[N],a2[N];
bool vis[N];
int n,m1,m2,sum,maxx=0,t;
bool cmp(node a,node b){
	return a.ll<b.ll;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i].ll,&a1[i].rr);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&a2[i].ll,&a2[i].rr);
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	if(m2==0){
		int s1=n;
		t=0;
		for(int i=1;i<=m1;i++){
			sum=0;
			for(int j=i-1;j>=1;j--){
				if(a1[i].ll<a1[j].rr&&vis[j]){
					sum++;
				}
			}
			if(sum<s1){
				t++;
				vis[i]=1;
			}
			else vis[i]=0;
		}
		maxx=max(maxx,t);
	}
	else if(m1==0){
		int s2=n;
		t=0;
		for(int i=1;i<=m2;i++){
			sum=0;
			for(int j=i-1;j>=1;j--){
				if(a2[i].ll<a2[j].rr&&vis[j]){
					sum++;
				}
			}
			if(sum<s2){
				t++;
				vis[i]=1;
			}
			else vis[i]=0;
		}
		maxx=max(maxx,t);
	}
	else{
	for(int s1=n;s1>=0;s1--){
		int s2=n-s1;
		t=0;
		for(int i=1;i<=m1;i++){
			sum=0;
			for(int j=i-1;j>=1;j--){
				if(a1[i].ll<a1[j].rr&&vis[j]){
					sum++;
				}
			}
			if(sum<s1){
				t++;
				vis[i]=1;
			}
			else vis[i]=0;
		}
		for(int i=1;i<=m2;i++){
			sum=0;
			for(int j=i-1;j>=1;j--){
				if(a2[i].ll<a2[j].rr&&vis[j]){
					sum++;
				}
			}
			if(sum<s2){
				t++;
				vis[i]=1;
			}
			else vis[i]=0;
		}
		maxx=max(maxx,t);
	}
	}
	printf("%d",maxx);
	return 0;
} 
