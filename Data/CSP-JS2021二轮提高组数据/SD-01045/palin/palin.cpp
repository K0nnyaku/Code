#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
using namespace std;
inline int read()
{
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
int T,n,a[1000010],book[210],qwq[210],endflag;
stack<int> st;
bool check()
{
	memset(qwq,0,sizeof(qwq));
	int lp=1,rp=2*n;
	for(int i=1;i<=n;i++)
		if(book[i]==0)
		{
			qwq[i]=a[lp];
			lp++;
		}
		else
		{
			qwq[i]=a[rp];
			rp--;
		}
	for(int i=n;i>=1;i--)
	{
		if(a[lp]!=qwq[i]&&a[rp]!=qwq[i])return 0;
		if(a[lp]==qwq[i])lp++;
		if(a[rp]==qwq[i])rp--;
	}
	return 1;
}
void dfs(int xx)
{
	if(xx>n)
	{
		if(check())
		{
			endflag=1;
			for(int i=1;i<=n;i++)
				if(book[i]==0)
					printf("L");
				else
					printf("R");
			int lp=1,rp=2*n;
			for(int i=1;i<=n;i++)
				if(book[i]==0)lp++;
				else rp--;
			for(int i=n;i>=1;i--)
				if(a[lp]==qwq[i])
				{
					printf("L");
					lp++;
				}
				else
				{
					printf("R");
					rp--;
				}
			printf("\n");
		}
		return;
	}
	dfs(xx+1);
	if(endflag)return;
	book[xx]=1;
	dfs(xx+1);
	book[xx]=0;
	if(endflag)return;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	for(int qwerty=1;qwerty<=T;qwerty++)
	{
		n=read();
		for(int i=1;i<=2*n;i++)a[i]=read();
		if(n>=100)
		{
			int palincnt=0,mid=0;
			while(!st.empty())st.pop();
			for(int i=1;i<=2*n;i++)
				if(!st.empty()&&a[i]==st.top())
				{
					st.pop();
					if(st.empty())
					{
						if(mid==0)mid=i;
						palincnt++;
						if(palincnt>2)
						{
							printf("-1\n");
							endflag=1;
							break;
						}
					}
				}
				else st.push(a[i]);
			if(!endflag)
			{
				if(!st.empty())
				{
					printf("-1\n");
					continue;
				}
				for(int i=1;i<=mid/2;i++)printf("L");
				for(int i=1;i<=2*n-mid;i++)printf("R");
				for(int i=1;i<=mid/2;i++)printf("L");
				printf("\n");
			}
		}
		else
		{
			endflag=0;
			memset(book,0,sizeof(book));
			dfs(1);
			if(!endflag)printf("-1\n");
		}
	}
	return 0;
}
