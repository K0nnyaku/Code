//感觉这暴力可以拿 
//算法看来是对了，但是跑的比较忙 
// 先想别的把 
#include <bits/stdc++.h>
using namespace std;
const int B=1e6+10;
int T;
int read() {int x;scanf("%d",&x);return x;}
int a[B];
int b[B];
string s;
string ans;
int n;
int l,r;
int ok;
void dfs(int now)
{
	if (ok==1) return;
	if (now==2*n)
	{
		ans=s;
		ok=1;
		return;
	}
	if (now>n)
	{
		int i=now+1;
		if (a[l]==b[2*n-i+1])
		{
			s+='L';
			b[now+1]=a[l];
			l++;
			dfs(now+1);
			l--;
			s.erase(s.size()-1);
		}
		if (a[r]==b[2*n-i+1])
		{
			s+='R';
			b[now+1]=a[r];
			r--; 
			dfs(now+1);
			r++;
			s.erase(s.size()-1);
		}
	}	
	else 
	{
		s+='L';
		b[now+1]=a[l];
		l++;
		dfs(now+1);
		l--;
		s.erase(s.size()-1);
		s+='R';
		b[now+1]=a[r];
		r--; 
		dfs(now+1);
		r++;
		s.erase(s.size()-1);
	}
}
void solve()
{
	n=read();
	ans.clear();
	ok=0;
	l=1,r=2*n;
	for (int i=1;i<=2*n;i++) a[i]=read();
	dfs(0);
	if (ans.size()==0) {printf("-1\n");return;}
	else 
	{
		cout<<ans<<endl;
		return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while (T--) solve();
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

2
1
20
5 20 6 12 13 18 9 17 2 7 7 18 1 11 10 15 4 6 17 19 14 10 14 13 1 16 8 3 12 8 19 20 4 16 5 3 9 2 15 11
3
3 2 1 2 1 3
*/ 
