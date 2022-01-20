//T3 ±©Á¦ 
#include <iostream>
#include <cstdio>
#define re register
using namespace std;
const int N=5e5+5;

inline int read()
{
	re int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int t,n,a[2*N],b[2*N],c[2*N],last;//1 L 2 R
int front,rear;
bool flag;

bool check()
{
	for(int i=1;i<=n;i++)
	  if(b[i]!=b[2*n+1-i]) return 0;
	return 1;
}
void show()
{
	for(int i=1;i<=2*n;i++)
	  if(c[i]==1) putchar('L');
	  else if(c[i]==2) putchar('R');
	putchar('\n');
} 
void dfs(int t)
{
	if(flag) return;
	if(t>2*n)
	{
		if(check())
		{
			flag=1;
			show();
		}
		return;
	}
	
	c[t]=1;
	b[++last]=a[front++];
	dfs(t+1);
	c[t]=0,last--,front--;
	
	c[t]=2,b[++last]=a[rear--];
	dfs(t+1);
	c[t]=0,last--,rear++;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=2*n;i++) a[i]=read();
		flag=0;
		front=1,rear=2*n;
		dfs(1);
		if(!flag) puts("-1");
	}
	return 0;
}
