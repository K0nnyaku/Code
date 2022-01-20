#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long
using namespace std;
const int N = 1e3 + 9;
const int M = 1e3 + 9;
const int mod = 998244353;
int n,m,T;
int dis[N][N];
int val[N][2];
int id[N],k,ans;
int Col[N];
int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^'0');s=getchar();}
	return f*x;
}
int get(int i,int j)
{
	return (i-1)*m + j;
}
void Prepare()
{
	for(int i = 1 , j = 1; i <= m and j <= m; i ++ , j ++)
		id[i] = get(1,j);
	for(int i = m + 1 , j = 1; i <= m + n and j <= n; i ++ , j ++)
		id[i] = get(j,m);
	for(int i = m + n + 1 , j = m ; i <= m + m + n and j >= 1; i++ , j --)
		id[i] = get(n,j);
	for(int i = m + m + n + 1 , j = n; i <= m + m + n + n and j >= 1; i ++ , j --)
		id[i] = get(j,1);
	//for(int i = 1; i <= n + n + m + m; i ++)
	//	printf("id[%d] = %d\n",i,id[i]);
}
void dfs(int x,int y,int ret)
{
	if(ret >= ans)
		return;
	if(x == n + 1)
	{
		ans = min(ans ,ret);
		return;
	}
	int Fir = get(x - 1 , y);
	int Sec = get(x , y - 1); 
	int it = get(x,y);
	int w = 0;
	//染成白色：
	Col[it] = 0;
	if(Col[Fir] != Col[it]) w += dis[Fir][it];
	if(Col[Sec] != Col[it]) w += dis[Sec][it];
	w += val[it][1];
	if(y == m)
		dfs(x+1,1,ret + w);
	else dfs(x,y+1,ret + w);
	//染成黑色： 
	w = 0;
	Col[it] = 1;
	if(Col[Fir] != Col[it]) w += dis[Fir][it];
	if(Col[Sec] != Col[it]) w += dis[Sec][it];
	w += val[it][0];
	if(y == m)
		dfs(x+1,1,ret + w);
	else dfs(x,y+1,ret + w);
	Col[it] = 0; 
}
void Main()
{
	k = read();
	ans = 1e18;
	memset(val,0,sizeof(val));
	for(int i = 1; i <= k ; i ++)
	{
		int w = read();
		int Id = read();
		int col = read();
		val[id[Id]][col^1] += w;	
	}
	dfs(1,1,0);
	printf("%lld\n",ans);
}
signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n = read(); m = read(); T = read();
	for(int i = 1 ; i < n; i ++)
		for(int j = 1;j <= m; j ++)
		{
			int Fir = get(i,j);
			int Sec = get(i+1,j);
			dis[Fir][Sec] = dis[Sec][Fir] = read();
		}
	for(int i = 1 ; i <= n; i ++)
		for(int j = 1; j < m ; j++)
		{
			int Fir = get(i,j);
			int Sec = get(i,j+1);
			dis[Fir][Sec] = dis[Sec][Fir] = read();
		}
	Prepare();
	while(T--)
		Main();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
