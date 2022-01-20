#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > gn,gw;
int f1[100010],f2[100010];
int g1[100010],g2[100010];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) {
		int x,y;
		cin>>x>>y;
		gn.insert(make_pair(x,y));
	}
	for(int i=1;i<=m2;i++) {
		int x,y;
		cin>>x>>y;
		gw.insert(make_pair(x,y));
	}
	for(int i=1;i<=n;i++) {
		int cnt=0;
		pair<int,int> now=make_pair(0,0);
		while(1) {
			auto it=gn.upper_bound(now);
			if(it==gn.end()) break;
			now=make_pair((*it).second,0),cnt++;
			gn.erase(it);
			f1[i]++;
		}
		if(cnt==0) break;
	}
	for(int i=1;i<=n;i++) {
		int cnt=0;
		pair<int,int> now=make_pair(0,0);
		while(1) {
			auto it=gw.upper_bound(now);
			if(it==gw.end()) break;
			now=make_pair((*it).second,0),cnt++;
			gw.erase(it);
			f2[i]++;
		}
		if(cnt==0) break;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m1;j++)
			g1[i]=g1[i-1]+f1[i];
		for(int j=1;j<=m2;j++)
			g2[i]=g2[i-1]+f2[i];
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,g1[i]+g2[n-i]);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
