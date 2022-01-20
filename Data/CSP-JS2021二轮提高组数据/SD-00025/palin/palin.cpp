#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
const int N = 1e5 + 9;
const int M = 1e5 + 9;
const int mod = 998244353;
int a[N],b[N];
int n,m,T;
char ans[N];
bool flag;
int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^'0');s=getchar();}
	return f*x;
}
bool check()
{
	for(int i = 1; i <= n/2; i ++)
		if(b[i] != b[n - i + 1])
			return false;
	return true;	
}
void dfs(int step,int L,int R)
{
	if(step == n + 1)
	{
		if(check())
			flag = true;
		return;
	}
	if(step <= n / 2)
	{
		ans[step] = 'L';
		b[step] = a[L];
		dfs(step+1,L+1,R);
		b[step] = 0;
	
		if(flag) return;
		
		ans[step] = 'R';
		b[step] = a[R];
		dfs(step+1,L,R-1);
		b[step] = 0;
		if(flag) return;
	}
	else 
	{
		if(b[n - step + 1] == a[L])
		{
			ans[step] = 'L';
			b[step] = a[L];
			dfs(step+1,L+1,R); 
			b[step] = 0;
			if(flag) return;
		}
		if(b[n - step + 1] == a[R])
		{
			ans[step] = 'R';
			b[step] = a[R];
			dfs(step+1,L,R-1);	
			b[step] = 0;
			if(flag) return;
		}
	}
}
void Main()
{
	flag = false;
	n = read() * 2;
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	dfs(1,1,n);
	if(flag) 
		for(int i = 1; i <= n; i ++)
			printf("%c",ans[i]);
	else printf("-1");
	printf("\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T = read();
	while(T--)
		Main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

