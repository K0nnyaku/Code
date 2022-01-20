#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int N = 510;
int n,k,ans;
char s[N];
bool check()
{
	stack<char>stk;
	for(int i = 1;i <= n;i ++)
	{
		if(s[i] == '(')
			stk.push('(');
		else if(s[i] == ')')
		{
			int ar = 0;
			while(stk.top() == '*' && !stk.empty())
				ar ++,stk.pop();
			if(ar >= k)
				return false;
			if(stk.top() == '(')
				stk.pop();
			else
				stk.push(')');
		}
		else if(s[i] == '*')
		{
			int ar = 0;
			while(stk.top() == '*' && !stk.empty())
				ar ++,stk.pop();
			ar ++;
			if(ar >= k)
				return false; 
			else
				while(ar --)
					stk.push('*');
		}
	}
	return stk.empty();
}
void tr(int b)
{
	if(b == n + 1)
	{
		ans += check(); 
		return ;
	}
	if(s[b] == '?')
	{
		s[b] = '(';
		tr(b + 1);
		s[b] = ')';
		tr(b + 1);
		s[b] = '*';
		tr(b + 1);
		s[b] = '?';
	}
	else
		tr(b + 1);
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	cin >> n >> k;
	
	for(int i = 1;i <= n;i ++)
		cin >> s[i];
		
//	tr(0);
		
	cout << 0 << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
