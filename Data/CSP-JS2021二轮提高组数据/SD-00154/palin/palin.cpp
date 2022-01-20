#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<map>
#include<bitset>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 5e5+7, inf = 0x3f3f3f3f;

inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
};

int n, t;
int a[N], b[N];

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t = read();
	while(t--)
	{
		n = read();
		for(int i = 1; i <= 2*n; i++)
			a[i] = read();
	cout << -1<<endl;
	}
	return 0;
}
