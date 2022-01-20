#include<bits/stdc++.h>
using namespace std;
struct flight {
	int start,end;
} fn[100000+20],fw[100000+20];

bool cmp(flight a,flight b) {
	return a.start<b.start;
}
bool cmpint(int a,int b) {
	return a>b;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);

	int n,m1,m2,Ans=0;
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>fn[i].start>>fn[i].end;
	}
	for(int i=1; i<=m2; i++) {
		cin>>fw[i].start>>fw[i].end;
	}
	sort(fn+1,fn+m1+1,cmp);
	sort(fw+1,fw+m2+1,cmp);
	int cnt1=m1,cnt2=m2;
	for(int i=0; i<=n; i++) {
		int tknum[100000+20]= {0};
		for(int j=1; j<=m1; j++) {
			for(int k=fn[j].start; k<=fn[j].end; k++) {
				tknum[k]++;
			}
		}
		sort(tknum,tknum+m1+1,cmpint);
		cnt2-=tknum[0]-guonei;
		int tknumm[100000+20]= {0};
		for(int j=1; j<=m2; j++) {
			for(int k=fw[j].start; k<=fw[j].end; k++) {
				tknumm[k]++;
			}
		}
		sort(tknumm,tknumm+m2+1,cmpint);
		cnt2-=tknumm[0]-guowai;
		Ans=max(Ans,cnt1+cnt2);
	}
	cout<<Ans;
	return 0;
}
