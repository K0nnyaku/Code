#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2e6;
const int MOD = 1e9 + 7;
const string str = "*()";
int n,m,k,len;
ll ans;
string s;
bool check()
{
	int ans1 = 0,ans2 = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i] == '(') ans1++;
		if(s[i] == ')') ans2++;
	}
	if(ans1 != ans2) return false;
	if(s[0] == '*') return false;
	return true;
}
void print(int len)
{
	if(check() == true) ans++,ans %= MOD;
}
void dfs(int num)
{
	if(num == n) 
	{
		print(n);
		return;
	}
	if(s[num] != '?') dfs(num+1);
	if(s[num] == '?')
	{
		for(int i=0;i<3;i++)
		{
			s[num] = str[i];
			dfs(num + 1);
			s[num] = '?';
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	dfs(0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

