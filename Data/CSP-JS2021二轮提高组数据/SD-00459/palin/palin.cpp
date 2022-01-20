#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int n,a[1003],b[1003],ans[1003],ak[1003],n2;
bool flag;

void check(int l,int r){
	for(int i=1; i<=n; ++i)
	{
		if(a[l]==b[n+1-i]) {ans[n+i]=1; ++l;}
		else if(a[r]==b[n+1-i]) {ans[n+i]=2; --r;}
		else return ;
	}
	flag=1;
	for(int i=1; i<=n2; ++i)
		ak[i]=ans[i];
	return ;
}

void dfs(int l,int r,int op)
{
	if(flag) return ;
	if(op==n+1){
		check(l,r);
		return ;
	}
	ans[op]=1; b[op]=a[l]; dfs(l+1,r,op+1);
	ans[op]=2; b[op]=a[r]; dfs(l,r-1,op+1);
}

bool isspa()
{
	for(int i=1; i<=n; ++i)
		if(a[i]!=a[n2+1-i]) return 0;
	return 1;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		n2=n*2;
		for(int i=1; i<=n2; ++i)
			scanf("%d",&a[i]);
		
		if(isspa())
		{
			for(int i=1; i<=n; ++i) printf("L");
			for(int i=1; i<=n; ++i) printf("R");
			cout<<endl;
			continue;
		}	
		
		memset(ans,0,sizeof(ans));
		flag=0;
		
		dfs(1,n2,1);
		
		if(flag){
			for(int i=1; i<=n2; ++i)
				if(ak[i]==1) printf("L");
				else printf("R");
		}
		else cout<<-1;
		cout<<endl;
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
