#include<bits/stdc++.h>
using namespace std;
#define N 100006
#define ll long long
struct node{
	int l,r;
}a[N],b[N];
bool cmp(node a,node b){
	return a.l<b.l;
}
int ta[N],tb[N],las1[N],las2[N];
int n,m1,m2,ans,maa=1,mab=1; 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		a[i].l=l,a[i].r=r;
	}
	for(int i=1;i<=m2;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		b[i].l=l,b[i].r=r;
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	ta[1]=1;tb[1]=1;
	las1[1]=1,las2[1]=1;
	for(int i=2;i<=m1;i++){
		for(int j=1;j<=m1;j++){
			if(las1[j]==0){
				ta[j]++;
				maa=j;
				las1[j]=i;
				break;
			}
			if(a[las1[j]].r<a[i].l){
				ta[j]++;
				las1[j]=i;
				break;
			}
		}
	}
	for(int i=2;i<=m2;i++){
		for(int j=1;j<=m2;j++){
			if(las2[j]==0){
				las2[j]=i;
				tb[j]++;
				mab=j;
				break;
			}
			if(b[las2[j]].r<b[i].l){
				tb[j]++;
				las2[j]=i;
				break;
			}
		}
	}
	int m=min(n,max(maa,mab));
	for(int i=1;i<=m;i++)
		ta[i]+=ta[i-1];
	for(int i=1;i<=m;i++)
		tb[i]+=tb[i-1];
	if(maa+mab<=n) printf("%d",ta[maa]+tb[mab]);
	else {
		for(int i=m;i>=0;i--){
			int t1=i,t2=n-i;
			ans=max(ans,ta[t1]+tb[t2]); 
		}
		printf("%d",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
