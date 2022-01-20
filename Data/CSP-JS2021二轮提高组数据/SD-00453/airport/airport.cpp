#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100010
using namespace std;
int m1,m2;
int n; 
struct Node{
	int x,y;
}a[N],b[N]; 
bool cmp(Node a,Node b){
	return a.x<b.x;
}
int ans;
int d[100000010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i){
		cin>>a[i].x>>a[i].y;
		a[i].y--;
	}
	for(int i=1;i<=m2;++i){
		cin>>b[i].x>>b[i].y;
		b[i].y--;
	} 
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=0;i<=n;++i){//国内区数量 
		int sum1=m1,sum2=m2;
		for(int j=1;j<=m1;++j)d[a[j].x]=0;
		for(int j=1;j<=m1;++j){
			if(d[a[j].x]+1>i)sum1--;
			else{
				for(int k=j+1;a[k].x<=a[j].y;++k)++d[a[k].x];
			}
		}
		for(int j=1;j<=m2;++j)d[b[j].x]=0;
		for(int j=1;j<=m2;++j){
			if(d[b[j].x]+1>n-i)sum2--;
			else{
				for(int k=j+1;b[k].x<=b[j].y;++k)++d[b[k].x];
			}
		}
		ans=max(ans,sum1+sum2);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
