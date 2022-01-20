#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e6;
int n,m,t,cnt;
int a[N];
ll tot;
struct node{
	int num;
	string c;
}b[N];
struct doit{
	string s;
}ans[N];
bool vis[N];
bool cmp(doit a,doit b)
{
	return a.s < b.s;
}
bool check(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i] != a[2*n-i+1]) 
		return false; 
	}
	return true;
}
void print(int n)
{
	bool flag = true;
	++tot;
	for(int i=1;i<=n;i++)
	{
		if(b[i].num != b[2*n-i+1].num)  
		flag = false;
	}
	if(flag == true) 
	{
		for(int i=1;i<=2*n;i++)
		{
			//printf("%d ",b[i].num);
			//cout<<b[i].c;
			ans[cnt].s += b[i].c;
		}
		//cout<<ans[cnt].s;
		cnt++;
		//printf("\n");
	}
}
void dfs(int x,int y,int sum)
{
	if(sum == 2*n + 1 ) 
	{
		print(sum/2);
		return;
	}
	b[sum].num = a[x];
	b[sum].c = char(76);//char(76) = L 
	dfs(x+1,y,sum+1);//选择 操作一 
	b[sum].num = a[y];
	b[sum].c = char(82);//char(82) = R
	dfs(x,y-1,sum+1);//选择 操作二 
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cnt = 0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=2*n;i++)
		cin>>a[i];
		if(check(n) == true) //本身就是回文串 
		{
			for(int i=1;i<=2*n;i++)
			cout<<"L";
			cout<<"\n";
		}
		else
		{
			dfs(1,2*n,1);
			sort(ans,ans+cnt,cmp);
			if(cnt == 0)
			puts("-1");
			else cout<<ans[0].s<<endl;
		}
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
