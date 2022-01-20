#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;

const int N=1e5+50;
int n,k,tmp;
int now[N];
char ch[N];
int ans;

int check()
{
	int lcnt=0,rcnt=0;
	for(int i=1;i<=n;i++) 
		if(ch[i]=='(') lcnt++;
		else if(ch[i]==')') rcnt++;
	for(int i=1;i<=tmp;i++)
	if(now[i]==1) lcnt++;
	else if(now[i]==2) rcnt++;
	if(lcnt!=rcnt) return 0;
	int nowtmp=0;
	char nowch[N];
	for(int i=1;i<=n;i++) 
	if(ch[i]=='('||ch[i]==')'||ch[i]=='*') nowch[i]=ch[i];
	else 
	{
		nowtmp++;
		if(now[nowtmp]==0)
		nowch[i]='*';
		else if(now[nowtmp]==1)
		nowch[i]='(';
		else nowch[i]=')';
	}
	int CN=0,LC=0;
	for(int i=1;i<=n;i++)
	{
		if(nowch[i]!='*') CN=0;
		else CN++;
		if(CN>k) return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(nowch[i]=='(') LC++;
		else if(nowch[i]==')') LC--;
		if(LC<0) return 0;
	} 
	if(nowch[n]=='*'||nowch[1]=='*') return 0;
	//for(int i=1;i<=n;i++) 
//	cout<<nowch[i];
//	puts("");
	return 1;
}

void dfs(int i)
{
	if(i==tmp+1)
	{
		ans+=check();
		return;
	}
	for(int j=0;j<3;j++)
	{
		now[i]=j;
		dfs(i+1);
	}
}


int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++) if(ch[i]=='?') tmp++;
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
