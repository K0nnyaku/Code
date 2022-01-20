#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n;
int ansl[2010];
int a[2010],b[2010];
bool num[1010];
bool flag=false;
bool ch()
{
	for(int i=1,j=2*n;i<=n,j>=1+n;i++,j--) 
	{
		if(b[i]!=b[j]) return false;
	}
	return true;
}
void dfs(int k,int st,int fn)
{
	if(flag) return;
	if(k==2*n+1)
	{
		if(ch())
		{
			flag=true;
			for(int i=1;i<=2*n;i++)
			{
				if(ansl[i]==1) cout<<"L";
				else if(ansl[i]==2) cout<<"R";
			}
			cout<<endl;
		}
		return;
	}
	
	
	
	if(k<=n)
	{
		//st
		if(!num[a[st]])
		{
			num[a[st]]=true;
			b[k]=a[st];
			ansl[k]=1;
			dfs(k+1,st+1,fn);
			num[a[st]]=false;
		 } 
		//fn
		if(!num[a[fn]])
		{
			num[a[fn]]=true;
			b[k]=a[fn];
			ansl[k]=2;
			dfs(k+1,st,fn-1);
			num[a[fn]]=false;
		}
	}
	
	if(k>n)
	{
		//st
		if(num[a[st]]&&b[2*n-k+1]==a[st])
		{
			b[k]=a[st];
			ansl[k]=1;
			dfs(k+1,st+1,fn);
		}
		//fn
		if(num[a[fn]]&&b[2*n-k+1]==a[fn])
		{
			b[k]=a[fn];
			ansl[k]=2;
			dfs(k+1,st,fn-1);
		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);

	cin>>T;
	while(T--){
		memset(b,0,sizeof(b));
		memset(num,false,sizeof(num));
		cin>>n;
		for(int i=1;i<=2*n;i++) cin>>a[i];
		dfs(1,1,2*n);
		if(!flag) cout<<-1<<endl;
		flag=false;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


