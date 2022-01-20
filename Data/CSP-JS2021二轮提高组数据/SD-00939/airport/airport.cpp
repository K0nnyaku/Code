#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

const int N=998244;

int top,qwq1[N],qwq2[N],n,m1,m2,tag[N];
struct ap{
	int s,t;
}d1[N],d2[N];
std::set<int> s;
struct data{
	int id,val,ty;
	bool operator < (const data &b) const {
		return val<b.val;
	}
}stk[N];

signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) cin>>d1[i].s>>d1[i].t;
	for(int i=1;i<=m2;i++) cin>>d2[i].s>>d2[i].t;
	for(int i=1;i<=m1;i++){
		stk[++top]=(data){i,d1[i].s,1};
		stk[++top]=(data){i,d1[i].t,0};
	}
	std::sort(stk+1,stk+top+1);
	for(int i=1;i<=m1;i++) s.insert(i);
	for(int i=1;i<=top;i++){
		if(stk[i].ty){
			int bf=*s.begin();
			tag[stk[i].id]=bf,qwq1[bf]++;
			s.erase(bf);
		} else {
			int bf=tag[stk[i].id];
			s.insert(bf);
		}
	}
	/*-------------------------------------------*/
	s.clear();top=0;
	for(int i=1;i<=m2;i++) tag[i]=0;
	for(int i=1;i<=m2;i++){
		stk[++top]=(data){i,d2[i].s,1};
		stk[++top]=(data){i,d2[i].t,0};
	}
	std::sort(stk+1,stk+top+1);
	for(int i=1;i<=m2;i++) s.insert(i);
	for(int i=1;i<=top;i++){
		if(stk[i].ty){
			int bf=*s.begin();
			tag[stk[i].id]=bf,qwq2[bf]++;
			s.erase(bf);
		} else {
			int bf=tag[stk[i].id];
			s.insert(bf);
		}
	}
	for(int i=1;i<=m1;i++) qwq1[i]+=qwq1[i-1];
	for(int i=1;i<=m2;i++) qwq2[i]+=qwq2[i-1];
	int ans=0;
	for(int i=0;i<=n;i++){
//		cerr<<i<<" -> "<<qwq1[i]<<" "<<qwq2[i]<<"\n";
		ans=std::max(ans,qwq1[i]+qwq2[n-i]);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
3 5 4 
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
