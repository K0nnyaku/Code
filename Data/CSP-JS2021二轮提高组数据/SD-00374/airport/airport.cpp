#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
inline int read() {
	int f=0,res=0; char ch;
	while(ch<'0'||ch>'9') {if(ch=='-')f=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){res=(res<<1)+(res<<3)+(ch^48);ch=getchar();}
	return f?-res:res; 
}
const int maxn=1e5+10;
struct K{
	int a,b;
}k1[maxn],k2[maxn];
int n,m1,m2,ans,maxx;
priority_queue<int> que;
bool cmp(const K &x,const K &y) {
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(); m1=read(); m2=read();
	for(int i=1;i<=m1;i++) {k1[i].a=read(); k1[i].b=read();}
	for(int i=1;i<=m2;i++) {k2[i].a=read(); k2[i].b=read();}
	sort(k1+1,k1+m1+1,cmp); sort(k2+1,k2+m2+1,cmp);
	for(int i=1;i<=n;i++) {
		int tot=0; ans=0;
		for(int j=1;j<=m1;j++) {
			while(tot>0&&-1*que.top()<=k1[j].a) {--tot; que.pop();}
			if(tot<i) {que.push(-k1[j].b); ++tot; ans++;}
		} while(!que.empty()) que.pop(); tot=0;
		for(int j=1;j<=m2;j++) {
			while(tot>0&&-1*que.top()<=k2[j].a) {--tot; que.pop();}
			if(tot<n-i) {que.push(-k2[j].b); ++tot; ans++;}
		} while(!que.empty()) que.pop();
		maxx=max(ans,maxx); 
	} cout<<maxx<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
