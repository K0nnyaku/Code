#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


#define tp int

#define F(i, a, b) for(int i = a; i <= b; i++)
#define UF(i, a, b) for(int i = a; i >= b; i--)
#define alledge(i, u) for(int i = head[u]; i; i = edge[i].nxt) 

#define ll long long
#define ull long long

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

void swap(tp &a, tp &b)
{
	tp tmp = a;
	a = b;
	b = tmp;
}

tp read()
{
	tp x = 0, ch = getchar();
	while(!(ch >= '0' && ch <= '9')) ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

void write(tp x)
{
	if(x >= 10)	write(x / 10);
	putchar(x % 10 + '0');
}
void write(tp x, char k)
{
	write(x);
	putchar(k);
} 

struct Node
{
	int st, ed;
	void input()
	{
		st = read(), ed = read();
	}
//	bool operator<(const Node &ano) const
//	{
//		return st < ano.st;
//	}
} arr1[100005], arr2[100005];

bool cmp1(Node a, Node b)
{
	return a.st < b.st;
}

struct cmp
{
	bool operator()(Node a, Node b)
	{
		return a.ed > b.ed;
	}	
};

int n, m1, m2;

struct lsh
{
	int num;
	int k;
	int i;
	bool operator<(const lsh &ano) const
	{
		return num < ano.num;
	}
	lsh(int a = 0, int b = 0, int c = 0)
	{
		num = a, k = b, i = c;
	}
} lsharr[200005];

int cnt;

void lisanhua()
{
	F(i, 1, m1)
		{
			lsharr[++ cnt] = lsh(arr1[i].st, 0, i);
			lsharr[++ cnt] = lsh(arr1[i].ed, 1, i);
		}
		sort(lsharr + 1, lsharr + 1 + cnt);
		F(i, 1, cnt)
		{
			if(lsharr[i].k == 0)
			{
				arr1[lsharr[i].i].st = i;
			}
			else
			{
				arr1[lsharr[i].i].ed = i;
			}
		}
		sort(arr1 + 1, arr1 + 1 + m1, cmp1);
		
		cnt = 0;
		F(i, 1, m2)
		{
			lsharr[++ cnt] = lsh(arr2[i].st, 0, i);
			lsharr[++ cnt] = lsh(arr2[i].ed, 1, i);
		}
		sort(lsharr + 1, lsharr + 1 + cnt);
		F(i, 1, cnt)
		{
			if(lsharr[i].k == 0)
			{
				arr2[lsharr[i].i].st = i;
			}
			else
			{
				arr2[lsharr[i].i].ed = i;
			}
		}
		sort(arr2 + 1, arr2 + 1 + m2, cmp1);
		
}

namespace dusk1
{
	void solve()
	{
		int ans = 0;
		lisanhua();
		F(i, 0, n)
		{
			priority_queue<Node, vector<Node>, cmp> a;
			priority_queue<Node, vector<Node>, cmp> b;
			int ans1 = 0;
			F(j, 1, m1)
			{
				Node tmp = arr1[j];
				ans1++;
				if(a.size() < i)
					a.push(tmp);
				else
				{
					
					while(!a.empty())
					{
						if(a.top().ed < tmp.st)
							a.pop();
						else 
							break;
					}
						
					if(a.size() < i)
						a.push(tmp);
					else
						ans1--;
				} 
			}
//			cout << ans1 << endl;
			
			
			
			
			int ans2 = 0;
			F(j, 1, m2)
			{
				Node tmp = arr2[j];
				ans2++;
				if(b.size() < n - i)
					b.push(tmp);
				else
				{
					
					while(!b.empty())
					{
						if(b.top().ed < tmp.st)
							b.pop();
						else 
							break;
					}
						
					if(b.size() < n - i)
						b.push(tmp);
					else
						ans2--;
				} 
			}
//			cout << ans2 << endl;
			ans = max(ans, ans1 + ans2);
		}
		write(ans);
	}
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	n = read(), m1 = read(), m2 = read();
	F(i, 1, m1)
		arr1[i].input();
	F(i, 1, m2)
		arr2[i].input();
	dusk1::solve();
	
	
	return 0;
}
