#include<bits/stdc++.h>
using namespace std;
inline int Read()
{
	int x;
	char ch;
	bool neg=0;
	while ((ch=getchar())<'0'||ch>'9') neg=(ch=='-');
	x=ch-'0';
	while ((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0';
	return neg?-x:x;
}
const int N=5e5+10;
int n,a[N<<1],b[N<<1];
string ans;
inline bool check(string s)
{
	int l=1,r=2*n;
	for (int i=1;i<=2*n;i++)
	{
		if (s[i-1]=='L')
		{
			b[i]=a[l++];
		}
		else if (s[i-1]=='R')
		{
			b[i]=a[r--];
		}
	}
	for (int i=1;i<=n;i++)
		if (b[i]!=b[2*n-i+1]) return 0;
	return 1;
}
void dfs(int now,string s)
{
	if (now>2*n)
	{
		if (check(s)) ans=min(ans,s);
		return;
	}
	dfs(now+1,s+'L');
	dfs(now+1,s+'R');
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	T=Read();
	while (T--)
	{
		n=Read();
		ans="";
		for (int i=1;i<=2*n;i++)
			a[i]=Read(),b[i]=0,ans+="Z";
		dfs(1,"");
		if (ans[0]=='Z') printf("-1\n");
		else cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
