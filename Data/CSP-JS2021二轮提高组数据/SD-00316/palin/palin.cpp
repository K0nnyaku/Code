#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath> 

using namespace std;

const int N=5e4+10;
int a[N],n,ans[N];
int sm[N],t,f[N];

void print()
{
	for(int i=1;i<=2*n;i++)
		if(ans[i]==1) printf("L");
		else printf("R");
	printf("\n");
}

void dfs(int x,int lc,int rc)
{
	if(t==1) return;
	if(x==2*n+1){t=1;print();return;}
	
	bool flag=true;
	sm[a[lc]]++;f[x]=a[lc];ans[x]=1;
	if(x<=n && sm[a[lc]]>1) {sm[a[lc]]--;flag=false;} 
	if(x>n && f[x]!=f[2*n+1-x]) {sm[a[lc]]--;flag=false;}
	if(flag) dfs(x+1,lc+1,rc),sm[a[lc]]--;
	
	if(t==1) return;
	flag=true;
	sm[a[rc]]++;f[x]=a[rc];ans[x]=2;
	if(x<=n && sm[a[rc]]>1) {sm[a[rc]]--;flag=false;}
	if(x>n && f[x]!=f[2*n+1-x]) {sm[a[rc]]--;return;}
	dfs(x+1,lc,rc-1),sm[a[lc]]--;
}

void work()
{
	memset(sm,0,sizeof(sm));t=0;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
	dfs(1,1,2*n);
	if(t==0) printf("-1\n");
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);	
	int t;scanf("%d",&t);
	while(t--) work();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
