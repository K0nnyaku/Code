#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long 
#define PII pair<int,int>
int n,m,na,nb,ma,mb,ans;
struct fl{
	int arr,lea;
	bool s;
}a[110000],b[110000];
bool cmp(fl a,fl b){
	return a.arr<b.arr;
}
int f(int na,int nb){
	int cnt=0;
	priority_queue<int> qa,qb;
	for(int i=1;i<=ma;++i){
		while(!qa.empty() && -qa.top()<=a[i].arr){
			qa.pop();
		}
		if(qa.size()<na){
			qa.push(-a[i].lea);
			++cnt;
		}
	}
	for(int i=1;i<=mb;++i){
		while(!qb.empty() && -qb.top()<=b[i].arr)
			qb.pop();
		if(qb.size()<nb){
			qb.push(-b[i].lea);
			++cnt;
		}
	}
	return cnt;
} 
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>ma>>mb;
	m=ma+mb;
	if(n>=m){
		cout<<m<<endl;
		return 0; 
	} 
	for(int i=1;i<=ma;++i){
		cin>>a[i].arr>>a[i].lea;
		a[i].s=0;
	}
	for(int i=1;i<=mb;++i){
		cin>>b[i].arr>>b[i].lea;
		b[i].s=1;
	}
	sort(1+a,1+a+ma,cmp);
	sort(1+b,1+b+mb,cmp);
	int qwq=0,minn=0;
	if(ma>mb)
		qwq=1,minn=mb;
	else
		minn=ma;
	if(minn>n)
		minn=n;
//	cout<<qwq<<" "<<minn<<endl;
	for(int i=0;i<=minn;++i){
		int q=0;
		if(qwq)
			q=f(n-i,i);
		else
			q=f(i,n-i);
		if(ans<q)
			ans=q;
	}
	cout<<ans<<endl;
	return 0;
}
//CSP2021 RP=INF
