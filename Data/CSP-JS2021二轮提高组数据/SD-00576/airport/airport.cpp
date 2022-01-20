#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e6+16;
struct data{
	int l,r;
} d1_[MAXN],d2_[MAXN];
priority_queue < pair<int,int> > q1_,q2_,q3_,q4_;
int n,m1_,m2_,top1_=1,top2_=1;
int t1_[MAXN],t2_[MAXN];
bool cmp(data a,data b){
	return a.l<b.l;
}
void init(){
	cin>>n>>m1_>>m2_;
	for(int i=1;i<=m1_;i++)
		cin>>d1_[i].l>>d1_[i].r;
	for(int i=1;i<=m2_;i++)
		cin>>d2_[i].l>>d2_[i].r;
	sort(d1_+1,d1_+1+m1_,cmp);
	sort(d2_+1,d2_+1+m2_,cmp);
	q1_.push(make_pair(0,-1));
	q2_.push(make_pair(0,-1));
	for(int i=1;i<=m1_;i++){
		int l=d1_[i].l,r=d1_[i].r;
		int f=-q1_.top().first,s=-q1_.top().second;
		while(f<=l && (!q1_.empty())){
			f=-q1_.top().first,s=-q1_.top().second;
			if(f>l) break;
			q1_.pop();
			q3_.push(make_pair(-s,-f));
		}
		if(!q3_.empty()){
			f=-q3_.top().second,s=-q3_.top().first;
			q3_.pop();
			t1_[s]++;
			q1_.push(make_pair(-r,-s));
		}
		else{
			top1_++;
			t1_[top1_]++;
			q1_.push(make_pair(-r,-top1_));
		}
	}
	for(int i=1;i<=m2_;i++){
		int l=d2_[i].l,r=d2_[i].r;
		int f=-q2_.top().first,s=-q2_.top().second;
		while(f<=l && (!q2_.empty())){
			f=-q2_.top().first,s=-q2_.top().second;
			if(f>l) break; 
			q2_.pop();
			q4_.push(make_pair(-s,-f));
		}
		if(!q4_.empty()){
			f=-q4_.top().second,s=-q4_.top().first;
			t2_[s]++;
			q4_.pop();
			q2_.push(make_pair(-r,-s));
		}
		else{
			top2_++;
			t2_[top2_]++;
			q2_.push(make_pair(-r,-top2_));
		}
	}
	for(int i=1;i<=n;i++)
		t1_[i]=t1_[i]+t1_[i-1];
	for(int i=1;i<=n;i++)
		t2_[i]=t2_[i]+t2_[i-1];
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,t1_[i]+t2_[n-i]);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	init();

	return 0;
}
/*
3 4 5
2 11
4 15
7 17
12 16
1 5
3 8
6 10
9 14
13 18


//



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

