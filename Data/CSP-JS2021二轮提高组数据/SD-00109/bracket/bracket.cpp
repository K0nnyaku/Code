//CSP2021 rp++ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<stack>
#include<cstdlib>
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+(ch-'0'),ch=getchar();
	return s*w;
}
const int MAXN(510);
int n,k;
char s[MAXN];
int ans;
stack<char>st;
inline bool check()
{
	while(!st.empty()) st.pop();
	for(register int i=1;i<=n;i++)
	{
		if(s[i]=='(') st.push('(');
		else if(s[i]==')')
		{
			if(st.empty()) return false;
			else st.pop();
		}
	}
	return true;
}
inline void dfs(int k,int sum)
{
	if(sum>k) return;
	if(k>n)
	{
		if(check()) ++ans;
		return;
	}
	if(s[k]!='?') 
	{
		if(s[k]=='*') dfs(k+1,sum+1);
		else dfs(k+1,sum);
	}
	else
	{
		s[k]='*';
		dfs(k+1,sum+1);
		s[k]='(';
		dfs(k+1,sum);
		s[k]=')';
		dfs(k+1,sum);
		s[k]='?';
	}
	return;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	dfs(1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

