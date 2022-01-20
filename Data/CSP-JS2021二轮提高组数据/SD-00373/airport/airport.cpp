#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

void read(int &x)
{
	int f= 1;
	x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch= getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch-48;
		ch = getchar();
	}
	x *= f;
}

const int N = 1e5+5;

int n,m1,m2;

struct pr
{
	int first,second;
}in[N],out[N];

int guoxu[N],outxu[N];
bool vis[N];

int sum1[N],sum2[N];

int ef(pr a[],int x,int y,int k)
{
	if(a[y].first < k)
		return 0;
	int l = x,r = y;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(a[mid].first < k)
			l = mid + 1;
		else
			r = mid;
	}
	return r;
}

bool cmp(pr x,pr y)
{
	return x.first < y.first;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(m1);read(m2);
	for(int i = 1;i <= m1;i++)
	{
		read(in[i].first);
		read(in[i].second);
	}
	for(int i = 1;i <= m2;i++)
	{
		read(out[i].first);
		read(out[i].second);
	}
	sort(in+1,in+1+m1,cmp);
	/*for(int i = 1;i <= m1;i++)
	{
		printf("%d %d %d\n",in[i].first,in[i].second,i);
	}*/
	sort(out+1,out+1+m2,cmp);
	int top = 1,cnt = 1;
	for(int i = 1;i <= m1;i++)
	{
		if(!vis[i])
		{
			int now = i,cnt = 1;
			vis[i] = 1;
			while(now <= m1)
			{
				//printf("%d\n",now);
				int nowend = in[now].second;
				int kl = ef(in,now+1,m1,nowend);
				while(vis[kl])
				{
					kl++;
				}
				//printf("%d %d %d\n",nowend,kl,cnt);
				if(kl != 0 && kl <= m1)
				{
					cnt++;
					vis[kl] = 1;
					now = kl;
					//printf("1\n");
				}
				else
				{
					guoxu[top++] = cnt;
					//printf("2\n");
					break;
				}
			}
		}
	}
	//printf("%d\n",top);
	for(int i = 1;i < top;i++)
	{
		//printf("%d\n",guoxu[i]);
		sum1[i] =sum1[i-1]+guoxu[i];
	}
	for(int i = top;i <= n;i++)
	{
		sum1[i] = sum1[top-1];
	}
	top = 1;cnt = 1;
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= m2;i++)
	{
		if(!vis[i])
		{
			int now = i,cnt = 1;
			vis[i] = 1;
			while(now <= m2)
			{
				//printf("%d\n",now);
				int nowend = out[now].second;
				int kl = ef(out,now+1,m2,nowend);
				while(vis[kl])
				{
					kl++;
				}
				//printf("%d %d %d\n",nowend,kl,cnt);
				if(kl != 0 && kl <= m1)
				{
					cnt++;
					vis[kl] = 1;
					now = kl;
					//printf("1\n");
				}
				else
				{
					outxu[top++] = cnt;
					//printf("2\n");
					break;
				}
			}
		}
	}
	for(int i = 1;i < top;i++)
	{
		sum2[i] =sum2[i-1]+outxu[i];
	}
	for(int i = top;i <= n;i++)
	{
		sum1[i] = sum1[top-1];
	}
	int maxn = 0;
	for(int i = 0;i <= n;i++)
	{
		int k = sum1[i]+sum2[n-i];
		maxn = max(maxn,k);
	}
	printf("%d",maxn);
	return 0;
}

