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
int n;
#define maxn 1000009
int a[maxn];
bool ok;
int now[maxn];
bool Ck(string opt)
{
	int l=1,r=n*2;
	for(int i=0;i<opt.size();i++)
	{
		if(opt[i]=='L')
		{
			now[i+1]=a[l];l++;
		}else
		{
			now[i+1]=a[r],r--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(now[i]!=now[2*n+1-i])return 0;
	}
	return 1;
}
void dfs(string opt)
{
	if(ok)return;
	if(opt.size()==2*n)
	{
		if(Ck(opt))
		{
			cout<<opt<<endl;
			ok=1;
			return;
		}
		return;
	}
	dfs(opt+"L");
	dfs(opt+"R");
}
void Sol()
{
	scanf("%d",&n);
	memset(now,0,sizeof(now));
	for(int i=1;i<=n*2;i++)
	{
		scanf("%d",&a[i]);
	}
	if(n<1000)
	{
		string res="";
		for(int i=1;i<=n*2;i++)res+="L";
		if(Ck(res))cout<<res;
		else printf("-1");
		printf("\n");
		return;
	} 
	ok=0;
	dfs("");
	if(!ok)printf("-1\n");
}
signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)Sol();
	return 0;
}
/*
4:28 
暴力很好写 可以搜索 
性质的话 对于当前的一个数 和他相同的那个数 
然后有了40分？？感觉可以，够了。 
我超 搜索不行啊 得换个算法 
不管了 快糊上一个 
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/
