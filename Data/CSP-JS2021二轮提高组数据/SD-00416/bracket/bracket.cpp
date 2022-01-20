#include<cstdio>
#include<cstring>
#include<stack>
#define R register 
#define ll long long

using namespace std;

ll read()
{
	R ll f = 1, x = 0;
	R char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
			f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

char a[510];
ll ans = 0, n, k;
stack<char> q;

void dfs1(int xx, int cnt)
{
	if(xx == n+1)
	{
		ans++;
		return;
	}
	for(R int i = xx; i <= n; ++i)
	{
		if(a[i] == '(')
			q.push('(');
		else if(a[i] == ')')
		{
			if(q.top() == '(')
				q.pop();
			else
				break;
		}
		else if(a[i] == '*')
			cnt++;
		else if(a[i] == '?')
		{
			if(cnt < k)
				dfs1(xx+1, cnt+1);
			if(!q.empty() && q.top() == '(')
				q.pop(), dfs1(xx+1, cnt), q.push('(');
			if(q.empty() || q.top() == ')')
				q.push('('), dfs1(xx+1, cnt), q.pop();
			break;
		}
	}
}

int main()
{
	freopen("bracket.in","r",stdin);freopen("bracket.out","w",stdout);
	n = read(), k = read();
	for(R int i = 1; i <= n; ++i)
		scanf("%c", &a[i]);
	dfs1(1, 0);
	printf("%lld",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
7 3
(*??*??

5

10 2
???(*??(?)

19

100 18
?*?????)?????*????????*??(*???????*????????????*???*?????*?????*??????*****??*??????????*???????????

*/


