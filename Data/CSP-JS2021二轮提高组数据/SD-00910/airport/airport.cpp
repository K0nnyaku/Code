#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define N 10005
using namespace std;
int n,m1,m2,ans=0,cnt=0,f1[N],f2[N],cnt1=0,cnt2=0;
struct node{
	int x,y;
};
node a1[N],a2[N];
bool cmp(node a,node b){
	return a.x<b.x;
}
int dfs(int x,int y){
	memset(f1,0,sizeof(f1));
	memset(f2,0,sizeof(f2));
	cnt1=0;
	cnt2=0;
	for(int i=1;i<=m1;i++){
		for(int j=1;j<=x;j++){
				if(f1[j]<=a1[i].x){
					f1[j]=a1[i].y;
					cnt1++; 
					break;
			}
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=1;j<=y;j++){
			if(f2[j]<=a2[i].x){
				f2[j]=a2[i].y;
				cnt2++; 
				break;
			}
		}
	}
	int l=cnt1+cnt2;
	return l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a1[i].x,&a1[i].y);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&a2[i].x,&a2[i].y);
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp); 
	for(int i=0;i<=n;i++){
		ans=max(ans,dfs(i,n-i));
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
