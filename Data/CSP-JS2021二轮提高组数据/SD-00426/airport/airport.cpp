#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#define ll long long
using namespace std;
struct node{
	ll be,en;
};
node a[200001];
node b[200001];
ll n,m1,m2,ans = 0,maxn=-123456789,qwq;

bool pan(node aa,node bb){
	return aa.be<bb.be;
}
ll find(ll nn,ll kong,node c[]){
	if(kong==0) return 0;
	priority_queue<long long> q;
	 ans = kong;
	for(int y = 1;y<=kong;y++){
		q.push(-c[y].en); 
	}
	for(int i = kong+1;i<=nn;i++){
		if(c[i].be>-q.top()){
			ans++;
			q.pop();
			q.push(-c[i].en); 
		}
	}
	return ans;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i = 1;i<=m1;i++){
		cin>>a[i].be>>a[i].en;
	}
	for(int i = 1;i<=m2;i++){
		cin>>b[i].be>>b[i].en;
	}
	sort(a+1,a+1+m1,pan);
	sort(b+1,b+1+m2,pan);

	for(int i = 0;i<=n;i++){
		maxn=max(maxn,find(m1,i,a)+find(m2,n-i,b));
	}
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
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
