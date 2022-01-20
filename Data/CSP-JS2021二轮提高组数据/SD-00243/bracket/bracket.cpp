#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,k;
string s;
int a[501],jxh,cnt,ans,coo,st;
pair<int,int> lzy[501],zy[501];//µÚfirstÎ»Îªsecond 
bool pd(int js)
{
	st=0;
	for(int i=1;i<=cnt;i++)
	{
		zy[i].first=lzy[i].first;
		zy[i].second=lzy[i].second;
	}
	bool res=1;
	jxh=coo=0;
	int cmp=cnt;
	while(js>0)
	{
		js-=1;
		zy[cnt].second+=1;
		while(zy[cmp].second>=3)
		{
			zy[cmp].second-=3;
			zy[--cmp].second+=1;
		}
		cmp=cnt;
	}
	for(int i=1;i<=cnt;i++)
	{
		a[zy[i].first]=zy[i].second;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) jxh+=1;
		else jxh=0;
		if(a[i]==1) 
		{
			coo+=1;
			st=i;
		}
		else if(a[i]==2) 
		{
			coo-=1;
			if(a[st-1]==0&&a[i+1]==0)
			{
				int u=0;bool pp=0;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]==1) u+=1,pp=1;
					if(a[j]==2) u-=1;
					if(u<-1) 
					{
						res=0;break;
					}
				}
				if(pp==0) res=0;
			}
		}
		if(coo<0||jxh>k) res=0;
	}
	if(coo!=0) res=0;
	for(int i=1;i<=cnt;i++)
	{
		a[zy[i].first]=-1;
	}
	return res;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	memset(a,-1,sizeof a);
	scanf("%d %d\n",&n,&k);
	getline(cin,s);
	if(s[0]=='*'||s[0]==')'||s[n-1]=='*'||s[n-1]=='(')
	{
		printf("0");
		return 0;
	}
	s[0]='(';s[n-1]=')';
	for(int i=0;i<n;i++)
	{
		if(s[i]=='*') jxh+=1;
		else jxh=0;
		if(jxh>k)
		{
			printf("0");
			return 0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(') a[i+1]=1;
		else if(s[i]==')') a[i+1]=2;
		else if(s[i]=='*') a[i+1]=0;
		else if(s[i]=='?') 
		{
			++cnt;
			lzy[cnt].first=i+1;
			lzy[cnt].second=0;
		}
	}
	int m=(int)pow(3,cnt)-1;
	for(int i=0;i<=m;i++)
	{
		if(pd(i)) ans+=1;
	}
	printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
