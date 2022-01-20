#include <cstdio>
#include <string>
#include <stack>
#include <vector>
#define R register
using namespace std;
typedef long long LL;
vector<int> cnm;
const LL INF=0x3f3f3f3f;
const LL MOD = 1e9 + 7;
int aNs = 0;
void starT()
{freopen("bracket.in", "r", stdin);freopen("bracket.out", "w", stdout);}
void enD(){fclose(stdin);fclose(stdout);}
int n, k;
int count = 0;
string a;
bool correCt(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '*')
		{
			cnt++;
			if (cnt > k)
				return false;
		}
		else
			cnt = 0;
	}
	stack<char> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			cnt = 0;
			st.push('(');
		}
			
		else if (s[i] == ')')
		{
			if (st.empty())
				return false;
			if (st.top() == '(')
				st.pop();
			else
				return false;
		}
		else
			continue;
	}
	if (!st.empty())
		return false;
	return true;
}
inline void Dfs(string ss, int pos, int cnt)
{
	if (cnt == 0)
	{
		if (correCt(ss))
			++aNs %= MOD;
		return ;
	}
	int shabi;
	for (int i = 0; i < cnm.size(); ++i)
	{
		if (cnm[i] > pos)
		{
			shabi = cnm[i];
			break;
		}
	}
	string tmp;
	tmp = ss;
	tmp[pos] = '(';
	Dfs(tmp, shabi, cnt - 1);
	tmp[pos] = ')';
	Dfs(tmp, shabi, cnt - 1);
	tmp[pos] = '*';
	Dfs(tmp, shabi, cnt - 1);
	return ;
}
int main()
{
starT();
	int maRk;
	bool flag = true;
	scanf("%d%d", &n, &k);
	if (!n)
	{
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		//fuck:;
		R char temp = getchar();
		//if (temp != '(' && temp != ')' && temp != '?')
		//	goto fuck;
		if (temp == '?')
		{
			if (flag)
				maRk = i;
			flag = false;
			count++;
			cnm.push_back(i);
		}
		a += temp;
	}
	Dfs(a, maRk, count);
	printf("%d", aNs);
enD();
	
	return 0;
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/
