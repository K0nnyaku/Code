#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N=5e3+5;
int n,m1,m2,vis1[N],vis2[N],ans;
struct p{
	int id,tim,op;
} a1[N<<1],a2[N<<1];
bool cmp(p x,p y){
	return x.tim<y.tim;
}
int f(int k){
	int res1=k,res2=n-k,cnt=0;
	for(int i=1;i<=m1*2;++i){
		if(a1[i].op==1){
			if(res1){
				++cnt;
				--res1;
				vis1[a1[i].id]=1;
			}
		}
		else{
			if(vis1[a1[i].id]){
				++res1;
				vis1[a1[i].id]=0;
			}
		}
	}
	for(int i=1;i<=m2*2;++i){
		if(a2[i].op==1){
			if(res2){
				++cnt;
				--res2;
				vis2[a2[i].id]=1;
			}
		}
		else{
			if(vis2[a2[i].id]){
				++res2;
				vis2[a2[i].id]=0;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i) scanf("%d%d",&a1[i].tim,&a1[i+m1].tim),a1[i].id=a1[i+m1].id=i,a1[i].op=1,a1[i+m1].op=-1;
	for(int i=1;i<=m2;++i) scanf("%d%d",&a2[i].tim,&a2[i+m2].tim),a2[i].id=a2[i+m2].id=i,a2[i].op=1,a2[i+m2].op=-1;
	sort(a1+1,a1+m1*2+1,cmp);
	sort(a2+1,a2+m2*2+1,cmp);
	for(int i=0;i<=n;++i) ans=max(ans,f(i));
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
