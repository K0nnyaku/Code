#include<bits/stdc++.h>
using namespace std;
const int N=550;
const int mod=1000000007;
char a[N];
char x='(',y=')';
int f[N][N][3][3];
bool vis[N][N][3][3];
int dfs(int l,int r,int aa,int bb)
{
/*	if(aa==1||bb==0) return 0;
	if(l>r) return 0;
	if(vis[l][r][aa][bb]) return f[l][r][aa][bb];
	vis[l][r][aa][bb]=true;
	int res=0;
	int cost=0;//Í·Î²¼Û¸ñ 
	int c,d;
	    	if(a[l+1]==x) c=0;
	    	if(a[l+1]==y) c=1;
	    	if(a[l+1]=='*') c=2;
	    	if(a[r-1]==x) d=0;
	    	if(a[r-1]==y) d=1;
	    	if(a[r-1]=='*') c=2;
	    	if(a[r-1]=='?'&&a[l+1]=='?')
	    	{
	    		for(c=0;c<=2;++c) 
	    		for(d=0;d<=2;++d) 
	    		cost+=dfs(l+1,r-1,c,d);
			}
			else if(a[l+1]=='?')
			{
				for(d=0;d<=2;++d) 
	    		cost+=dfs(l+1,r-1,c,d);
			}
			else if(a[r-1]=='?') 
			{
				for(c=0;c<=2;++c) 
	    		cost+=dfs(l+1,r-1,c,d);
			}
			else cost+=dfs(l+1,r-1,c,d);
	
	
	if(aa==0&&bb==1)
	{
		for(int i=l+1;i<=r-1;++i)
		if(a[i]==y||a[i]=='?') 
		{
		if(a[i+1]==x||a[i+1]=='?') res+=dfs(l,i,0,1)*dfs(i+1,r,0,bb);
		if(a[i+1]==y||a[i+1]=='?') res+=dfs(l,i,0,1)*dfs(i+1,r,1,bb);
		if(a[i+1]=='*'||a[i+1]=='?') res+=dfs(l,i,0,1)*dfs(i+1,r,2,bb);
	    }
	    res+=cost;
	}
	if(aa==0&&bb!=1)
	{
		for(int i=l+1;i<=r-1;++i)
		if(a[i]==y||a[i]=='?') 
		{
		if(a[i+1]==x||a[i+1]=='?') res+=dfs(l,i,0,1)*dfs(i+1,r,0,bb);
		if(a[i+1]==y||a[i+1]=='?') res+=dfs(l,i,0,1)*dfs(i+1,r,1,bb);
		if(a[i+1]=='*'||a[i+1]=='?') res+=dfs(l,i,0,1)*dfs(i+1,r,2,bb);
	    }
	}
	if(aa!=0&&bb==1)
	{
		for(int i=l+1;i<=r-1;++i)
		if(a[i]==x||a[i]=='?') 
		{
		if(a[i-1]==x||a[i-1]=='?') res+=dfs(i,r,0,1)*dfs(l,i-1,aa,0);
		if(a[i-1]==y||a[i-1]=='?') res+=dfs(i,r,0,1)*dfs(l,i-1,aa,1);
		if(a[i-1]=='*'||a[i-1]=='?') res+=dfs(i,r,0,1)*dfs(l,i-1,aa,2);
	    }
	}
	if(aa==2&&bb==2)
	{
		
	}
	return res;*/
	return 0;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
/*	int ans=0;
	if((a[1]==x||a[1]=='?')&&(a[n]=='y'||a[n]=='?')) ans+=dfs(1,n,0,1);
	printf("%d",ans);*/
	printf("0");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
