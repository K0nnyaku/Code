#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
typedef long long lli;
lli n,m[2],s[2][100005],h[2][100005],ans,no[2][100005];
vector<pair<lli,pair<lli,lli> > >aa;
priority_queue<lli>q;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lli%lli%lli",&n,&m[0],&m[1]);
	for(lli ia=0; ia<2; ia++) {
		aa.clear();
		for(lli i=1,a,b; i<=m[ia]; i++) {
			scanf("%lli%lli",&a,&b);
			aa.push_back(make_pair(a,make_pair(i,1ll)));
			aa.push_back(make_pair(b,make_pair(i,0ll)));
		}
		sort(aa.begin(),aa.end());
		while (!q.empty()) {
			q.pop();
		}
		for(lli i=1; i<=100002; i++) {
			q.push(-i);
		}
		for(lli i=0; i<aa.size(); i++) {
			lli c=aa[i].second.first;
			if(aa[i].second.second){
				lli b=q.top();
				q.pop();
				s[ia][-b]++;
				no[ia][c]=b;
			}else{
				q.push(no[ia][c]);
			}
		}
		for(lli i=1; i<=n; i++) {
			h[ia][i]=s[ia][i]+h[ia][i-1];
		}
	}
	for(lli i=0; i<=n; i++) {
		ans=max(ans,h[0][i]+h[1][n-i]);
	}
	printf("%lli\n",ans);
	return 0;
}

