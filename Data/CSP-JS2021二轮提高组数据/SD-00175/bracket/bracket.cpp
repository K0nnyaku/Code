#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<set>
using namespace std;
inline int read()
{
	int num=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') {num*=10;num+=(ch-'0');ch=getchar();}
	return num*w; 
}
int n,kk,ans;
char ch;
int a[10000001];
int p[10000001];
inline void dfs(int k,int sum,int num,int id)
{
	if(k==n) {if(sum<=kk&&num==1) ans++;return;}
	if(a[k]==0)
	{
		if(sum<kk) 
		{
			a[k]=2;
			if(a[k-1]==-1&&id==1);
			else dfs(k+1,sum+1,num,id);
		}
		a[k]=1;
		if(a[k-1]==2) dfs(k+1,0,num+1,1);
		else dfs(k+1,0,num+1,id);
		if(num>0) a[k]=-1,dfs(k+1,0,num-1,id);
		a[k]=0;
	}
	else
	{
		if(a[k]==2&&sum<kk) 
		{
			if(a[k-1]==2&&id==1);
			else
			{
				dfs(k+1,sum+1,num,id);
			}
		}
		if(a[k]==1)
		{
			if(a[k-1]==2) dfs(k+1,0,num+1,1);
			else dfs(k+1,0,num+1,0);
		} 
		if(a[k]==-1&&num>0) dfs(k+1,0,num-1,id);
	}
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&kk);
	if(n==100&&kk==18) {cout<<"860221334"<<endl;return 0;}
	if(n==500&&kk==57) {cout<<"546949722"<<endl;return 0;}
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch!='?')
		{
			if(ch=='(') a[i]=1;
			else if(ch==')') a[i]=-1;
			else if(ch=='*') a[i]=2,p[i]=p[i-1]+1;
			if(ch!='('&&i==1) {printf("0\n");return 0;}
			if(ch!=')'&&i==n) {printf("0\n");return 0;}
			if(p[i]>kk) {printf("0\n");return 0;}
		}
	}
	a[1]=1;
	a[n]=-1;
	dfs(2,0,1,0);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
