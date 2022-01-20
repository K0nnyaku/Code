#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<stack>
using namespace std;
#define ll long long
const int numm = 1e6+5;
const int infss = 2147483647;
const int mod = 1e9+7;
int n,m,k;
int cnt;
int a[numm],sts[numm];
ll ans ;
stack<int>st;

inline bool check ()
{
//	int last = 0,tsal = 0;
	while(!st.empty()) st.pop();
	if(sts[1] == 3||sts[n] == 3) return false ;
	for(int i = 1;i<=n;i++)
	{
		if(sts[i] == 2)
		{
			if(st.empty()) return false ;
			st.pop();
		}
	    if(sts[i] == 1) st.push(1);
	    
	}
	if(st.empty()) return true;
	return false ;
}
void dfs (int step ,int numk)
{
	if(numk>k) return ;
	if(step>n)
	{
		if(check())
		{
		 ans = (ans+1) % mod;
//		 for(int i = 1;i<=n;i++)
//		 printf("%d ",sts[i]);
//		 printf("\n");
	    }
		return ;
	}
	if(a[step])
	{
		sts[step] = a[step];
		if(a[step] == 3)
		dfs(step+1,numk+1);
		else dfs(step+1,0);
	}
	else 
	for(int i = 1;i<=3;i++)
	{
		if(i == 3) {sts[step] = i;dfs(step+1,numk+1);}
		else 
		{
			sts[step] = i;
			dfs(step+1,0);
		}
	}
}
int main()
{
	   freopen("bracket.in","r",stdin);
	   freopen("bracket.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(n <=40)
    {
    	for(int i = 1;i<=n;i++)
    {
    	char c;cin>>c;
    	if(c == '(') a[i] = 1;
    	if(c == ')') a[i] = 2;
    	if(c == '*') a[i] = 3;
	}
	dfs(1,0);
	printf("%d",ans);
	}
	else 
	printf("0");
   fclose(stdin);
   fclose(stdout);
   return 0;
}
/*
10 2
???(*??(?)

*/

