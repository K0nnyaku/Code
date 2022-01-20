#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#define ll long long

using namespace std;

const ll N = 5e5 + 9;
ll T;
ll n;
ll a[N], b[N], c[N];
ll taill, head1, tail1, tail, tail2, head2;
string s1, ans, s2, ans1, ans2;
bool check1()
{
	for(register ll i = 1; i <= n; i++)
	{
		if(b[i] != b[2*n - i + 1])
			return false;
	}
	return true;
}

bool check2()
{
	for(register ll i = 1; i <= n; i++)
	{
		if(c[i] != c[2*n - i + 1])
			return false;
	}
	return true;
}
void dfs1(ll pos)
{
	if(check1())
	{
		ans1 = min(s1, ans1);
		return ;
	}
	if(s1[pos] == 'L')
	{
		b[tail] = a[head1];
		tail--;
		head1++;
		s1[pos + 1] = 'L';
			dfs1(pos + 1);
		tail++;
		head1--;
		b[tail] = 0;
		s1[pos + 1] = 'R';
			dfs1(pos + 1);
		tail++;
		head1--;
		b[tail] = 0;
	}
	if(s1[pos] == 'R')
	{
		b[tail] = a[tail1];
		tail--;
		tail1--;
		s1[pos + 1] = 'L';
			dfs1(pos + 1);
  		tail++;
		tail1++;
		b[tail] = 0;
		s1[pos + 1] = 'R';
			dfs1(pos + 1);
		tail++;
		tail1++;
 		b[tail] = 0;
	}
}

void dfs2(ll pos)
{
	if(check2())
	{
		ans2 = min(s2, ans2);
		return ;
	}
	if(s2[pos] == 'L')
	{
		c[taill] = a[head2];
		taill--;
		head2++;
		c[taill] = 0;
		s2[pos + 1] = 'L';
			dfs2(pos + 1);
		taill++;
		head2--;
		c[taill] = 0;
		s2[pos + 1] = 'R';
			dfs2(pos + 1);
		taill++;
		head2--;
		c[taill] = 0;
	}
	if(s2[pos] == 'R')
	{
		c[taill] = a[tail2];
		taill--;
		tail2--;
		c[taill] = 0;
		s2[pos + 1] = 'L';
			dfs2(pos + 1);
  		taill++;
		tail2++;
		c[taill] = 0;
		s2[pos + 1] = 'R';
			dfs2(pos + 1);
		taill++;
		tail2++;
 		c[taill] = 0;
	}
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%lld", &T);
	while(T--)
	{
		scanf("%lld", &n);
		s1[0] = 'L';
		s2[0] = 'R';
		head1 = 1;
		head2 = 1;
		tail2 = 2*n;
		taill = 2*n;
		tail = 2*n;
		tail1 = 2*n;
		for(int i = 1; i <= n;i ++)
		{
			ans[i] = 'Z';
			scanf("%lld", &a[i]);
		}
		dfs1(0);
		dfs2(0);
		ans = min(ans1, ans2);
		if(ans[1] == 'Z')
		{
			printf("-1\n");
			continue;
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
