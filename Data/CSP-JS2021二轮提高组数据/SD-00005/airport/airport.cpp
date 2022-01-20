#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rop(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define por(i,a,b) for(int i=(a);i>(b);i--)
using namespace std;
typedef long long ll;
namespace AnShu{

inline int read(){
	int W=0,F=1;
	char C=getchar();
	while((C<'0'||C>'9')&&C!='-') C=getchar();
	if(C=='-') F=-1,C=getchar();
	while(C>='0'&&C<='9') W=W*10+C-'0',C=getchar();
	return W*F;
}

int n,ma,mb,t,ans,fa[100005],fb[100005];
priority_queue<int,vector<int>,greater<int> > q;

struct node{
	int l,r;
}a[100005],b[100005];

bool cmp(node a,node b){
	if(a.l!=b.l) return a.l<b.l;
	return a.r<b.r;
}

void Main(){
	n=read(),ma=read(),mb=read();
	rep(i,1,ma) a[i].l=read(),a[i].r=read();
	rep(i,1,mb) b[i].l=read(),b[i].r=read(); 
	sort(a+1,a+ma+1,cmp);
	sort(b+1,b+mb+1,cmp);
	rep(k,0,n){
		while(!q.empty()) q.pop();
		t=0;
		rep(i,1,max(n,ma)){
			if(t<k){
				t++,fa[k]++;
				q.push(a[i].r);
				continue;
			}
			if((!q.empty())&&q.top()<a[i].l){
				q.pop();
				fa[k]++;
				q.push(a[i].r);
			}
		}
	}
	rep(k,0,n){
		while(!q.empty()) q.pop();
		t=0;
		rep(i,1,max(n,mb)){
			if(t<k){
				t++,fb[k]++;
				q.push(b[i].r);
				continue;
			}
			if((!q.empty())&&q.top()<b[i].l){
				q.pop();
				fb[k]++;
				q.push(b[i].r);
			}
		}
	}
	rep(i,1,n) ans=max(ans,fa[i]+fb[n-i]);
	printf("%d",ans);
}

}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	AnShu::Main();
	return 0;
}

