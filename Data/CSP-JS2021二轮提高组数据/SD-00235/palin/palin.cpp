#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int a[10000],la,fi,b[50000],n;
bool mark[500000]={},flag;
char ans[10000]={};
int check(int f,int l)
{
	int tmp=n;
	while(tmp>0)
	{
		if(a[f]==b[tmp])
		{
			ans[2*n-tmp]='L';
			tmp--;
			f++;
		}
		else if(a[l]==b[tmp])
		{
			ans[2*n-tmp]='R';
			tmp--;
			l--;
		}
		else break;
	}
	if(tmp<=0) return 1;
	else return 0;
}
void dfs(int k)
{
	int q=0;
	if(flag==1)return;
	if(k==n+1)
	{
		if(check(fi,la)==1)
		{
			flag=1;	
			while(ans[q]=='L'||ans[q]=='R')cout<<ans[q++];
			cout<<endl;
			for(int i=0;i<=5000;i++)ans[i]=1;
			return;
		}
		return;
	}
	if(mark[a[fi]]==0)
	{
		mark[a[fi]]=1;
		b[k]=a[fi];
		fi++;
		ans[k-1]='L';
		dfs(k+1);
		fi--;
		mark[a[fi]]=0;
	}
	if(mark[a[la]]==0)
	{
		mark[a[la]]=1;
		b[k]=a[la];
		la--;
		ans[k-1]='R';
		dfs(k+1);
		la++;
		mark[a[la]]=0;
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,i;
	bool f;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=2*n;i++)
		{
			cin>>a[i];
		}
		fi=1;la=2*n;flag=0;
		dfs(1);
		if(flag==0)cout<<"-1"<<endl;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
