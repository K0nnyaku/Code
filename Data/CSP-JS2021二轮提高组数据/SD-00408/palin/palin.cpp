#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int N=1e5+5;
int a[N],s[N],js[N];
int ans=0;
int n;
map<int,int> ma;
bool check()
{
	for(int i=1;i<=n;i++) if(a[i]!=a[n*2-i+1]) return 0;
	return 1;
}
void dfs(int l,int r,int k)//k=1 
{
	if(k>n*2)
	{
		if(check())
		{
			ans=1;
		}
		return;
	}
	a[k]=s[l];js[k]=0;ma[s[l]]++;
	if(k>n||ma[s[l]]<2)
	dfs(l+1,r,k+1);
	ma[s[l]]--;
	if(ans) return;
	a[k]=s[r];js[k]=1;
	if(k>n||ma[s[r]]<2)
	dfs(l,r-1,k+1);
	ma[s[r]]--;
	return;
}
int main()
{
	int T;
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int K=1;K<=T;K++)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n*2;i++) cin>>s[i];
		dfs(1,n*2,1);
		if(ans==0) cout<<"-1";
		else for(int i=1;i<=n*2;i++) cout<<(js[i]?"R":"L");
		cout<<"\n"; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
