#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<iomanip>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<cstring> 
using namespace std;
string a;
int now,n,k,ques,now_ques,duo,tmp,used;
long long ans; long long qu = 1000000007;
int you[505],need[505];

void dfs(int pos)
{
	if(pos==n)
	{
		return;
	}
	used++;
	if(ques-used-1>=abs(now))
	{
		now--;
		ans++; ans %= 1000000007;
		dfs(pos+1);
		now++;
	}
	if(now<0)
	{
		now++;
		ans++; ans%=1000000007;
		dfs(pos+1);
		now--;
	}
	if(duo<k)
	{
		if(now<=0&&ques-used>=abs(now))
		{
			duo++;
			ans++; ans %= 1000000007;
			dfs(pos+1);
			duo--;
		}
	}
	used--;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>a; ques = n;
//	for(int i = 0;i<n;i++)
//	{
//		if(a[i]=='?')
//		{
//			ques++;
//			suo++;
//			tmp++;
//			need[tmp] = i;
//		}
//		if(a[i]=='(')
//		{
//			you[i] = you[i]-1;
//		}
//		else
//		{
//			you[i] = you[i]+1;
//			if(you[i]>suo)
//			{
//				cout<<0<<endl;
//				return 0;
//			}
//		}
//	}
	dfs(0);
	cout<<ans<<endl;
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
