#include<bits/stdc++.h>
using namespace std;
const int N=100011;
int n,m1,m2,ans;
struct Node{
	int st,ed;
}air_1[N],air_2[N];
bool cmp(Node a,Node b){
	if(a.st==b.st){
		return a.ed<b.ed;
	}
	return a.st<b.st;
}
struct Heap{
	int sum,now_ed,f;//f 按生成顺序排 
}h[N],h2[N],h3[N],h4[N];//当前有几个区间 
int nheap,nheap2;
bool cmp2(Heap a,Heap b){
	if(a.now_ed==b.now_ed){
		return a.sum<b.sum;
	}
	return a.now_ed>b.now_ed;
}
bool cmp3(Heap a,Heap b){
	return a.sum<b.sum;
}
int as1[N],as2[N];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&air_1[i].st,&air_1[i].ed);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&air_2[i].st,&air_2[i].ed);
	}
	sort(air_1+1,air_1+1+m1,cmp);
	sort(air_2+1,air_2+1+m2,cmp);
	for(int i=1;i<=m1;i++){
		if(nheap==0||air_1[i].st<h[1].now_ed){
			h[++nheap].sum=1;
			h[nheap].now_ed=air_1[i].ed;
			h[nheap].f=nheap;
			push_heap(h+1,h+1+nheap,cmp2);
		}
		else{
			Heap linshi=h[1]; 
			pop_heap(h+1,h+1+nheap,cmp2);
			h[nheap]=linshi;
			h[nheap].sum++;
			h[nheap].now_ed=air_1[i].ed;
			push_heap(h+1,h+1+nheap,cmp2);
		}
	}
	for(int i=1;i<=m2;i++){
		if(nheap2==0||air_2[i].st<h2[1].now_ed){
			h2[++nheap2].sum=1;
			h2[nheap2].now_ed=air_2[i].ed;
			h2[nheap2].f=nheap2;
			push_heap(h2+1,h2+1+nheap2,cmp2);
		}
		else{
			Heap linshi=h2[1]; 
			pop_heap(h2+1,h2+1+nheap2,cmp2);
			h2[nheap2]=linshi;
			h2[nheap2].sum++;
			h2[nheap2].now_ed=air_2[i].ed;
			push_heap(h2+1,h2+1+nheap2,cmp2);
		}
	}
	for(int i=1;i<=nheap;i++){
		h3[h[i].f]=h[i];
	}
	for(int i=1;i<=nheap2;i++){
		h4[h2[i].f]=h2[i];
	}
	for(int i=1;i<=nheap;i++){
		as1[i]=as1[i-1]+h3[i].sum;
	}
	for(int i=1;i<=nheap2;i++){
		as2[i]=as2[i-1]+h4[i].sum;
	}
//	for(int i=1;i<=nheap;i++){
//		printf("%d ",h3[i].sum);
//	}
//	printf("\n");
//	for(int i=1;i<=nheap;i++){
//		printf("%d ",as1[i]);
//	}
//	printf("\n");
//	for(int i=1;i<=nheap2;i++){
//		printf("%d ",h4[i].sum);
//	}
//	printf("\n");
//	for(int i=1;i<=nheap2;i++){
//		printf("%d ",as2[i]);
//	}
//	printf("\n");
	for(int i=0;i<=n;i++){
		ans=max(ans,as1[i]+as2[n-i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
