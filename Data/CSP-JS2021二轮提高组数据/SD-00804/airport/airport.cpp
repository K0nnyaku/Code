#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
struct Plane {
	ll rh,lt;
}in[100005],out[100005];
bool operator < (Plane a,Plane b) {
	return a.rh<b.rh;
}
queue <ll> q;
ll n,m1,m2,l,r,ans,h,t;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++) in[i].rh=read(),in[i].lt=read();
	for(int i=1;i<=m2;i++) out[i].rh=read(),out[i].lt=read();
	sort(in+1,in+m1+1);
	sort(out+1,out+m2+1);
	for(int i=0;i<=n;i++) {
		ll sum1=0,sum2=0;
		while(!q.empty()) q.pop();
		for(int j=1;j<=m1;j++) {
			while(!q.empty()&&q.front()<=in[j].rh) q.pop();
			if(q.size()==i) continue;
			else {
				sum1++;
				q.push(in[j].lt);
			}
		}
		while(!q.empty()) q.pop();
		for(int j=1;j<=m2;j++) {
			while(!q.empty()&&q.front()<=out[j].rh) q.pop();
			if(q.size()==n-i) continue;
			else {
				sum2++;
				q.push(out[j].lt);
			}
		}
		ans=max(ans,sum1+sum2);
	}
	cout<<ans<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
