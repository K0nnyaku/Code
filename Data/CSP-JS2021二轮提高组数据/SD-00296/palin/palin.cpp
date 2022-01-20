#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
#include<stack>
using namespace std;
long long quickpower(int a,int b)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)	ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;
}
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int n,a[3001],T,head,tail;
bool b,d;
deque<int>q;
deque<int>p;
bool pd()
{
	deque<int>qu=q;
	int b[3001]= {0},t=1;
	while(!qu.empty())
	{
		b[t++]=qu.front();
		qu.pop_front();
	}
	for(int i=1; i<=n; i++)
		if(b[i]!=b[2*n+1-i])
			return 0;
	return 1;
}
bool vis[100000][2];
void print() 
{
	deque<int>qu=q;
	int b[3001]= {0},t=0;
	while(!qu.empty())
	{
		b[t++]=qu.front();
		qu.pop_front();
	}
	for(int i=0; i<2*n; i++)
		cout<<b[i]<<' ';
	cout<<endl;
}
void dfs(int x,int y)
{
	d=0;
	if(x>=2*n&&pd()&&!b)
	{
		while(!p.empty())
		{
			if(p.front()==1)
				printf("L");
			else
				printf("R");
			p.pop_front();
		}
		printf("\n");
		b=1;
		d=1;
		return;
	}
	if(x>=2*n||vis[x][y]||head>tail)
	{
		d=1;
		return ;
	}
	for(int i=x;i<2*n;i++)
	{
		if(y==1)
		{
			vis[x][y]=1;
			q.push_back(a[head]);
			head++;
			p.push_back(1);
		}
		else
		{
			vis[x][y]=1;
			q.push_back(a[tail]);
			tail--;
			p.push_back(0);
		}
		dfs(x+1,1);
		if(!d)
		{
			q.pop_back();
			p.pop_back();
			head--;
		}
		dfs(x+1,0);
		if(!d)
		{
			q.pop_back();
			p.pop_back();
			tail++;
		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0; i<2*n; i++)
			scanf("%d",&a[i]);
		head=0,tail=2*n-1;
		dfs(0,1);
		if(!b)
			dfs(0,0);
		if(!b)
			printf("-1\n");
		n=0;
		while(!p.empty())
			p.pop_front();
		while(!q.empty())
			q.pop_front();
		for(int i=0; i<2*n; i++)
			a[i]=0;
		b=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

