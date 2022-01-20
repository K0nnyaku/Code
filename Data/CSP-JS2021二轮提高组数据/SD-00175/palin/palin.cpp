#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<set>
using namespace std;
inline int read()
{
	int num=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') {num*=10;num+=(ch-'0');ch=getchar();}
	return num*w; 
}
bool flag;
int t;
int n;
char ans[1000001];
int a[100001];
int p[1000001];
inline void pd()
{
	for(int i=1,j=2*n;i<=n;i++,j--)
	{
		if(p[i]!=p[j]) return;
	}
	flag=1;
	return;
}
inline void dfs(int k,int from,int to)
{
	if(flag==1) return; 
	if(k==2*n+1) {pd();return;}
	ans[k]='L',p[k]=a[from],dfs(k+1,from+1,to);
	if(flag==1) return;
	ans[k]='R',p[k]=a[to],dfs(k+1,from,to-1);
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,1,2*n);
		if(flag==0) printf("-1\n");
		else
		{
			int qwq=2*n;
			for(int i=1;i<=qwq;i++)
			{
				cout<<ans[i];
			}
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
