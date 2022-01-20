#include<iostream>
#include<cstdio>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
inline int qread(){
	int x=0;
	char c=getchar(),o=' ';
	while(c<'0'||c>'9') o=c,c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	if(o=='-') x=~x+1;
	return x;
}
struct flight{
	int s,t;
}f[100010];
int ans1[100010],ans2[1000010];
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int > > > q1,q2;
bool cmp(flight x,flight y){
	return x.s<y.s;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=qread(),m1=qread(),m2=qread();
	for(int i=1;i<=m1;++i){
		f[i].s=qread(),f[i].t=qread();
	}
	sort(f+1,f+1+m1,cmp);
	int cnt=0;
	for(int i=1;i<=m1;++i){
		while(!q2.empty()){
			if(q2.top().first>=f[i].s) break;
			q1.push(make_pair(q2.top().second,q2.top().first));
			q2.pop();
		}
		if(q1.empty()){
			q2.push(make_pair(f[i].t,++cnt));
			ans1[cnt]=1;
		}else{
			ans1[q1.top().first]++;
			q2.push(make_pair(f[i].t,q1.top().first));
			q1.pop();
		}
	}
	cnt=0;
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	for(int i=1;i<=m2;++i){
		f[i].s=qread(),f[i].t=qread();
	}
	sort(f+1,f+1+m2,cmp);
	for(int i=1;i<=m2;++i){
		while(!q2.empty()){
			if(q2.top().first>=f[i].s) break;
			q1.push(make_pair(q2.top().second,q2.top().first));
			q2.pop();
		}
		if(q1.empty()){
			q2.push(make_pair(f[i].t,++cnt));
			ans2[cnt]=1;
		}else{
			ans2[q1.top().first]++;
			q2.push(make_pair(f[i].t,q1.top().first));
			q1.pop();
		}
	}
	for(int i=1;i<=n;++i){
		ans1[i]=ans1[i-1]+ans1[i];
		ans2[i]=ans2[i-1]+ans2[i];
	}
	int ans=0;
	for(int i=0;i<=n;++i){
		ans=max(ans,ans1[i]+ans2[n-i]);
//		cout<<ans1[i]<<" "<<ans2[n-i]<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
