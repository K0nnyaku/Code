#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN=5e5+10;

int n;
int a[MAXN<<1];

inline bool chk(string s)
{
	int lpos=1,rpos=2*n;
	deque<int> b;
	
	for(int i=0;i<2*n;i++)
		if(s[i]=='L') b.push_back(a[lpos++]);
		else b.push_back(a[rpos--]);
	
	static int tmp[MAXN<<1],gao[MAXN<<1];
	for(int i=1;i<=2*n;i++)
		gao[i]=tmp[i]=b.front(),
		b.pop_front();
		
	reverse(gao+1,gao+2*n+1);
	for(int i=1;i<=2*n;i++)
		if(gao[i]!=tmp[i]) return false;
	return true;
}

inline void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	
	string ans,ept;
	for(int msk=0;msk<(1<<(2*n));msk++)
	{
		string cur;
		for(int i=1;i<=2*n;i++)
			if(msk&(1<<(i-1))) cur+='L';
			else cur+='R';
		
		if(chk(cur))
		{
			if(ans==ept) ans=cur;
			else ans=min(ans,cur);
		}
	}
	
	if(ans==ept) puts("-1");
	else cout<<ans<<'\n';
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
} 
