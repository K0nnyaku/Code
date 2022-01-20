//���� ���� ���ַ�������ȥ�ǰ� 
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
int n,k;
#define maxn 509
char a[maxn],b[maxn];
int ans=0;
int f[maxn][maxn][maxn*2];
bool check()
{
	int e=0,ok=1,s=0,maxs=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='(')e++;
		else if(a[i]==')')e--;
		if(a[i]=='*')s++;
		else maxs=max(s,maxs),s=0;
		if(e<0)
		{
			break;
		}
	}
	if(e==0&&ok&&maxs<=k)
	{
	
	printf("%s\n",a+1)	;return 1;
	}
	return 0;
}
void dfs(int now)
{
	if(now==n+1)
	{
		if(check())ans++;
		return;
	}
	if(b[now]!='?')
	{
		dfs(now+1);
		return;
	}
	a[now]='(';
	dfs(now+1);
	a[now]=')';
	dfs(now+1);
	a[now]='*';
	dfs(now+1);
	return;
}
		int res=0,mod=1000000007;
int C(int n,int m)
{
	int p=1;
	for(int i=m+1;i<=n;i++)
	{
		p=p*i%mod;
	}
	for(int i=1;i<=n-m;i++)p/=i;
	return p;
}
int Cat(int k)
{
	return C(n,k)*C(n-1,k)%mod;
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	if(n>=100)
	{
		int res=0,mod=1000000007;
		for(int len=1;len<=n;len++)
		{
			res+=(n-len+1)*Cat(len)%mod;
			res%=mod;
		}
		printf("%d\n",res);
		return 0;
	}
	for(int i=1;i<=n;i++)b[i]=a[i];
	dfs(1);
	printf("%d\n",ans/2);
	return 0;
}
/*
4:20 
�۲����ݷ�Χ ��������dp 
����ᡣ��ȥ����T34�ı��� 
4:56���� �о�һ������������
5:23ʣ��ʱ�䶼�������T4��д�� 
5:28 5min���˸�T4.
f[i][j][k]��ʾ��[i,j]��������� 
����k���������ж����ַ��� 
f[l][r][a]=f[l][k]+f[k+1][r]
���Ű������Ǻ�����ɾ�� �ʺ����䰤������Ǻ����� 
Ȼ��������dp 
�����ɽ����һ�� 
6:00
���ᣬ׼��������25�� 
�������ʿ��Կ�������Ԥ����+ö���Ǻ� 
7 3
(*??*??
10 2
???(*??(?)
�о�Ӧ��34���� ֱ��ç2 ˵�������л��ᡣ
2�о�û�ˡ� 
*/
