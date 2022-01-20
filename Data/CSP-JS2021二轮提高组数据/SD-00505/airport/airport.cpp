#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100005; 
int t1[100000008],t2[100000008];
long long n,m1,m2,d1[N],d2[N],f1[N],f2[N];
struct gn{
	long long x,y;
}a[N];
struct gw{
	long long x,y;
}b[N];
bool cmp1(gn a,gn b){
	return a.x<b.x;
}
bool cmp2(gw x,gw y){
	return x.x<y.x;
}
priority_queue<long long>Q;
priority_queue<long long>A;
priority_queue<long long>B;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(long long i=1;i<=m1;i++){
		cin>>a[i].x>>a[i].y;
		A.push(-a[i].x);
		A.push(-a[i].y);
	}
	for(long long i=1;i<=m2;i++){
		cin>>b[i].x>>b[i].y;
		B.push(-b[i].x);
		B.push(-b[i].y);
	}
	for(long long i=1;i<=max(m1,m2);i++){
		Q.push(-i);
	}
	sort(a+1,a+m1+1,cmp1);
	sort(b+1,b+m2+1,cmp2);
	for(long long i=1;i<=m1;i++)t1[a[i].y]=i;
	for(long long i=1;i<=m2;i++)t2[b[i].y]=i;
	long long h=1;
	while(!A.empty()){
		long long i=-A.top();
		A.pop();
		if(i==a[h].x){
			d1[h]=-Q.top();
			Q.pop();
			f1[d1[h]]++;
			h++;
		}
		if(t1[i]){
			Q.push(-d1[t1[i]]);
		}
	}
	for(long long i=2;i<=n;i++){
		f1[i]=f1[i-1]+f1[i];
	}
	h=1;
	while(!B.empty()){
		long long i=-B.top();
		B.pop();
		if(i==b[h].x){
			d2[h]=-Q.top();
			Q.pop();
			f2[d2[h]]++;
			h++;
		}
		if(t2[i]){
			Q.push(-d2[t2[i]]);
		}
	}
	for(long long i=2;i<=n;i++){
		f2[i]=f2[i-1]+f2[i];
	}
	long long maxn=-1231231;
	for(long long i=1;i<=n;i++){
		maxn=max(f1[i]+f2[n-i],maxn);
	}
	cout<<maxn<<endl;
	fclose(stdin);
	fclose(stdout);
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




















