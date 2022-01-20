#include <iostream>
#include <cstdio>
#include <cstring>
#define INF 1000000007
using namespace std;
char a[505],tryy[505];
int n,k;
long long ans=0,sum=0,maxn;
bool checkk(int x,int y)
{
	for(int i=x+1;i<y;i++) {
		if(tryy[i]=='('||tryy[i]==')') return 0;
	}
	return 1;
}
bool check()
{
	if(tryy[1]=='*'||tryy[n]=='*') return 0;
	bool fuhe[505];
	memset(fuhe,0,sizeof(fuhe));
	int tepsum=0,sumsqukuai=0,sss=0;
	for(int i=1;i<=n;i++) {
		if(tryy[i]=='*')
		{
			tepsum++;
			if(tepsum>k) {
				return 0;
			}
		}else{
			if(((tryy[sss]==')'&&tryy[i]=='(')||(tryy[sss]=='('&&tryy[i]=='(')||(tryy[sss]==')'&&tryy[i]==')'))&&tepsum!=0) {
				sumsqukuai++;
			}
			tepsum=0;
			sss=i;
		}
	}
	int tepa=0,suma=0;
	for(int i=1;i<=n;i++) {
		if(tryy[i]=='(') {
			tepa++;
		}
		if(tryy[i]==')') {
			if(tepa>0) {
				tepa--;
			}else{
				return 0;
			}
		}
	}
	if(tepa!=0) return 0;
	for(int i=1;i<=n;i++) {
		if(tryy[i]=='(') suma++;
	}
	if(sumsqukuai>(suma-1)) {
		return 0;
	}
	return 1;
}
void dfs(int step)
{
	if(step==n+1) {
		sum++;
		if(check()) {
			ans++;
		}
		if(sum>=maxn) return;
	}else{
		if(a[step]=='?') {
			tryy[step]='(';
			dfs(step+1);
			tryy[step]=')';
			dfs(step+1);
			tryy[step]='*';
			dfs(step+1);
			tryy[step]='?';
		}else{
			dfs(step+1);
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	maxn=1;
	for(int i=1;i<=k;i++) maxn*=k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		tryy[i]=a[i];
	}
	if(n%2!=0&&k==0) {
		printf("0\n");
		return 0;
	}
	dfs(1);
	ans=ans%INF;
	printf("%lld\n",ans);
	return 0;
}

