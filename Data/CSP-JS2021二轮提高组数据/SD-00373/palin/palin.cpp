#include <iostream>
#include <cstdio>
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

const int N = 500005;

int t,n;

int a[2*N],tong[N];
pair <int,int> p[N];

bool pan(int a[])
{
	for(int i = 1;i <= n/2;i++)
	{
		if(a[i] != a[n-i+1])
			return false;
	}
	return true;
}

int other(int i)
{
	return p[a[i]].first == i?p[a[i]].second:p[a[i]].first;
}

bool flag = 1;
int front,end;
int zanb[2*N];

void dfs(int now,string s)
{
	//cout << s << 2*n-1 << endl;
	if(!flag) return;
	if(now == 2 * n)
	{
		zanb[now] = a[front];
		if(pan(zanb))
		{
		cout << s << endl;
		flag = 0;
		}
		return ;
	}
	/*for(int i = 1;i <= 2 * n;i++)
		printf("%d ",zanb[i]);
	printf("\n");*/
	//printf("%d %d\n",front,end);
	now++;
	string h = s + 'L';
	zanb[now] = a[front++];
	dfs(now,h);
	front--;
	h = s + 'R';
	zanb[now] = a[end--];
	dfs(now,h);
	end++;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);
		memset(zanb,0,sizeof(zanb));
		for(int i = 1;i <= 2 * n;i++)
		{
			read(a[i]);
			if(tong[a[i]]) p[a[i]].second = i;
			else{
				tong[a[i]]++;
				p[a[i]].first = i;
			}
		}
		front = 1,end = n*2;
		if(pan(a))
		{
			for(int i = 1;i <= 2 * n;i++)
				printf("L");
			printf("\n");
			continue;
		}
		else
		{
			dfs(0,"");
			if(flag)
				printf("-1\n");
		}
	}
	return 0;
}

