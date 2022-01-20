#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
int t,n,a[1000010],vis[500010];
vector<int>v;
vector<char>s;
inline bool dfs(int l,int r){
	int len=v.size();
	if(len&&len<=n&&vis[v.back()]==2)
		return 0;
	if(len&&len>n&&v.back()^v[n-(len-n)])
		return 0;
	if(l>r){
		for(int i=0;i<len-i-1;++i)
			if(v[i]^v[len-1-i])
				return 0;
		for(int i=0;i<s.size();++i)
			putchar(s[i]);
		putchar('\n');
		return 1;
	}
	v.push_back(a[l]);
	++vis[v.back()];
	s.push_back('L');
	if(dfs(l+1,r))
		return 1;
	s.pop_back();
	--vis[v.back()];
	v.back()=a[r];
	++vis[v.back()];
	s.push_back('R');
	if(dfs(l,r-1))
		return 1;
	s.pop_back();
	--vis[v.back()];
	v.pop_back();
	return 0;
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(vis,0,sizeof(int)*(n+1));
		for(int i=1;i<=n<<1;++i)
			scanf("%d",a+i);
		vector<int>tmp;
		vector<char>tmps;
		swap(tmp,v);
		swap(tmps,s);
		if(!dfs(1,n<<1))
			puts("-1");
	}
	return 0;
}
