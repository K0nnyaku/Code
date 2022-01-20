#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1e6+10;
//int read();

int t,n,l,r;
int a[N],b[N],len;
char d[N];

void dfs(int num);
bool ck();

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		l = 1,r = 2*n;
		for(int i = 1;i <= 2*n;i ++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

bool ck()
{
	for(int i = 1;i <= n;i ++)
	{
		if(b[i] != b[2*n+1-i])return false;
	}
	return true;
}

void dfs(int num)
{
	if(num > 2*n)
	{
		if(ck())
		{
			for(int i = 1;i <= 2*n;i ++)
			{
				cout << d[i];
			}
			return;
		}
	}
	d[num] = 'L';
	b[++len] = a[l++];
	dfs(num+1);
	len --;
	l --;
	d[num] = 'R';
	b[++len] = a[r--];
	dfs(num+1);
	len --;
	r ++;
}

int read()
{
	int f = 1,num = 0;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c <= '9' && c >= '0')
	{
		num = num*10+c-'0';
		c = getchar();
	}
	return num*f;
}
