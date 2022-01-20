#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
inline int read() {
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*y;
}

int n,m1,m2;

struct node {
	int s,t;
	bool operator <(const node& temp)const {
		if(s<temp.s) return 1;
		else if(s==temp.s&&t<temp.t) return 1;
		return 0;
	}
};
node a[100005],b[100005];
int c[100000001];
int maxx1,maxx2,x,t1,t2;
int last[100005];
int f1(int x) {
	if(x==0) return 0;
	if(x>=t1) return m1;
	int ans=1;
	memset(last,0,sizeof(last));
	last[1]=a[1].t;
	for(int i=2; i<=m1; i++) {
		for(int j=1; j<=x; j++) {
			if(last[j]>a[i].t) continue;
			if(!last[j] || last[j]<=a[i].s) {
				ans++,last[j]=a[i].t;
				break;
			}
		}
	}
	return ans;
}
int f2(int x) {
	if(x==0) return 0;
	if(x>=t2) return m2;
	int ans=1;
	memset(last,0,sizeof(last));
	last[1]=b[1].t;
	for(int i=2; i<=m2; i++) {
		for(int j=1; j<=x; j++) {
			if(last[j]>b[i].t) continue;
			if(!last[j] || last[j]<=b[i].s) {
				ans++,last[j]=b[i].t;
				break;
			}
		}
	}
	return ans;
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	maxx1=maxx2=-1;
	for(int i=1; i<=m1; i++) {
		a[i].s=read(),a[i].t=read();
		maxx1=max(maxx1,a[i].t);
	}
	for(int i=1; i<=m2; i++) {
		b[i].s=read(),b[i].t=read();
		maxx2=max(maxx2,b[i].t);
	}
	sort(a+1,a+m1+1);
	sort(b+1,b+m2+1);
	memset(c,0,sizeof(c));
	for(int i=1; i<=m1; i++) {
		c[a[i].s]++,c[a[i].t+1]--;
	}
	x=c[0],t1=0;
	for(int i=1; i<=maxx1; i++) {
		x=x+c[i];
		t1=max(t1,x);
	}
	memset(c,0,sizeof(c));
	for(int i=1; i<=m2; i++) {
		c[b[i].s]++,c[b[i].t+1]--;
	}
	x=c[0],t2=x;
	for(int i=1; i<=maxx2; i++) {
		x=x+c[i];
		t2=max(t2,x);
	}
	if(t1>n&&t2>n) {

		int ans=0;
		for(int i=0; i<=n; i++) {
			ans=max(ans,f1(i)+f2(n-i));
			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	} else {
		int temp1;
		temp1=min(t1,n);
		int ans1,ans2;
		ans1=f1(temp1)+f2(n-temp1);
		temp1=min(t2,n);
		ans2=f1(n-temp1)+f2(temp1);
		cout<<max(ans1,ans2);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

