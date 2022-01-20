#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#define unsigned long long usll
using namespace std;
int n,m1,m2,plane=0,maxn=-1;;
int last[100010];
int  ans = 0,ts=1;
// int m1in[1e5+10],m2in[1e5+10],m1out[1e5+10],m2out[1e5+10];
struct qiao {
	bool kind,use=0;   //0国内，1国际
	int in,out;
} airplane[100010];
int dfs1(int n) {
	if(n==0) return 0;
	int plane1 = 0;
	memset(last,0,sizeof(last));
	for(int i=1; i<=m1; i++) {
		for(int j=1; j<=n; j++) {
			if(airplane[i].in>last[j])	{
				last[j] = airplane[i].out;
				++plane1;
				break;
			}
		}

	}
	return plane1;
}
int dfs2(int n) {
	if(n==0) return 0;
	int plane2 = 0;
	memset(last,0,sizeof(last));
	for(int i=m1+1; i<=m1+m2; i++) {
		for(int j=1; j<=n; j++) {
			if(airplane[i].in>last[j])	{
				last[j] = airplane[i].out;
				++plane2;
				break;
			}
		}
	}
	return plane2;
}
int cmp(qiao a,qiao b) {

	return a.in<b.in;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) cin>>airplane[i].in>>airplane[i].out,airplane[i].kind=0;
	for(int i=m1+1; i<=m1+m2; i++) cin>>airplane[i].in>>airplane[i].out,airplane[i].kind=1;
	sort(airplane+1,airplane+m1,cmp);
	sort(airplane+m1+1,airplane+m1+m2,cmp);
	/*	for(int i=0; i<=n; i++) {
		 //从0开始，因为可以不用廊桥
		 dfs(1,i);
		 long long dfs1=maxn;
		 maxn = 0;plane = 0;
		 dfs(m1+1,n-i);
		 dfs1+=maxn;
			ans=max(maxn , ans);
		}*/


	for(int i=0; i<=n; i++) {
		ans = max(ans, dfs1(i)+dfs2(n-i));
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
}
