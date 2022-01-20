#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,cnt;
long long ans,f1[100001],f2[100001],pre1[100001],pre2[100001];
struct num{
	int t,val,id;
}x[200001];
bool cmp1(num a,num b){
	return a.val<b.val;
}
struct plane{
	int l,r,id;
}a[200001];
bool cmp2(plane a,plane b){
	return a.l<b.l;
}
int l[200001],r[200001],id[200001],b[200001];
long long k;
bool vis1[200001],vis2[200001];
void init(){
	for(int i=1;i<=2e5;i++){
		b[i]=0;
		id[i]=0;
	}
}
void work1(int x){
	if(vis1[x]){
		return;
	}
	vis1[x]=1;
	if(!b[x]){
		b[x]=++cnt;
	}
	f1[b[x]]++;
	k=id[*lower_bound(l+x+1,l+m1+1,r[x])];
	while(vis1[k]){
		k=id[*lower_bound(l+k+1,l+m1+1,l[k])];
	}
	if(k==0){
		return;
	}
	b[k]=b[x];
	work1(k);
}
void work2(int x){
	if(vis2[x]){
		return;
	}
	vis2[x]=1;
	if(!b[x]){
		b[x]=++cnt;
	}
	f2[b[x]]++;
	k=id[*lower_bound(l+x+1,l+m2+1,r[x])];
	while(vis2[k]){
		k=id[*lower_bound(l+k+1,l+m2+1,l[k])];
	}
	if(k==0){
		return;
	}
	b[k]=b[x];
	work2(k);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&x[(i<<1)-1].val,&x[(i<<1)].val);
		x[(i<<1)-1].id=x[(i<<1)].id=i;
		x[(i<<1)-1].t=1;
		x[(i<<1)].t=2;
	}
	sort(x+1,x+(m1<<1)+1,cmp1);
	for(int i=1;i<=(m1<<1);i++){
		if(x[i].t==1){
			a[x[i].id].l=i;
		}else{
			a[x[i].id].r=i;
		}
	}
	sort(a+1,a+m1+1,cmp2);
	for(int i=1;i<=m1;i++){
		l[i]=a[i].l;
		r[i]=a[i].r;
		id[l[i]]=i;
	}
	cnt=0;
	for(int i=1;i<=m1;i++){
		work1(i);
	}
	for(int i=1;i<=n;i++){
		pre1[i]=pre1[i-1]+f1[i];
	}
	init();
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&x[(i<<1)-1].val,&x[(i<<1)].val);
		x[(i<<1)-1].id=x[(i<<1)].id=i;
		x[(i<<1)-1].t=1;
		x[(i<<1)].t=2;
	}
	sort(x+1,x+(m2<<1)+1,cmp1);
	for(int i=1;i<=(m2<<1);i++){
		if(x[i].t==1){
			a[x[i].id].l=i;
		}else{
			a[x[i].id].r=i;
		}
	}
	sort(a+1,a+m2+1,cmp2);
	for(int i=1;i<=m2;i++){
		l[i]=a[i].l;
		r[i]=a[i].r;
		id[l[i]]=i;
	}
	cnt=0;
	for(int i=1;i<=m2;i++){
		work2(i);
	}
	for(int i=1;i<=n;i++){
		pre2[i]=pre2[i-1]+f2[i];
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,pre1[i]+pre2[n-i]);
	}
	printf("%lld\n",ans);
	return 0;
}
