#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 100000;
int n,m1,m2,f1[N],f2[N];
int head1=1,head2=1;
struct ti {
	int nxt,pre;
	int x,y;
}a[N],b[N];
bool cmp (ti aa,ti ab){
	return aa.x<ab.x;
}
int main ( ) {
	freopen ("airport.in","r",stdin);
	freopen ("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	for (int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for (int i=1;i<=m1;i++){
		a[i].nxt=i==m1?-1:i+1;
		a[i].pre=i==1?-1:i-1;
	}
	for (int i=1;i<=m2;i++){
		b[i].nxt=i==m2?-1:i+1;
		b[i].pre=i==1?-1:i-1;
	}
	f1[0]=f2[0]=0;
	int max1=a[1].y,max2=b[1].y;
	for (int len=1;len<=n;len++){
		f1[len]=f1[len-1]+1,f2[len]=f2[len-1]+1;
		for (int i=head1;~i;i=a[i].nxt){
			if (i==head1) continue;
			if (a[i].x>max1){
				if (~a[i].pre)
					a[a[i].pre].nxt=a[i].nxt;
				if (~a[i].nxt)
					a[a[i].nxt].pre=a[i].pre;
				f1[len]++;
				max1=a[i].y;
			}
		}
		for (int i=head2;~i;i=b[i].nxt){
			if (i==head2) continue;
			if (b[i].x>max2){
				if (~b[i].pre)
					b[b[i].pre].nxt=b[i].nxt;
				if (~b[i].nxt)
					b[b[i].nxt].pre=b[i].pre;
				f2[len]++;
				max2=b[i].y;
			}
		}
		head1=a[head1].nxt,head2=b[head2].nxt;
		max1=a[head1].y,max2=b[head2].y;
	}
	int ans=0;
	for (int i=0;i<=n;i++){
		ans=max(ans,f1[i]+f2[n-i]);
	}
	printf("%d\n",ans);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
