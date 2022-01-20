/*
Author: smyslenny
Title:
Date:2021.10.23
Main idea:
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <map>
#include <vector>

#define ll long long
#define INF 0x3f3f3f3f
#define orz cout<<"LKP AK IOI"

using namespace std;
const int M=5e5+5;
int T,n;
int sz[M];
int read()
{
	int x=0,y=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') y=0;c=getchar();}
	while(isdigit(c)) { x=x*10+(c^48);c=getchar();}
	return y?x:-x;
}
int tmp[M],js,flag;
ll Ans_sum=INF,sum;
int ans[M],Ans[M];
bool check()
{
	int l=1,r=2*n,fg=1,sum=0;
	while(l<=r)
	{
		if(tmp[l]==tmp[r])
			l++,r--;
		else 
		{
			fg=0;
			break;
		}
	}
	if(fg==1) flag=1;
	if(fg==1)
	{
		sum=0;
		for(int i=1;i<=2*n;i++)
			sum=sum*10+ans[i];
	}
	return fg;
}
int L,R;
void dfs(int pos)
{
	if(pos>2*n)
	{
		if(check())
		{
			if(sum<Ans_sum)
			{
				for(int i=1;i<=2*n;i++) 
					Ans[i]=ans[i];
				Ans_sum=sum;
			}
		}
		return;
	}
	ans[++js]=1;
	tmp[pos]=sz[L];
	L++;
	dfs(pos+1);
	L--;
	ans[js]=2;
	tmp[pos]=sz[R];
	R--;
	dfs(pos+1);
	R++;
	js--;
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read(),flag=0,js=0;
		memset(Ans,0,sizeof(Ans));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=2*n;i++) sz[i]=read();
		L=1,R=2*n;
		dfs(1);
		if(!flag) printf("-1\n");
		else 
		{
			for(int i=1;i<=2*n;i++)
				if(Ans[i]==1) printf("L");
				else printf("R");
			printf("\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/


