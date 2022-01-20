#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#define pii pair<int,int> 
using namespace std;
const int N=1e5+10;
int n,m1,m2;
struct dmh{
	int x,y;
};
bool cmp(dmh x,dmh y){
	return x.x<y.x;
}
dmh t1[N],t2[N];
int res=0;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin>>n>>m1>>m2;
	for(register int i=1;i<=m1;i++) cin>>t1[i].x>>t1[i].y;
	for(register int i=1;i<=m2;i++) cin>>t2[i].x>>t2[i].y;
	
	sort(t1+1,t1+m1+1,cmp);
	sort(t2+1,t2+m2+1,cmp);
	
	for(register int i=0;i<=n;i++){
		int cnt1=0,cnt2=0,ans=0;
		int x=i,y=n-i;
		priority_queue<pii,vector<pii>,greater<pii> >q1,q2;
		
		for(register int j=1;j<=m1;j++){
			priority_queue<pii,vector<pii>,greater<pii> > a;
			while(!q1.empty()){
				if(q1.top().second<=t1[j].x) q1.pop();
				else{
					a.push(make_pair(q1.top().first,q1.top().second));
					q1.pop();
				}
			}
			while(!a.empty()){
				q1.push(make_pair(a.top().first,a.top().second));
				a.pop();
			}
			int size=q1.size();
			if(size<x){
				q1.push(make_pair(t1[j].x,t1[j].y));
				cnt1++;
			}
			else continue;
		}
		
		for(register int j=1;j<=m2;j++){
			priority_queue<pii,vector<pii>,greater<pii> > a;
			while(!q2.empty()){
				if(q2.top().second<=t2[j].x) q2.pop();
				else{
					a.push(make_pair(q2.top().first,q2.top().second));
					q2.pop();
				}
			}
			while(!a.empty()){
				q2.push(make_pair(a.top().first,a.top().second));
				a.pop();
			}
			int size=q2.size();
			if(size<y){
				q2.push(make_pair(t2[j].x,t2[j].y));
				cnt2++;
			}
			else continue;
		}
		
		ans=cnt1+cnt2;
		res=max(ans,res);
	}
	cout<<res;
	return 0;
} 
