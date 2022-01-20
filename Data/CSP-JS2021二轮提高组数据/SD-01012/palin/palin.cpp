#include<bits/stdc++.h>
using namespace std;
int a[100005],c[100005],t,n,flag;
char s[100005];
void check()
{
	int l=1,r=2*n;
	for(int i=1;i<=2*n;i++)
	{
		if(s[i]=='L')c[i]=a[l],l++;
		else c[i]=a[r],r--;
	}
	for(int i=1;i<=2*n;i++)
	{
		if(c[i]!=c[2*n-i+1])return;
	}
	for(int i=1;i<=2*n;i++)printf("%c",s[i]);
	printf("\n");
	flag=1;
}
void dfs(int k)
{
	if(flag)return;
	if(k==2*n+1){check();return;}
	s[k]='L';
	dfs(k+1);
	s[k]='R';
	dfs(k+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		flag=0;
		dfs(1);
	    if(!flag)printf("-1\n");
	}
	return 0;
}
