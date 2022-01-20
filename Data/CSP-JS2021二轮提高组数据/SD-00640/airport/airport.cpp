#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
inline long long r_ll(){
	long long f=1,x=0;int c;
	do{c=getchar();if(c=='-')f=-1;}while((c<'0'||c>'9')&&c!=EOF);
	do{x=(x<<3)+(x<<1)+c-'0',c=getchar();}while(c>='0'&&c<='9');
	return f*x;
}
int n,m1,m2;
bool bb1,bb2;
struct SEG{
	int l;
	int r;
	inline friend bool operator< (const SEG &x,const SEG &y){
		return x.l<y.l;
	}
};
int ans;
SEG seg1[100010],seg2[100010];
int po1[100010],po2[100010];
void fr1(int x){
	int ccf=0;int la;
	for(int i=1;i<=m1;i++){
		if(!po1[i]){
		ccf=i,la=seg1[i].r;
		break;
		}
	}
	if(!ccf){
		bb1=1;
		return;
	}
	for(int i=ccf;i<=m1;i++){
		if(po1[i]) continue;
		if(i==ccf||!po1[i]&&la<=seg1[i].l){
			po1[i]=x;la=seg1[i].r;
		}
	}
	return;
}
void fr2(int x){
	int ccf=0;int la;
	for(int i=1;i<=m2;i++){
		if(!po2[i]){
		ccf=i,la=seg2[i].r;
		break;
		}
	}
	if(!ccf){
		bb2=1;
		return;
	}
	for(int i=ccf;i<=m2;i++){
		if(po2[i]) continue;
		if(i==ccf||!po2[i]&&la<seg2[i].l){
			po2[i]=x;la=seg2[i].r;
		}
	}
	return;
}
int tot1[100010],tot2[100010];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=r_ll(),m1=r_ll(),m2=r_ll();
	for(int i=1;i<=m1;i++){
		seg1[i].l=r_ll(),seg1[i].r=r_ll();
	}
	for(int i=1;i<=m2;i++){
		seg2[i].l=r_ll(),seg2[i].r=r_ll();
	}
	sort(seg1+1,seg1+1+m1);
	sort(seg2+1,seg2+1+m2);
	for(int i=1;i<=n;i++){
		if(bb1) break;
		fr1(i);
	}
	for(int i=1;i<=n;i++){
		if(bb2) break;
		fr2(i);
	}
	for(int i=1;i<=m1;i++){
		if(po1[i]){
			tot1[po1[i]]++;
		}
	}
	for(int i=1;i<=m2;i++){
		if(po2[i]){
			tot2[po2[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		tot1[i]+=tot1[i-1];
	}
	for(int i=1;i<=n;i++){
		tot2[i]+=tot2[i-1];
	}
	for(int i=0;i<=n;i++){
		tot1[i]+=tot2[n-i];
		ans=max(ans,tot1[i]);
	}
	printf("%d",ans);
	return 0;
}
