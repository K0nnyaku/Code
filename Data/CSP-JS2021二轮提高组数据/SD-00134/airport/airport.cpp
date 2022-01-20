#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAX 100010

using namespace std;

int n,m1,m2,ans;
int s1[MAX],s2[MAX],sum1[MAX],sum2[MAX];
int vis1[MAX],vis2[MAX];

struct node1{
	int start,end;
}arr1[MAX];
struct node2{
	int start,end;
}arr2[MAX];

bool cmp1(node1 a,node1 b){
	return a.start<b.start;
}
bool cmp2(node2 a,node2 b){
	return a.start<b.start;
}
int min(int a,int b){
	return a < b ? a : b;
}
int max(int a,int b){
	return a > b ? a : b;
}
void ef2(int x){
	
}
void dfs1(int x,int a){
	int q=arr1[a].end;
	for(int i=a+1;i<=m1;i++){
		if(arr1[m1].start<q) break;
		if(arr1[i].start>=q&&!vis1[i]){
			vis1[i]=1;
			s1[x]++;
			q=arr1[i].end;
		}
	}
	return ;
}
void dfs2(int x,int a){
	int q=arr2[a].end;
	for(int i=a+1;i<=m2;i++){
		if(arr2[m2].start<q) break;
		if(arr2[i].start>=q&&!vis2[i]){
			vis2[i]=1;
			s2[x]++;
			q=arr2[i].end;
		}
	}
	return ;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&arr1[i].start,&arr1[i].end);
	for(int i=1;i<=m2;i++) scanf("%d%d",&arr2[i].start,&arr2[i].end);
	sort(arr1+1,arr1+1+m1,cmp1);
	sort(arr2+1,arr2+1+m2,cmp2);
	int t1=1,t2=1;
	for(int i=1;i<=m1&&t1<=n;i++){
		if(!vis1[i]) {
			vis1[i]=1;
			s1[t1]++;
			dfs1(t1,i);
			t1++;
		}
	}
	for(int i=1;i<=m2&&t2<=n;i++){
		if(!vis2[i]) {
			vis2[i]=1;
			s2[t2]++;
			dfs2(t2,i);
			t2++;
		}
	}
	t1--,t2--;
	for(int i=1;i<=t1;i++) sum1[i]=s1[i]+sum1[i-1];
	for(int i=1;i<=t2;i++) sum2[i]=s2[i]+sum2[i-1];
	for(int i=0;i<=n;i++) ans=max(ans,sum1[i]+sum2[n-i]);
	printf("%d",ans);
	return 0;
}
