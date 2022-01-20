#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, k;
char op[3] = {'*', '(', ')'}; 
char a[510];
int cnt;

bool check(vector<char> v)
{
	stack<char> s;
	//  ((**()*(*))*)(***) 
	// –Œ»Á AA, ASA, (A), (SA), (AS) 
	
	if (v[0] == '*') return false;
	if (v[v.size() - 1] == '*') return false;
	for (int i = 0; i < v.size(); i ++ )
	{
		if (v[i] == '(' || v[i] == '*') s.push(v[i]);
		else
		{
			int num = 0;
			while (s.top() != '(' && s.size())
			{
				num ++ ;
				s.pop();
			}
			
			if (!s.size()) return false;
			if (num > k) return false;
			s.pop();
		}
	}
	
	return true;
}

void dfs(vector<char> v)
{
	if (v.size() == n)
	{
		if (check(v))
			cnt ++ ;
		return;
	}
	
	if (a[v.size()] == '(' || a[v.size()] == ')' || a[v.size()] == '*')
	{
		v.push_back(a[v.size()]);
		dfs(v);
	}
	
	else
	{
		for (int i = 0; i < 3; i ++ )
		{
			v.push_back(op[i]);
			dfs(v);
			v.pop_back();
		}
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	cin >> n >> k;
	
	scanf("%s", a);
	
//	for (int i = 0; i < strlen(a); i ++ ) cout << a[i];
	vector<char> c;
	dfs(c);
	
	cout << cnt << endl;
	return 0;
}
