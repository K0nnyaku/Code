#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;
int a[1000010],T,n,head,tail;
stack<int> b,ansb,text;
char ans[1000010];
bool book[1000010];
bool check()
{
	for(int i=1;i<=n;i++)
	{
		ansb.push(b.top());
		text.push(b.top());
		b.pop(); 
	}
	for(int i=1;i<=n;i++)
	{
		if(b.top()==ansb.top())
		{
			ansb.pop();
			text.push(b.top());
			b.pop();
		}
		else
		{
			while(!text.empty())
			{
				b.push(text.top());
				text.pop();
			}
			return 0;
		}
	}
	return 1;
}
bool dfs(int i)
{
	if(i>n)
	{
		for(int i=1;i<=n;i++)
		{
		
			if(book[i]==0)
			{
//				printf("%d\n",i);		
				return 0;
			}
		}
	}
	if(i>2*n)
	{
		if(check())
		{
			for(int j=1;j<=2*n;j++)
			{
				printf("%c",ans[j]);
			}
			printf("\n");
			return 1;
		}
		else
		{
			return 0;
		}
	}
	b.push(a[head]);
	head++;
	ans[i]='L';
	if(book[a[head-1]]!=1&&i<=n)
	{
		book[a[head-1]]=1;
		if(dfs(i+1))
		{
			book[a[head-1]]=0;
			return 1;
		}
		book[a[head-1]]=0;
	}
	else
	{
		if(dfs(i+1))
		{
			return 1;
		}
	}
	b.pop();
	head--;
	b.push(a[tail-1]);
	tail--;
	ans[i]='R';
	if(book[a[tail]]!=1&&i<=n)
	{
		book[a[tail]]=1;
		if(dfs(i+1))
		{
			book[a[tail]]=0;
			return 1;
		}
		book[a[tail]]=0;
	}
	else
	{
		if(dfs(i+1))
		{
			return 1;
		}
	}
	b.pop();
	tail++;
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		head=1;
		tail=2*n+1;
		if(!dfs(1))
		{
			printf("-1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

