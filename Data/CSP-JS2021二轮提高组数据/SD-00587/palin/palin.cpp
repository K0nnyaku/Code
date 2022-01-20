#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
#define ll long long
#define db double
const int N=1e5+10;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
int T,n,a[N<<1],pre[N<<1],len[N<<1],tmp[N];
bool vis[N];
char op[N];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(pre,0,sizeof(pre));
		memset(len,0,sizeof(len));
		n=read();
		for(int i=1;i<=2*n;i++)
			a[i]=read();
		bool flag=true;
		for(int i=0;i<(1<<n);i++)
		{
			int l=1,r=2*n,cnt=0,top=0;
			memset(vis,false,sizeof(vis));
			bool o=true;
			for(int j=1;j<=n;j++)
			{
				int bit=(i>>(n-j))&1;
				//cout<<bit;
				if(!bit) tmp[++cnt]=a[l++],op[++top]='L';
				else tmp[++cnt]=a[r--],op[++top]='R';
				if(!vis[tmp[cnt]]) vis[tmp[cnt]]=true;
				else o=false;
			}
			//cout<<endl;
			if(!o)
				continue;
			for(int j=cnt;j>=1;j--)
			{
				bool is_op=false;
				if(tmp[j]==a[l])
				{
					l++;is_op=true;
					op[++top]='L';
				}
				else if(tmp[j]==a[r])
				{
					r--;is_op=true;
					op[++top]='R';
				}
				if(!is_op) o=false;
			}
			if(o)
			{
				for(int i=1;i<=top;i++) cout<<op[i];
				cout<<endl;
				flag=false;
				break;
			}
		}
		if(flag) puts("-1");
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
