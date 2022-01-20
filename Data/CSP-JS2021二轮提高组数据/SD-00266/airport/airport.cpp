#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=100005;
struct Item{int s,t;
	Item(int s=0,int t=0)
		:s(s),t(t){}
	bool operator<(const Item&r)
		const{return s>r.s||(s==r.s&&t>r.t);}
}a[maxn],b[maxn];
bool cmp(Item a,Item b){return a.s<b.s;}
int n,m1,m2,s1[maxn],s2[maxn];
int main(){
	ios::sync_with_stdio(0);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;int ans=0;
	for(int i=0;i<m1;i++)cin>>a[i].s>>a[i].t;
	for(int i=0;i<m2;i++)cin>>b[i].s>>b[i].t;
	sort(a,a+m1,cmp);sort(b,b+m2,cmp);
	priority_queue<Item>q1,q2;
	for(int i=0;i<m1;i++){
		queue<Item>tmp;
		while(q1.size()&&q1.top().s<=a[i].s)
			{int x=q1.top().t;q1.pop();tmp.push(Item(-1,x));}
		while(tmp.size()){q1.push(tmp.front());tmp.pop();}
		if(q1.size()&&q1.top().s<a[i].s)
			{int x=q1.top().t;q1.pop();q1.push(Item(a[i].t,x));s1[x]++;}
		else{int x=q1.size()+1;q1.push(Item(a[i].t,x));s1[x]++;}
	}
	for(int i=0;i<m2;i++){
		queue<Item>tmp;
		while(q2.size()&&q2.top().s<=b[i].s)
			{int x=q2.top().t;q2.pop();tmp.push(Item(-1,x));}
		while(tmp.size()){q2.push(tmp.front());tmp.pop();}
		if(q2.size()&&q2.top().s<b[i].s)
			{int x=q2.top().t;q2.pop();q2.push(Item(b[i].t,x));s2[x]++;}
		else{int x=q2.size()+1;q2.push(Item(b[i].t,x));s2[x]++;}
	}
	for(int i=0;i<=n;i++)s1[i]+=s1[i-1];
	for(int i=0;i<=n;i++)s2[i]+=s2[i-1];
	for(int i=0;i<=n;i++)
		ans=max(ans,s1[i]+s2[n-i]);
	cout<<ans<<endl;
	return 0;
}
