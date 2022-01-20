#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int M =1e5+100;
int n,mm1,mm2;

struct note  {
	int l,r;
}fgt1[M],fgt2[M];

bool cmp(note a,note b) {
	return a.l<b.l;
}

int ans1[M],ans2[M];
int ans;
int cnt,now,qr[M];
int ql[M];

inline void input() {
	scanf("%d%d%d",&n,&mm1,&mm2);
	for (int i=1;i<=mm1;i++) {
		scanf("%d%d",&fgt1[i].l,&fgt1[i].r);
	}
	for (int i=1;i<=mm2;i++) {
		scanf("%d%d",&fgt2[i].l,&fgt2[i].r);
	}

	sort(fgt1+1,fgt1+mm1+1,cmp);
	sort(fgt2+1,fgt2+mm2+1,cmp);

	for (int i=mm1;i<=n;i++) ans1[i]=mm1;
	for (int i=mm2;i<=n;i++) ans2[i]=mm2;
}

inline void dowork() {
	memset(qr,0x3f,sizeof(qr));
	for (int i=1;i<=n;i++) {
		cnt=0;
		now=0;
		ans=0;
		
		for (int j=1;j<=mm1;j++) {//all plane
			now=fgt1[j].l;
			for (int ta=cnt;ta>=1;ta--) {
				if (now>=qr[ta]) {
					for (int xx=1;xx<=cnt-ta;xx++) qr[xx]=qr[xx+ta];
					for (int xx=cnt-ta+1;xx<=cnt;xx++) qr[xx]=0x3f3f3f3f;
					cnt-=ta;
				}
			}
			if (cnt>=i) continue;
			qr[cnt+1]=fgt1[j].r;
			cnt++;
			sort(qr+1,qr+cnt+1);
			ans++;
		}
		ans1[i]=ans;
		if (ans==mm1) {
			for (int ac=i;ac<=n;ac++) ans1[i]=mm1;
			break;
		}
		if (i>=mm1) break;
	}
	
	memset(qr,0x3f,sizeof(qr));
	for (int i=1;i<=n;i++) {
		cnt=0;
		now=0;
		ans=0;
		
		for (int j=1;j<=mm2;j++) {//all plane
			now=fgt2[j].l;
			for (int ta=cnt;ta>=1;ta--) {
				if (now>=qr[ta]) {
					for (int xx=1;xx<=cnt-ta;xx++) qr[xx]=qr[xx+ta];
					for (int xx=cnt-ta+1;xx<=cnt;xx++) qr[xx]=0x3f3f3f3f;
					cnt-=ta;
				}
			}
			if (cnt>=i) continue;
			qr[cnt+1]=fgt2[j].r;
			cnt++;
			sort(qr+1,qr+cnt+1);
			ans++;
		}
		ans2[i]=ans;
		if (ans==mm2) {
			for (int ac=i;ac<=n;ac++) ans2[i]=mm2;
			break;
		}
		if (i>=mm2) break;
	}
}

inline void output() {
	ans=-1;
	
	for (int i=0;i<=n;i++) {
		ans=max(ans,ans1[i]+ans2[n-i]);
	}
	
	printf("%d",ans);
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	input();
	dowork();
	output();
	return 0;	
}






