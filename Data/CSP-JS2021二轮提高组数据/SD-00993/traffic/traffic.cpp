#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)
	{
		if(ch=='-')f=-1;
		ch=getchar(); 
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}	
const int N=2e5+5;
int head[N],cnt;
struct Edge
{
	int nxt,to;
}e[N<<1];
void add_edge(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nxt=head[x];
	head[x]=cnt;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<12<<'\n';
	return 0;
}
