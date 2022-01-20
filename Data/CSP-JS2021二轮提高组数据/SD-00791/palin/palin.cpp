#include<bits/stdc++.h>
#define ri read<int>()

using namespace std;

template <typename T=int>
inline T read()
{
	T x=0,w=1;
	char c=0;
	while(c<'0'||c>'9')
	{
		if(c=='-')
			w=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
template <typename T=int>
inline void write(T x)
{
	if(!x)
		putchar('0');
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	int an[130];
	int tm=0;
	while(x)
	{
		an[tm++]=x%10;
		x/=10;
	}
	while(tm)
	{
		putchar(an[--tm]+'0');
	}
}

int n,t;
int l,r;
const int N=1e6+10;
int a[N];
char ans[N];
int b[N];
int f;
bool check()
{
	int L=1,R=2*n;
	while(L<=R)
	{
		if(b[L]!=b[R])
		return false;
		L++;
		R--;
	}
	return true;
}
void dfs(int t)
{
	if(t>2*n)
	{
		if(check()&&f==0)
		{
			for(int i=1;i<=2*n;i++)
			{
				putchar(ans[i]);
			}
			putchar('\n');
			f=1;
		}
		return;
	}
	b[t]=a[l++];
	ans[t]='L';
	dfs(t+1);
	l--;
	b[t]=a[r--];
	ans[t]='R';
	dfs(t+1);
	r++;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=ri;
	if(t<=10)
	{
		while(t--)
		{
			n=ri;
			f=0;
			memset(b,0,sizeof b);
			for(int i=1;i<=2*n;i++)
			{
				a[i]=ri;
			}
			l=1;
			r=2*n;
			dfs(1);
			if(f==0)
			{
				putchar('-');
				putchar('1');
			}
		}
	}
	else
	{
		n=ri;
		for(int i=1;i<=2*n;i++)
		{
			putchar('L');
		}
		putchar('\n');
	}
	return 0;
}
