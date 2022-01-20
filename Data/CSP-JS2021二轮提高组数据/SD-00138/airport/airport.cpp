#include<algorithm>
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M[2];int l[2][MAXN],r[2][MAXN],res[2][MAXN],ans;pair<int,int>a[2][MAXN];set<int>pos[2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int solve(int id)
{
	if(pos[id].empty())return 0;int x=*pos[id].begin(),ans=1;pos[id].erase(x);
	while(1){auto z=pos[id].lower_bound(lower_bound(l[id]+1,l[id]+M[id]+1,r[id][x])-l[id]);if(z==pos[id].end())break;x=*z;pos[id].erase(x);ans++;}
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);freopen("airport.out","w",stdout);
	N=get();For(i,0,1)M[i]=get();For(i,0,1)For(j,1,M[i])a[i][j].first=get(),a[i][j].second=get();
	For(i,0,1){sort(a[i]+1,a[i]+M[i]+1);For(j,1,M[i])l[i][j]=a[i][j].first,r[i][j]=a[i][j].second;}
	For(i,0,1){For(j,1,M[i])pos[i].insert(j);For(j,1,N)res[i][j]=res[i][j-1]+solve(i);}
	For(i,0,N)ans=max(ans,res[0][i]+res[1][N-i]);cout<<ans<<'\n';return 0;
}
