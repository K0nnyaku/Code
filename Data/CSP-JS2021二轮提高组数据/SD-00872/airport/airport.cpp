#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define INF 0x7fffffff
using namespace std;
int n,m1,m2,ans1[100010],ans2[100010],ans,use[100010],use1[100010],t;
struct plane{
	int a,b;
}china[100010],usa[100010];
bool cmp(plane x,plane y){
	return x.a<y.a;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&china[i].a,&china[i].b);
	}
	sort(china+1,china+1+m1,cmp);
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=1;j<=m1;j++){
			if(use[j]) continue;
			if(t==0){
				++ans1[i];
				t=china[j].b;
				use[j]=1;
			}
			else{
				if(china[j].a>t){
					++ans1[i];t=china[j].b;
					use[j]=1;
				}
			}
		}
		if(t==0) break;
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&usa[i].a,&usa[i].b);
	}
	sort(usa+1,usa+1+m2,cmp);
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=1;j<=m2;j++){
			if(use1[j]) continue;
			if(t==0){
				++ans2[i];
				t=usa[j].b;
				use1[j]=1;
			}
			else{
				if(usa[j].a>t){
					++ans2[i];t=usa[j].b;
					use1[j]=1;
				}
			}
		}
		if(t==0) break;
	}
	for(int i=2;i<=n;i++){
		ans1[i]+=ans1[i-1];
		ans2[i]+=ans2[i-1];
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,ans1[i]+ans2[n-i]);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
