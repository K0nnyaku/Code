#include<cstdio>
#include<iostream>
#include<algorithm>
struct node{
	int l,r;
}a[100005],b[100005];
int n,m1,m2,e1[100005],e2[100005],t1=0,t2=0,ans1[100005],ans2[100005],x;
bool cmp(node a,node b){
	return a.l<b.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;++i)scanf("%d%d",&b[i].l,&b[i].r);
	std::sort(a+1,a+m1+1,cmp);
	std::sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m1;++i){
		for(x=1;x<=t1;++x)if(a[i].l>e1[x]){e1[x]=a[i].r,++ans1[x];break;}
		if(x>t1&&t1<=n)e1[++t1]=a[i].r,++ans1[t1];
	}
	for(int i=1;i<=m2;++i){
		for(x=1;x<=t2;++x)if(b[i].l>e2[x]){e2[x]=b[i].r,++ans2[x];break;}
		if(x>t2&&t2<=n)e2[++t2]=b[i].r,++ans2[t2];
	}
	for(int i=1;i<=n;++i)ans1[i]+=ans1[i-1],ans2[i]+=ans2[i-1];
	int maxa=0;
	for(int i=0;i<=n;++i)
		maxa=std::max(maxa,ans1[i]+ans2[n-i]);
	printf("%d\n",maxa);
	return 0;
}
