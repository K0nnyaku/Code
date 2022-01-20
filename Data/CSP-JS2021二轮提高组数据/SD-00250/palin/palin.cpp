#include <cstdio>
#include <deque>
#include <vector>
#define R register
void starT()
{freopen("palin.in", "r", stdin);freopen("palin.out", "w", stdout);}
void enD(){fclose(stdin);fclose(stdout);}
int read(){int a=1;int b=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')a=-1;c=getchar();}while(c<='9'&&c>='0'){b=(b<<3)+(b<<1)+(c^'0');c=getchar();}return a*b;}
int T, n;
std :: vector<int> v;
std :: vector<int> a;
std :: deque<int> q;
std :: vector<char> ans;
std :: vector<int> temp;
std :: vector<char> tmp2;
inline void Dfs()
{
	if (q.empty())
	{
		putchar('-');
		putchar('1');
		return ;
	}
	bool f = true;
	for (R int i = 0, j = a.size() - 1; i < j; ++i, --j)
		if (a[i] ^ a[j])
			f = false;
	if (f)
	{
		for (R int i = 0; i < ans.size(); ++i)
			putchar(ans[i]);
		return ;
	}
	temp = a;
	a.push_back(q.front());
	int Fron = q.front();
	q.pop_front();
	tmp2 = ans;
	ans.push_back('L');
	Dfs();
	ans = tmp2;
	q.push_front(Fron);
	a = temp;
	a.push_back(q.back());
	q.pop_back();
	ans.push_back('R');
	Dfs();
}
bool judg()
{
	for (R int i = 0, j = v.size() - 1; i < j; ++i, --j)
		if (v[i] ^ v[j])
			return false;
	return true;
}
int main()
{
starT();
	T = read();
	while (T--)
	{
		n = read();
		for (R int i = 0; i < 2*n; ++i)
		{
			v.push_back(read());
			q.push_back(v[i]);
		}
			
		if (judg())
		{	
			R int temp = 2*n;
			while (temp--)
				putchar('L');
			return 0;
		}
		Dfs();
		putchar('\n');
	}
enD();
	return 0;
}
/*
2 5
4 1 2 4 5 3 1 2 3 5 
3
3 2 1 2 1 3
*/
