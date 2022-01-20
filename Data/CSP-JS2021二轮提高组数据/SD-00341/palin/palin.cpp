#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<map>
#define N 10005
using namespace std;
template <class T> void read(T&x)
{
	int w=0;
	x=0;
	char g=getchar();
	while(!isdigit(g))
	{
		w=(g=='-');
		g=getchar();
	}
	while(isdigit(g))
	{
		x=(x<<3)+(x<<1)+(g xor 48);
		g=getchar();
	}
	x=w?-x:x;
	return ;
}
int t,s[N],n,a[N],b[N],tot,head,tail;
char ans[N];
bool flag;
bool check()
{
		tot=2*n;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[tot]) return 0;
			tot--;
		}
		return 1;
}
void dfs(int x)
{
	if(x>2*n){
		if(check())
		flag=1;
		return ;
	}
	for(int i=1;i<3;i++)
	{
		if(flag) return ;
		if(i==1){
		b[x]=a[head++];
		ans[x]='L';
		dfs(x+1);
		head--;
		}
		else
		{
		b[x]=a[tail--];
		ans[x]='R';
		dfs(x+1);
		tail++;
		}
	} 
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		flag=0;
		memset(ans,0,sizeof(ans));
		head=1;tail=2*n;
		for(int i=1;i<=2*n;i++)
		read(a[i]);
		dfs(1);
		if(flag)
		{
			for(int i=1;i<=2*n;i++)
			printf("%c",ans[i]);
		}
		else
		printf("-1");
		printf("\n");
	} 
	return 0;
}

