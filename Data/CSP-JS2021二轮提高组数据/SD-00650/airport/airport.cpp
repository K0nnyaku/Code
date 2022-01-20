#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int n,m1,m2,ans=-1;
int a[N];
struct node{
	int l,r;
}inter[N],outer[N];
bool cmp(node a,node b){
	return a.l<b.l;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d %d",&inter[i].l,&inter[i].r);
	for(int i=1;i<=m2;i++) scanf("%d %d",&outer[i].l,&outer[i].r);
	sort(inter+1,inter+m1+1,cmp);
	sort(outer+1,outer+m2+1,cmp);
	for(int i=0;i<=n;i++){
		int t=0;
		for(int j=1;j<=m1;j++){
			if(!i) break;
			for(int k=1;k<=i;k++){
				if(inter[j].l>a[k]){
					a[k]=inter[j].r;
					t++;
					break;
				}
			}
		}
		if(t+m2<=ans) continue;
		memset(a,0,sizeof a);
		for(int j=1;j<=m2;j++){
			if(!(n-i)) break;
			for(int k=1;k<=n-i;k++){
				if(outer[j].l>a[k]){
					a[k]=outer[j].r;
					t++;
					break;
				}
			}
		}
		ans=max(ans,t);
		memset(a,0,sizeof a);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
