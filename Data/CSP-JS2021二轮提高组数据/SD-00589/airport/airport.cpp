#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
int q1[maxn],q2[maxn];
struct node{
	int l,r;
}a[maxn],b[maxn];
bool cmp(node x,node y){
	return x.l<y.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,tot1,tot2,top1,top2;
	int ans,maxx=0;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+m1+1,cmp);
	for(int i=1;i<=m2;++i)
		scanf("%d%d",&b[i].l,&b[i].r);
	sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;++i){
		int x=i,y=n-i;
		ans=0,tot1=0,tot2=0,top1=1,top2=1;
		if(x!=0){
			if(x>=m1) ans+=m1;
			else{
				for(int i=1;i<=x;++i){
					q1[++tot1]=a[i].r;
					ans++;
				}
				sort(q1+top1,q1+tot1+1);
				for(int i=x+1;i<=m1;++i){
					if(a[i].l>=q1[top1]){
						ans++;
						top1++;
						q1[++tot1]=a[i].r;
						sort(q1+top1,q1+tot1+1);
					}
				}
			}
		}
		if(y!=0){
			if(y>=m2) ans+=m2;
			else{
				for(int i=1;i<=y;++i){
					q2[++tot2]=b[i].r;
					ans++;
				}
				sort(q2+top2,q2+tot2+1);
				for(int i=y+1;i<=m2;++i){
					if(b[i].l>=q2[top2]){
						ans++;
						top2++;
						q2[++tot2]=b[i].r;
						sort(q2+top2,q2+tot2+1);
					}
				}
			}
		}
		maxx=max(maxx,ans);
	}
	printf("%d",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
