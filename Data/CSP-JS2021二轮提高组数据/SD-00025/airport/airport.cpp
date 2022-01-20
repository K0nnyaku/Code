#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<vector>
#include<map>
using namespace std;
const int N = 1e5 + 9;
const int M = 1e5 + 9;
struct node{
	int pos;
	int id;
	int type;//1 - > l , 2 - > r;  
}a[N*2],b[N*2];
int vis[N];
bool Is[N];//判断是否用过 
int n,m,A,B;
int ans = 0; 
int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^'0');s=getchar();}
	return f*x;
}
bool cmp(node x,node y)
{
	return x.pos < y.pos;
}
int work1(int res)
{
	int ret = 0;
	for(int i = 1; i <= A; i ++)
	{
		if(a[i].type == 1)//如果一个来了
		{
			if(res >= 1)
			{
				ret++;
				res --;
				Is[a[i].id] = 1;
			}
		}
		if(a[i].type == 2)
		{
			if(Is[a[i].id] == 1)
			{
				Is[a[i].id] = 0;
				res ++;//用完了廊桥 
			}
		}
	}
	return ret; 
}
int work2(int res)
{
	int ret = 0;
	for(int i = 1; i <= B; i ++)
	{
		if(b[i].type == 1)//如果一个来了
		{
			if(res >= 1)
			{
				ret++;
				res --;
				Is[b[i].id] = 1;
			}
		}
		if(b[i].type == 2)
		{
			if(Is[b[i].id] == 1)
			{
				Is[b[i].id] = 0;
				res ++;//用完了廊桥 
			}
		}
	}
	return ret; 
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read(); A = read(); B = read();
	for(int i = 1; i <= A; i ++)
	{
		int Fir = 2 * i - 1;
		int Sec = 2 * i;
		a[Fir].pos = read(); a[Fir].id = i; a[Fir].type = 1;
		a[Sec].pos = read(); a[Sec].id = i; a[Sec].type = 2;
	}
	for(int i = 1; i <= B; i ++)
	{
		int Fir = 2 * i - 1;
		int Sec = 2 * i;
		b[Fir].pos = read(); b[Fir].id = i; b[Fir].type = 1;
		b[Sec].pos = read(); b[Sec].id = i; b[Sec].type = 2;
	}
	A = 2 * A; B = 2 * B; 
	sort(a+1,a+1+A,cmp);
	sort(b+1,b+1+B,cmp);
	for(int i = 0; i <= n; i ++)
	{
		int ansA = i >= A/2 ? A/2 : work1(i);
		int ansB = (n - i) >= B/2 ? B/2 : work2(n - i);
		ans = max(ans , ansA + ansB);	
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
