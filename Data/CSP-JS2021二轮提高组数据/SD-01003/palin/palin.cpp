#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

const int N=100;
int num[N];
//bool isin[N];
int du[N];
bool st[N];
int n;
int T;
bool findxx;
bool way[N];
int l,r,idx;

bool ispalin()
{
	for(int i=0;i<n;i++)
	if(du[i]!=du[n*2-i-1])return false;
	return true;
}


void dfs(int i)
{
	//cout<<n<<"  ";
	if(findxx == 1)return;
	if(i==n*2){
		
		if(ispalin())
		{
			findxx=1;
			return ;
		}
		return ;
	}
	
	way[idx]=0;
	du[idx++]=num[l++];
	dfs(i+1);
	if(findxx == 1)return;
	idx--;l--;
	
	way[idx]=1;
	du[idx++]=num[r--];
	dfs(i+1);
	if(findxx == 1)return;
	idx--;r++;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		
		scanf("%d",&n);
		for(int i=0;i<n*2;i++)
		{
			scanf("%d",&num[i]);
		}
		l=0;r=n*2-1;idx=0;
		findxx=false;
		
		dfs(0);
		
		if(findxx)
		for(int i=0;i<n*2;i++)
		{
			if(way[i])printf("R");
			else printf("L");
		}
		else printf("-1");
		puts("");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/* 2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
