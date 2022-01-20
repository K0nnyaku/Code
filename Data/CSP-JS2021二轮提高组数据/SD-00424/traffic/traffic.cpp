#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
const int inf_int = 0x7fffffff;
typedef long long ll;
int n,m;
#define maxn 250009
vector<int> son[maxn],v[maxn];
#define pos(x,y) ((x-1)*n+y)
void Add(int x,int y,int z)
{
	son[x].push_back(y);
	v[x].push_back(z);
}
bool vis[maxn];
int a[maxn*4]; 
signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int T;
	scanf("%d%d%d",&n,&m,&T);
	int cnt=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			a[++cnt]=x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			int x;
			scanf("%d",&x);
			a[++cnt]=x;
		}
	}
	while(T--)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			int p,c,b;
			scanf("%d%d%d",&p,&b,&c);
			a[++cnt]=p;
		}
		sort(a+1,a+1+cnt);
		int res=0;
		for(int i=1;i<=(n-1)*(m-1);i++)res+=a[i];
		printf("%d\n",res);
		cnt-=k;
	}
	return 0;
}
/*
4:43 ��������϶��� 2^n
����n^3����AyA 
���� 2^NM �� 
�Ͻ�д�� 
�����Ż� ��Ȼͬɫ��Ӧ�ö�����һ�� 
����k=2����� ������ȫŪ�ɺڵ� 
Ȼ��Ӱ׵����￪ʼ������ת����� 
���Ӷ�2^(n+m) ɵ�� 
.2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0

*/ 
