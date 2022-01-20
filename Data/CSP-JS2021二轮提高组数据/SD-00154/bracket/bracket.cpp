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
const int N = 507, inf = 0x3f3f3f3f, mod = 1e9+7;

inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
};

int n, k, ans;
char c[N];

void show()
{
	for(int i = 1; i <= n; i++)
		cout << c[i];
	cout << endl;
}


bool judge()
{
	if(c[1]!='(' or c[n]!=')')
		return false;
	stack<char> s;
	int cnt = 0;
	//queue<int> mark;
	char last;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == '(')
		{
			s.push('(');
			cnt = 0;
			last = '(';
		}
		else if(c[i] == ')')
		{
			if(s.empty())
				return false;
			else
			{
				s.pop();
				cnt = 0;
				last = ')';
			}
		}
		else if(c[i] == '*')
		{
			if(cnt + 1 > k)
				return false;
		 //	else if(last == ')' and !s.empty())
		 //	{
		 	//	show();
		//		return false;
		//	}
			else
			{
				++cnt;
				last = '*';
			}
		}
	}
	if(!s.empty())
		return false;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == '(')
		{
			s.push('(');
			cnt = 0;
			last = '(';
		}
		else if(c[i] == ')')
		{
			if(s.empty())
				return false;
			else
			{
				s.pop();
				cnt = 0;
				last = ')';
			}
		}
		else if(c[i] == '*')
		{
			if(cnt + 1 > k)
				return false;
		 	else if(last == ')' and !s.empty())
		 	{
		 	//	show();
				return false;
			}
			else
			{
				++cnt;
				last = '*';
			}
		}
	}
	return true;
}


void solve(int t)
{
	if(t==n+1)
	{
		if(judge())
			ans = (ans + 1) % mod;//, show();
		return;
	}
	
	if(c[t]!='?')
		solve(t+1);
	else
	{
		c[t] = '(';
		solve(t+1);
		c[t] = ')';
		solve(t+1);
		c[t] = '*';
		solve(t+1);
		c[t] = '?';
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read();
	k = read();
	for(int i = 1; i <= n; ++i)
		c[i] = getchar();
	solve(1);
	cout << ans;
	return 0;
};
