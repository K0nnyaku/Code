#include<iostream>
#include<cstdio>
using namespace std;
const int N = 5e5+10;
int T,a[N*2],n,flag,b[N*2];
int cho[N*2];
bool judge(int l,int r){
	int nowl=l;int nowr=r;
	int gs=n;
	for(int i=n;i>=1;i--){
		int pan=b[2*n-i+1];
		if(a[nowl]==pan){
			cho[++gs]=0;
			nowl++;
		}
		else if(a[nowr]==pan){
			cho[++gs]=1;
			nowr--;
		}
		else if(a[nowl]!=pan&&a[nowr]!=pan) return false;
	}
	return true;
}
void dfs(int dep,int l,int r){
	if(dep==n){
		if(judge(l,r)==true){
			flag=1;
			for(int i=1;i<=2*n;i++){
				if(cho[i]==0) printf("L");
				else printf("R");
			}
			printf("\n");
		}
		return;
	}
	if(flag) return;
	cho[dep+1]=0;
	b[2*n-dep]=a[l];
	dfs(dep+1,l+1,r);
	if(flag) return;
	cho[dep+1]=1;
	b[2*n-dep]=a[r];
	dfs(dep+1,l,r-1);
	if(flag) return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
		scanf("%d",&a[i]);
		dfs(0,1,2*n);
		if(!flag) printf("-1\n");
	}
	return 0;
}
