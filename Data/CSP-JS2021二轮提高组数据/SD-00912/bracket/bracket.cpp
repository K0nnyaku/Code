#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#define pr pair < int,int >
#define forever() while(true)
#define mkp(x,y) make_pair(x,y)
#define get_time() (clock()/1000.0)
#define out(x) write(x),putchar(' ')
#define writen(x) write(x),putchar('\n')
using namespace std;

inline int read()
{
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') y=-y;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^'0');
	return x;
}

inline void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

void input_an_output()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}

int n,k,ans;
char s[505],mem[15]={"%()*"};
bool vis[505];
bool pailiezuhe=1;
#define mod ((int)1e9+7)

bool check()
{
	int cnt=0;
	stack < int > st;
	if(s[1]!='('||s[n]!=')') return 0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')
		{
			st.push(i);
			cnt=0;
		}
		if(s[i]==')')
		{
			if(st.empty()) return 0;
			if(s[st.top()-1]=='*'&&s[i+1]=='*') return 0;
			st.pop();
			cnt=0;
		}
		if(s[i]=='*')
		{
			cnt++;
			if(cnt>k) return 0;
		}
	}
	if(st.size()) return 0;
	return 1;
}

void dfs(int x)
{
	if(x==n+1)
	{
		if(check()) ans++;
		ans%=mod;
		return ;
	}
	if(vis[x])
	{
		dfs(x+1);
		return ; 
	}
	for(int i=1;i<=3;i++)
	{
		s[x]=mem[i];
		dfs(x+1);
		s[x]='?';
	}
}

signed main()
{
	input_an_output();
	n=read(),k=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]!='?') pailiezuhe=0,vis[i]=1;
	}
	if(n<=40)
	{
		dfs(1);
		write(ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
