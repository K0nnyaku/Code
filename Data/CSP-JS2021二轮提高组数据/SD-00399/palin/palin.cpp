#include<bits/stdc++.h>

using namespace std;

template<typename _T>
inline void read(_T &x)
{
	x = 0;int f = 1;char s = getchar();
	while(s < '0'||s > '9'){f=1;if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s = getchar();}
	x *= f;
}

int a[23333],n;
int typ[2333];
int b[2333];

inline int solve()
{
	int head=1,tail=2 * n;
	int top(0);
	for(int i=1;i <= 2 * n;i ++)
	{
		if(typ[i]){//L
			b[++top] = a[head];
			head++;
		}
		else{// R
			b[++top] = a[tail];
			tail--;
		}
	}
	int flag = 1;
	for(int i=1;i <= 2*n;i ++) if(b[i] != b[2 * n-i + 1]) flag = 0;
	if(flag){
		for(int i=1;i <= 2 * n;i ++)
		if(typ[i]) printf("L");
		else printf("R");
		printf("\n");
	}
	return flag;
}

inline int dfs(int x)
{
	if(x== 2 * n + 1)
	{
		int op = solve();
		return op;
	}
	typ[x] = 1;
	if(dfs(x + 1)) return 1;
	typ[x] = 0;
	if(dfs(x + 1)) return 1;
	return 0;
}

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<= 2 * n;i ++) read(a[i]);		
		int op = dfs(1);
		if(!op){
			printf("-1\n");
		}
	}

	
}

