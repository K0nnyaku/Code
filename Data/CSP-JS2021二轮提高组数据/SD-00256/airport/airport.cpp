/*
		
    	qwq
    	
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#define il inline
#define re register
#define ll long long
const int N=100005,M=1e8+5;
int n,m1,m2,ans[2][N],tot=0,ioi;
il int R () {
	re int s=0,f=1;re char ch=getchar();
	while (!isdigit(ch)) f=(ch=='-')?-1:1,ch=getchar();
	while (isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}
struct node {
	int x,y;
	bool operator <(const node &o) const {return y>o.y;}	
}a[3][N];
std::priority_queue<node> q;
il bool cmp (node x,node y) {return x.x<y.x;}
int main () {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=R(),m1=R(),m2=R();
	for (int i=1;i<=m1;i++) a[1][i].x=R(),a[1][i].y=R();
	for (int i=1;i<=m2;i++) a[2][i].x=R(),a[2][i].y=R();
	std::sort(a[1]+1,a[1]+m1+1,cmp);
	std::sort(a[2]+1,a[2]+m2+1,cmp);
	for (int siz1=0;siz1<=n;siz1++) {
		int sum1=0,flag=0;
		if (!ans[1][siz1]) {
			while (!q.empty()) q.pop();
			for (int i=1;i<=m1;i++) {
				int x=a[1][i].x,y=a[1][i].y;
				while (!q.empty()&&q.top().y<=x) q.pop();
				if (q.size()<siz1) sum1++,q.push(a[1][i]);
			}
			ans[1][siz1]=sum1;
			if (sum1==siz1&&sum1!=0) {
				flag=1;
				for (int i=siz1;i<=n;i++) ans[1][i]=sum1;
			}
		}
		if (flag) break;
	}
	for (int siz2=0;siz2<=n;siz2++) {
		int sum2=0,flag=0;
 		if (!ans[2][siz2]) {
			while (!q.empty()) q.pop();
			for (int i=1;i<=m2;i++) {
				int x=a[2][i].x,y=a[2][i].y;
				while (!q.empty()&&q.top().y<=x) q.pop();
				if (q.size()<siz2) sum2++,q.push(a[2][i]);
			}
			ans[2][siz2]=sum2;
			if (sum2==siz2&&sum2!=0) {
				flag=1;
				for (int i=siz2;i<=n;i++) ans[2][i]=sum2;
			}
		}
		if (flag) break;
	}
	int total=0;
	for (int i=0;i<=n;i++) total=std::max(total,ans[1][i]+ans[2][n-i]);
	printf("%d",total);
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
*/
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
