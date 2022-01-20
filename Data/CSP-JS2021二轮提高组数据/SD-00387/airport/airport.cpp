#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

const int N = 1e5+10;

int q[N],num,ans[N];
int qa[N],numa,ansa[N];
int n,m1,m2,res[N];

struct Plane
{
	bool abd;
	int come;
	int leave;
	int nd;
}a[N];

//int read();

bool cmp(Plane a,Plane b)
{
	if(a.abd != b.abd)return b.abd;
	return a.come < b.come;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i = 1;i <= m1;i ++)
	{
		a[i].abd = false;
		scanf("%d%d",&a[i].come ,&a[i].leave );
	}
	for(int i = m1+1;i <= m1+m2;i ++)
	{
		a[i].abd = true;
		scanf("%d%d",&a[i].come ,&a[i].leave );
	}
	sort(a+1,a+m1+m2+1,cmp);
	for(int i = 1;i <= m1;i ++)
	{
		bool sf = false;//free?
		for(int j = 1;j <= num;j ++)//find
		{
			if(q[j] < a[i].come)//ok
			{
				q[j] = a[i].leave;
				sf = true;
				a[i].nd = j;
				ans[j] ++;//not_abroad = j;
			}
		}
		if(!sf)//add
		{
			q[++num] = a[i].leave;
			a[i].nd = num;
			ans[num] ++;
		}
	}
	for(int i = m1+1;i <= m1+m2;i ++)
	{
		bool sf = false;
		for(int j = 1;j <= numa;j ++)
		{
			if(qa[j] < a[i].come)
			{
				qa[j] = a[i].leave;
				sf = true;
				a[i].nd = j;
				ansa[j] ++;
			}
		}
		if(!sf)
		{
			qa[++numa] = a[i].leave;
			a[i].nd = numa;
			ansa[numa] ++;
		}
	}
	int maxn = 0;
	for(int i = 1;i <= n;i ++)
	{
		ans[i] += ans[i-1];
		ansa[i] += ansa[i-1];
	}
	for(int i = 0;i <= n;i ++)
	{
		res[i] = ans[i] + ansa[n-i];
		maxn = max(maxn,res[i]);
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
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
