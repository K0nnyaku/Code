#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>
#include<set>

#define INF 0x3f3f3f3f
#define ll long long
#define maxn 100005
#define pii pair<int,int>

using namespace std;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int n,m1,m2;

struct Node{
	int a,b;
}a[maxn],b[maxn];

int ca[maxn],cb[maxn],fa[maxn],fb[maxn],ans;

inline bool cmp(Node a,Node b)
{
	return a.a<b.a;
}

priority_queue<pii,vector<pii>,greater<pii> >q; 
set<int>e;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read(); 
	for(int i=1;i<=m1;i++){
		a[i].a=read(),a[i].b=read();
	}
	for(int i=1;i<=m2;i++){
		b[i].a=read(),b[i].b=read();
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=n;i++) e.insert(i);
	for(int i=1;i<=m1;i++){
		while(!q.empty()){
			if(q.top().first>a[i].a) break;
			int t=q.top().second;
			q.pop();
			e.insert(ca[t]); 
		}
		if(!e.empty()){
			ca[i]=*(e.begin());
			e.erase(ca[i]);
			q.push(make_pair(a[i].b,i)); 
		}
	}
	e.clear(); 
	while(!q.empty()) q.pop();
	
//	for(int i=1;i<=m1;i++) cout<<ca[i]<<endl;
	
	for(int i=1;i<=n;i++) e.insert(i);
	for(int i=1;i<=m2;i++){
		while(!q.empty()){
			if(q.top().first>b[i].a) break; 
			int t=q.top().second;
			q.pop();
			e.insert(cb[t]);
		}
		if(!e.empty()){
			cb[i]=*(e.begin());
			e.erase(cb[i]);
			q.push(make_pair(b[i].b,i));
		}
	}
	
//	for(int i=1;i<=m2;i++) cout<<cb[i]<<endl; 
	
	for(int i=1;i<=m1;i++) if(ca[i]) fa[ca[i]]++;
	for(int i=2;i<=n;i++) fa[i]+=fa[i-1];
	for(int i=1;i<=m2;i++) if(cb[i]) fb[cb[i]]++;
	for(int i=2;i<=n;i++) fb[i]+=fb[i-1];
	
	for(int i=0;i<=n;i++){
		ans=max(ans,fa[i]+fb[n-i]);
//		cout<<i<<" "<<fa[i]+fb[n-i]<<endl; 
	}
	cout<<ans<<endl;
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
