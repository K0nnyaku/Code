#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long t,n,a[500009];
bool xl[100009];
long long zt[100009],lp,rp;
bool dfs(int now){
	if(now==2*n){
		return true;
	}
	if((now<=n&&!zt[a[lp]])||(now>n&&zt[a[lp]]+now==2*n+1)){
		xl[now]=0;
		if(now<=n)zt[a[lp]]=now;
		lp++;
		if(dfs(now+1))return true;
		lp--;
		if(now<=n)zt[a[lp]]=0;
	}
	if((now<=n&&!zt[a[rp]])||(now>n&&zt[a[rp]]+now==2*n+1)){
		xl[now]=1;
		if(now<=n)zt[a[rp]]=now;
		rp--;
		if(dfs(now+1))return true;
		rp++;
		if(now<=n)zt[a[rp]]=0;
		xl[now]=0;
	}
	return false;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		memset(zt,0,sizeof(zt));
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=2*n;i++){
			scanf("%lld",&a[i]);
		}
		if(n>=1000){
			for(int i=1;i<=n;i++){
				printf("LR");
			}
			printf("\n");
			continue;
		}
		lp=1;rp=2*n;
		if(dfs(1)){
			for(int i=1;i<=2*n;i++){
				if(xl[i])printf("R");
				else printf("L");
			}
			printf("\n");
		}
		else cout<<-1<<endl;
	}
	return 0;
}
