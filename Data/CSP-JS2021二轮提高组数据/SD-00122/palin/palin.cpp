#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int t;
int n,a[100005],nn;
int b[100005],c[100005],sum;
char s[100005],ss[100005];
int head,tail;

int bj(char x[],char y[])
{
	int s=0;
	for(int i=0;i<nn;i++)
	{
		if(x[i]>y[i])
			return 0;
	}
	return 1;
}//比较字典序 

int h(int x[])
{
	for(int i=0;i<=nn/2;i++)
	{
		if(x[i]!=x[nn-i-1])
			return 0;
	}
	return 1;
}//判断回文数 

void dfs(int x,char y)
{
	if(y=='L')
		head++;
	else
		tail--;
	if(head==tail+2&&sum==0)
	{
		if(h(b)==1)
		{
			for(int i=0;i<nn;i++)
			{
				ss[i]=s[i];
				c[i]=b[i];
			}
			sum=1;
		}
		return;
	}
	if(head==tail+2&&sum!=0)
	{
		if(h(b)==1&&bj(s,ss)==1)
		{
			for(int i=0;i<nn;i++)
			{
				ss[i]=s[i];
				c[i]=b[i];
			}
		}
		return;
	}
	if(y=='L')
	{
		b[x]=a[head-1];
	}
	if(y=='R')
	{
		b[x]=a[tail+1];
	}
	s[x]=y;
	dfs(x+1,'L');
	head--;
	dfs(x+1,'R');
	tail++;
}//搜索寻找所有可能情况
 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;//t组数据 
	while(t--)
	{
		cin>>n;
		nn=2*n;
		head=0;
		tail=2*n-1;
		for(int i=0;i<nn;i++)
			c[i]=-1;
		for(int i=0;i<nn;i++)
			cin>>a[i];
		//输入 
		dfs(0,'L');
		dfs(0,'R');
		//搜索 
		if(c[0]==-1)
		{
			cout<<-1<<endl;
			continue;
		}
		//特判不可能出现回文数的情况 
		for(int i=0;i<nn;i++)
	 		cout<<ss[i];
	 	cout<<endl;
	 	//输出 
	}
	return 0;
}
