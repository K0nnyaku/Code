#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100006;
int n, m1, m2, c1, c2, ans1, ans2, ans, d, qwq, c[N];
struct E { int l, r; } a[N], b[N], q[N];
bool operator<(E a,E b) { return a.l!=b.l? a.l<b.l:a.r<b.r; }
inline int r_() {
	int a=0, f=0; char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);a=(a<<1)+(a<<3)+(c^48),c=getchar());
	return a;
}
inline int Max(int x,int y) { return x>y? x:y; }
inline int Min(int x,int y) { return x<y? x:y; }
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=r_(), m1=r_(), m2=r_();
	for(int i=1;i<=m1;++i) a[i].l=r_(), a[i].r=r_();
	for(int i=1;i<=m2;++i) b[i].l=r_(), b[i].r=r_();
	sort(a+1,a+m1+1), sort(b+1,b+m2+1);
	for(int i=0;i<=n;++i) {
		c1=c2=1, ans1=ans2=0;
		for(int j=1;j<=m1;++j) {
			if(!i) break;
			int f=0;
			for(int k=1;k<=c1;++k) if(a[j].l>c[k]) { ++ans1, c[k]=a[j].r, f=1; break; }
			if(!f&&c1<i) c[++c1]=a[j].r, ++ans1;
		}
		memset(c,0,sizeof(c));
		for(int j=1;j<=m2;++j) {
			if(!(n-i)) break;
			int f=0;
			for(int k=1;k<=c2;++k) if(b[j].l>c[k]) { ++ans2, c[k]=b[j].r, f=1; break; }
			if(!f&&c2<(n-i)) c[++c2]=b[j].r, ++ans2;
		}
		memset(c,0,sizeof(c));
		ans=Max(ans,ans1+ans2);
	}
	printf("%d\n",ans);
}
