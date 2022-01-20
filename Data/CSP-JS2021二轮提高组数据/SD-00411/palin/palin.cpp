#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}

int a[MAXN];

string get_res(int l,int r,int x,int y)
{
	string s, t;
	while(l<=r || x<=y)
	{
		bool ok = 0;
		if(l <= r)
		{
			if(l < r && a[r] == a[l])
			{
				s += 'L'; t += 'L';
				ok = 1; ++l; --r;
			}
			else if(x <= y && a[y] == a[l])
			{
				s += 'L'; t += 'R';
				ok = 1; ++l; --y;
			}
		}
		if(!ok && x <= y)
		{
			if(x < y && a[y] == a[x])
			{
				s += 'R'; t += 'R';
				ok = 1; ++x; --y;
			}
			else if(l <= r && a[r] == a[x])
			{
				s += 'R'; t += 'L';
				ok = 1; ++x; --r;
			}
		}
		if(!ok) return "Z";
	}
	reverse(t.begin(), t.end());
	return s + t;
}

void solve(void)
{
	int n = read();
	n *= 2;
	for(int i=1; i<=n; ++i) a[i] = read();
	
	static int pos1[MAXN], pos2[MAXN];
	memset(pos1, 0, (n+1)<<2);
	memset(pos2, 0, (n+1)<<2);
	for(int i=1; i<=n; ++i)
	{
		if(pos1[a[i]] == 0) pos1[a[i]] = i;
		else pos2[a[i]] = i;
	}
	
	int k = pos2[a[1]];
	reverse(a+k+1,a+n+1);
	string s = get_res(2, k-1, k+1, n);
	if(s != "Z")
	{
		cout << "L" << s << "L" << endl;
		return;
	}
	reverse(a+k+1,a+n+1);
	
	k = pos1[a[n]];
	reverse(a+k+1, a+n);
	s = get_res(1, k-1, k+1, n-1);
	if(s != "Z")
	{
		cout << "R" << s << "L" << endl;
		return;
	}
	cout << -1 << endl;
}

int main(void)
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int T = read();
	while(T--) solve();
	return 0;
}
